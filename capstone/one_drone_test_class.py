#목표1 : 드론 측위 
#목표2 : 드론 움직이기


import multiprocessing.process
import time
import threading
import multiprocessing
import queue


import cflib.crtp
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.log import LogConfig
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie
from cflib.crazyflie.syncLogger import SyncLogger


import logging
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation
import tkinter as tk

logging.basicConfig(level=logging.ERROR)

# URI to the Crazyflie to connect to
uri = 'radio://0/125/2M/E7E7E7E7A2'

sequence=[0,0,0]
a=[]
flytime = 20
height = 0.5
position = [4,4]

def plot(data_queue):    
    fig = plt.figure()
    ax = fig.add_subplot(121, projection='3d')
    ax2 = fig.add_subplot(122, projection='3d')
    drone_trajectory = []
    def update_plot(frame):
        ax.clear()
        ax2.clear()
        # 데이터 큐에서 샘플을 받아와 시각화
        try:
            sample = data_queue.get_nowait()
        except queue.Empty:
            pass
        else:
            drone_trajectory.append(sample)            
        x_values = [pos[0] for pos in drone_trajectory]
        y_values = [pos[1] for pos in drone_trajectory]
        z_values = [0] 
        x = x_values[-1]
        y = y_values[-1]
        z = z_values[-1]   
        ax.plot(x_values, y_values, z_values, color='b')
        ax2.scatter(x,y,z, marker ='x')  

        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.set_xlim(-10, 10)  # x 축의 범위 설정
        ax.set_ylim(-10, 10)  # y 축의 범위 설정
        ax.set_zlim(-10, 10)
        ax.set_title('Real_Time 3D Vis. of  trajectory')

        ax2.set_xlabel('X')
        ax2.set_ylabel('Y')
        ax2.set_zlabel('Z')
        ax2.set_xlim(-10, 10)  # x 축의 범위 설정
        ax2.set_ylim(-10, 10)  # y 축의 범위 설정
        ax2.set_zlim(-10, 10)
        ax2.set_title('Real-time 3D Vis. of pos')

    ani = FuncAnimation(fig, update_plot, interval=200, cache_frame_data=False)
    plt.show()
        
class TOC:
    def __init__(self, cf):
        self._cf = cf 
        #로그 구성(LogConfig) 객체를 생성
        #이름은 'Position'으로 설정되어 있으며, 데이터 수집 주기는 밀리초 단위로 200ms
        self.log_conf = LogConfig(name='Position', period_in_ms=200)
        #add_variable 메서드를 사용하여 센서에서 수집할 변수를 지정
        self.log_conf.add_variable('ranging.distance0', 'float')
        self.log_conf.add_variable('ranging.distance1', 'float')
        self.log_conf.add_variable('ranging.distance2', 'float')
        self.log_conf.add_variable('ranging.distance3', 'float')
        self.log_conf.add_variable('ranging.distance4', 'float')
        #Crazyflie 객체의 로그 관리자를 나타냅니다. 이를 사용하여 센서 데이터 수집을 제어
        #메서드를 사용하여 로그 구성을 추가
        self._cf.log.add_config(self.log_conf)
        #add_callback() 메서드를 사용하여 데이터 수신 콜백에 self.position_callback 함수를 추가
        #센서 데이터가 수신될 때마다 이 함수가 자동으로 호출되어 데이터를 처리
        self.log_conf.data_received_cb.add_callback(self.position_callback)
        #Crazyflie에게 해당 로그 구성을 시작하도록 지시
        self.log_conf.start()
    # 센서로부터 수신된 데이터에서 각 거리 센서의 측정값을 추출하여 클래스의 속성으로 저장
    def position_callback(self, timestamp, data, logconf):
        self.d0=data['ranging.distance0']
        self.d1=data['ranging.distance1']
        self.d2=data['ranging.distance2']
        self.d3=data['ranging.distance3']
        self.d4=data['ranging.distance4']

def wait_for_position_estimator(scf):
    print('Waiting for estimator to find position...')

    log_config = LogConfig(name='Kalman Variance', period_in_ms=100)
    log_config.add_variable('kalman.varPX', 'float')
    log_config.add_variable('kalman.varPY', 'float')
    log_config.add_variable('kalman.varPZ', 'float')

    var_y_history = [1000] * 10
    var_x_history = [1000] * 10
    var_z_history = [1000] * 10

    threshold = 0.001

    with SyncLogger(scf, log_config) as logger:
        for log_entry in logger:
            data = log_entry[1]

            var_x_history.append(data['kalman.varPX'])
            var_x_history.pop(0)
            var_y_history.append(data['kalman.varPY'])
            var_y_history.pop(0)
            var_z_history.append(data['kalman.varPZ'])
            var_z_history.pop(0)
            
            min_x = min(var_x_history)
            max_x = max(var_x_history)
            min_y = min(var_y_history)
            max_y = max(var_y_history)
            min_z = min(var_z_history)
            max_z = max(var_z_history)

            # print("{} {} {}".
            #       format(max_x - min_x, max_y - min_y, max_z - min_z))

            if (max_x - min_x) < threshold and (
                    max_y - min_y) < threshold and (
                    max_z - min_z) < threshold:
                break


def reset_estimator(scf):
    global data
    cf = scf.cf
    cf.param.set_value('kalman.resetEstimation', '1')
    time.sleep(0.1)
    cf.param.set_value('kalman.resetEstimation', '0')
    data = TOC(cf)
    
    time.sleep(0.1)
    wait_for_position_estimator(cf)

def take_off(cf, position, tot):
    take_off_time = tot
    sleep_time = 0.1
    steps = int(take_off_time / sleep_time)
    vz = position / take_off_time

   #print(vz)

    for i in range(steps):
        cf.commander.send_velocity_world_setpoint(0, 0, vz, 0)
        time.sleep(sleep_time)

def land(cf, position, lt):
    landing_time = lt
    sleep_time = 0.1
    steps = int(landing_time / sleep_time)
    vz = -position / landing_time

    #print(vz)

    for i in range(steps):
        cf.commander.send_velocity_world_setpoint(0, 0, vz, 0)
        time.sleep(sleep_time)
        

    cf.commander.send_setpoint(0,0,0,0)
    # Make sure that the last packet leaves before the link is closed
    # since the message queue is not flushed before closing
    time.sleep(0.1)

def run_sequence(scf, sequence, data_queue):
    global a, height, flytime, delay, r
    cf = scf.cf
    end_time = time.time() + flytime
    cf.param.set_value('flightmode.posSet', '1')
    
    def thread_run():
        print('====', time.ctime(), '====')
        for i in range(1,20):
            print('Thread running -', i)

        threading.Timer(1, thread_run).start()
    thread_run()
    def TDOA(d):
        d21 = d[1]-d[0]
        d31 = d[2]-d[0]
        d41 = d[3]-d[0]
        d51 = d[4]-d[0]
        return d21, d31        
    take_off(cf, height, 3.0)
    while time.time() < end_time:  
        cf.commander.send_hover_setpoint(0, 0, 0, height)
        d = [data.d0,data.d1,data.d2,data.d3,data.d4]        
        data_queue.put(TDOA(d))
        time.sleep(0.1)


    land(cf, height, 3.0)				
    time.sleep(0.1)

class trans_self:
    def __init__(self):
        self.xyz = 0

    def trans_var(self):
        global data
        self.xyz = [[data.x, data.y, data.z]]

if __name__ == '__main__':
    cflib.crtp.init_drivers(enable_debug_driver=False)

    # 드론과의 통신을 관리
    with SyncCrazyflie(uri, cf=Crazyflie(rw_cache='./cache')) as scf:
        reset_estimator(scf)
        input("press enter to start the flight")
        '''
        t1 = threading.Thread(target=run_sequence, args=(scf, sequence, ))
        t1.start()
        t2 = threading.Thread(target=plot)
        t2.start()
        
        t1.join()
        t2.join()   
        '''        
        data_queue = multiprocessing.Queue()
        p1 = multiprocessing.Process(target=run_sequence, args=(scf, sequence, data_queue, ))
        p1.start()
        p2 = multiprocessing.Process(target=plot, args=(data_queue,))
        p2.start()          
        p1.join()
        p2.join()
        
        ddd=pd.DataFrame(a)
        ddd.to_csv('var.csv')
        exit(0)
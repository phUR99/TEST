import random

import time
import threading


import cflib.crtp
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.log import LogConfig
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie
from cflib.crazyflie.syncLogger import SyncLogger
import logging
import numpy as np
import pandas as pd

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import queue
logging.basicConfig(level=logging.ERROR)

# URI to the Crazyflie to connect to
uri = 'radio://0/125/2M/E7E7E7E7A2'

#sequence=[0,0,0]
a=[]
flytime = 20
height = 0.3
position = np.array([
    [0, 0],
    [7.14, 3.38],      
    [10.25, 1.94],            
    [0.8, 3.76],
    [0 ,0],
    [0, 0]            
])
data_queue = queue.Queue()

def plot():        
    global data_queue
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')    
    drone_trajectory = []

    def update_plot(frame):
        ax.clear()        
        # 데이터 큐에서 샘플을 받아와 시각화
        if data_queue.empty():
            pass
        else :
            sample = data_queue.get()
            sample = list(sample.T)                       
            drone_trajectory.append(sample)            
            x_values = [pos[0] for pos in drone_trajectory]
            y_values = [pos[1] for pos in drone_trajectory]
            z_values = [0] 
            x = x_values[-1]
            y = y_values[-1]
            z = z_values[-1]   
            ax.plot(x_values, y_values, z_values, color='b')
            ax.plot(x_values[-1], y_values[-1], z_values[-1], marker = 'x', markersize = 10)             
            ax.set_xlabel('X')
            ax.set_ylabel('Y')
            ax.set_zlabel('Z')
            ax.set_title('Real_Time trajectory')

    ani = FuncAnimation(fig, update_plot, interval=100, cache_frame_data=False)
    plt.show()
class TOC:
    def __init__(self, cf):
        self._cf = cf 
        self.log_conf = LogConfig(name='Position', period_in_ms=200)
        self.log_conf.add_variable('ranging.distance0', 'float')
        self.log_conf.add_variable('ranging.distance1', 'float')
        self.log_conf.add_variable('ranging.distance2', 'float')
        self.log_conf.add_variable('ranging.distance3', 'float')
        self.log_conf.add_variable('ranging.distance4', 'float')
        self.log_conf.add_variable('ranging.distance5', 'float')

        self._cf.log.add_config(self.log_conf)
        self.log_conf.data_received_cb.add_callback(self.position_callback)
        self.log_conf.start()

    def position_callback(self, timestamp, data, logconf):
        self.d0=data['ranging.distance0']
        self.d1=data['ranging.distance1']
        self.d2=data['ranging.distance2']
        self.d3=data['ranging.distance3']
        self.d4=data['ranging.distance4']
        self.d5=data['ranging.distance5']

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

def sequence(cf, height, t):
    global data_queue
    end_time = time.time() + flytime
    def TDOA(R):
        R = np.array(R)
        R = np.square(R)        
        R = R[1:3]                
        K = np.sum(np.square(position[1:3, :]), axis=1)                
        H = position[1:3, :]
        pH = np.linalg.pinv(H)
        b = (K -R) /2
        xhat = pH @ b        
        return xhat
    
    print("sequence start...")    

    take_off(cf, height, t)
    while time.time() < end_time:  
        cf.commander.send_hover_setpoint(0, 0, 0, height)
        d = [data.d0, data.d1, data.d2, data.d3, data.d4, data.d5]        
        r = TDOA(d)
        print(r)
        data_queue.put(r)
        time.sleep(0.1)
    land(cf, height, t)
    time.sleep(0.1)
    print("sequence end...")

def run_sequence(scf):
    global a, height
    cf = scf.cf    
    cf.param.set_value('flightmode.posSet', '1')
    threading.Thread(target=sequence, args=(cf, height, 3.0)).start()    
    plot()
    
    

if __name__ == '__main__':
    cflib.crtp.init_drivers(enable_debug_driver=False)

    with SyncCrazyflie(uri, cf=Crazyflie(rw_cache='./cache')) as scf:
        reset_estimator(scf)
        input("press enter to start the flight")
        run_sequence(scf)
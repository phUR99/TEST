
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

logging.basicConfig(level=logging.ERROR)

# URI to the Crazyflie to connect to
uri_target = 'radio://0/125/2M/E7E7E7E7A2'
uri_anchor = 'radio://0/90/2M/E7E7E7E7CC'

sequence=[0,0,0]
a=[]
flytime = 20
height = 0.3
position = [4,4]

class TOC:
    def __init__(self, cf):
        self._cf = cf 
        self.log_conf = LogConfig(name='Position', period_in_ms=200)        
        #self.log_conf.add_variable('ranging.distance1', 'float')
        #self.log_conf.add_variable('ranging.distance2', 'float')
        #self.log_conf.add_variable('ranging.distance3', 'float')        
        self.log_conf.add_variable('tdoa3.hmDist', 'float')
        #self.log_conf.add_variable('tdoa3.hmSeqOk', 'float')
        #self.log_conf.add_variable('tdoa3.hmEst', 'float')
        #self.log_conf.add_variable('radio.rssi', 'uint8_t')
        #self.log_conf.add_variable('radio.numRxBc', 'uint16_t')
        #self.log_conf.add_variable('radio.numRxUc', 'uint16_t')
        self._cf.log.add_config(self.log_conf)
        
        self.log_conf.data_received_cb.add_callback(self.position_callback)        
        self.log_conf.start()

    def position_callback(self, timestamp, data, logconf):        
        #self.d1=data['ranging.distance1']
        #self.d2=data['ranging.distance2']
        #self.d3=data['ranging.distance3']        
        self.d4=data['tdoa3.hmDist']
        #self.d5=data['tdoa3.hmSeqOk']
        #self.d6=data['tdoa3.hmEst']
        #self.d7=data['radio.rssi']
        #self.d8=data['radio.numRxBc']
        #self.d9=data['radio.numRxUc']
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

def run_sequence(scf):
    global a, height, flytime, delay
    cf = scf.cf
    end_time = time.time() + flytime
    cf.param.set_value('flightmode.posSet', '1')
    
    #take_off(cf, height, 3.0)
    while time.time() < end_time:  
        #cf.commander.send_hover_setpoint(0, 0, 0, height)
        #d = [data.d1,data.d2,data.d3,data.d4]            
        print('current data : ', data.d4)
        time.sleep(0.1)

    #land(cf, height, 3.0)				
    time.sleep(0.1)


if __name__ == '__main__':
    cflib.crtp.init_drivers(enable_debug_driver=False)
    threads = []

    with SyncCrazyflie(uri_target, cf=Crazyflie(rw_cache='./cache')) as scf_t, SyncCrazyflie(uri_anchor, cf=Crazyflie(rw_cache='./cache')) as scf_a :
        reset_estimator(scf_t)
        reset_estimator(scf_a)

        input("press enter to start the flight")
        scf_t.cf.param.set_value('tdoa3.hmId', 254)
        scf_t.cf.param.set_value('tdoa3.hmAnchLog', 253)
        scf_t.cf.param.set_value('tdoa3.hmTwr', '1')
        scf_t.cf.param.set_value('tdoa3.hmTwrEstPos', '1')
        time.sleep(0.5)
        scf_a.cf.param.set_value('tdoa3.hmId', 253)        
        scf_a.cf.param.set_value('tdoa3.hmAnchLog', 254)
        scf_a.cf.param.set_value('tdoa3.hmTwr', '1') 
        scf_a.cf.param.set_value('tdoa3.hmTwrEstPos', '1')
        time.sleep(0.5)
        print(scf_a.cf.param.get_value(complete_name='tdoa3.hmId'))        
        print(scf_a.cf.param.get_value(complete_name='tdoa3.hmAnchLog'))        
        print(scf_a.cf.param.get_value(complete_name='tdoa3.hmTwr'))
        print(scf_a.cf.param.get_value(complete_name='tdoa3.hmTwrEstPos'))

        print(scf_t.cf.param.get_value(complete_name='tdoa3.hmId'))
        print(scf_t.cf.param.get_value(complete_name='tdoa3.hmAnchLog'))
        print(scf_t.cf.param.get_value(complete_name='tdoa3.hmTwr'))
        print(scf_t.cf.param.get_value(complete_name='tdoa3.hmTwrEstPos'))
        
        t1 = threading.Thread(target=run_sequence, args=(scf_t, ))
        t2 = threading.Thread(target=run_sequence, args=(scf_a, ))
        
        t1.start()
        t2.start()
        threads.append(t1)
        threads.append(t2)
        for thread in threads:
            thread.join()

        scf_a.close_link()
        scf_t.close_link()

    


        
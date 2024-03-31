# -*- coding: utf-8 -*-
#
#     ||          ____  _ __
#  +------+      / __ )(_) /_______________ _____  ___
#  | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
#  +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
#   ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
#
#  Copyright (C) 2016 Bitcraze AB
#
#  Crazyflie Nano Quadcopter Client
#
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA  02110-1301, USA.
"""
Simple example that connects to one crazyflie (check the address at the top
and update it to your crazyflie address) and send a sequence of setpoints,
one every 5 seconds.

This example is intended to work with the Loco Positioning System in TWR TOA
mode. It aims at documenting how to set the Crazyflie in position control mode
and how to send setpoints.
"""
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
uri = 'radio://0/125/2M/E7E7E7E7A2'

sequence=[0,0,0]
a=[]
flytime = 20
height = 0.5
position = [4,4]

class TOC:
    def __init__(self, cf):
        self._cf = cf 
        self.log_conf = LogConfig(name='Position', period_in_ms=200)
        self.log_conf.add_variable('ranging.distance0', 'float')
        self.log_conf.add_variable('ranging.distance1', 'float')
        self.log_conf.add_variable('ranging.distance2', 'float')
        self.log_conf.add_variable('ranging.distance3', 'float')
        self.log_conf.add_variable('ranging.distance4', 'float')

        self._cf.log.add_config(self.log_conf)
        self.log_conf.data_received_cb.add_callback(self.position_callback)
        self.log_conf.start()

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

def run_sequence(scf, sequence):
    global a, height, flytime, delay
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
        return d21, d31, d41, d51

    take_off(cf, height, 3.0)
    while time.time() < end_time:  
        cf.commander.send_hover_setpoint(0, 0, 0, height)
        d = [data.d0,data.d1,data.d2,data.d3,data.d4]
        r1=TDOA(d)
        # print(r1)
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

    with SyncCrazyflie(uri, cf=Crazyflie(rw_cache='./cache')) as scf:
        reset_estimator(scf)
        input("press enter to start the flight")
        run_sequence(scf, sequence)
        ddd=pd.DataFrame(a)
        ddd.to_csv('var.csv')
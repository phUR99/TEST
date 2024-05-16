import multiprocessing
import numpy as np
import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import tkinter as tk

import queue
import threading

import cflib.crtp
from cflib.crtp.crtpstack import CRTPPacket
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.log import LogConfig
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie
from cflib.crazyflie.syncLogger import SyncLogger


import logging
import pandas as pd
import struct


logging.basicConfig(level=logging.ERROR)

def func(pkt):
    
    print(pkt._data)    
    recived_time = time.time()        
    #scf.cf.loc.send_short_lpp_packet(dest_id=255, data=bytes(1))
    send_time = time.time()
    #print((-recived_time + send_time) * light_speed_m_per_s)

light_speed_m_per_s = 299792458 
uri_target = 'radio://0/125/2M/E7E7E7E7A2'
uri_anchor = 'radio://0/90/2M/E7E7E7E7CC'

def sequence(pkt) :    
    port = pkt._port
    #if port != 2 : return
    #if pkt._data[-1] & 0xff != int(b'00010001') : return
    data = pkt._data    
    Channel = pkt._channel
    print('data : '  ,data)
    print('port : '  ,port)
    print('channel : ', Channel)
    time.sleep(0.1)

if __name__ == '__main__':
    cflib.crtp.init_drivers(enable_debug_driver=False)
    
    with SyncCrazyflie(uri_target, cf=Crazyflie(rw_cache='./cache')) as scf_t, SyncCrazyflie(uri_anchor, cf=Crazyflie(rw_cache='./cache')) as scf_a:
                                                                                  
        scf_t.cf.param.set_value('tdoa3.hmId', '254')
        scf_t.cf.param.set_value('tdoa3.hmAnchLog', '253')
        scf_t.cf.param.set_value('tdoa3.hmTwr', '1')
        time.sleep(0.5)
        scf_a.cf.param.set_value('tdoa3.hmId', '253')
        scf_a.cf.param.set_value('tdoa3.hmAnchLog', '254')
        scf_a.cf.param.set_value('tdoa3.hmTwr', '1') 
        time.sleep(0.5)
        
        scf_t.cf.packet_received.add_callback(sequence)
        for i in range(10):
            time.sleep(0.5)
            scf_a.cf.loc.send_short_lpp_packet(dest_id=254, data=b'00010001')

        
  
        
    
            
            
        


        
        
        
            

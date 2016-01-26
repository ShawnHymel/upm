#!/usr/bin/python
# Author: Shawn Hymel
# Copyright (c) 2016 SparkFun Electronics
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

import time
import pyupm_apds9960 as apds9960

# Define gestures
def gestures(g):
    return {
        apds9960.DIR_UP:    'UP',
        apds9960.DIR_DOWN:  'DOWN',
        apds9960.DIR_LEFT:  'LEFT',
        apds9960.DIR_RIGHT: 'RIGHT',
        apds9960.DIR_NEAR:  'NEAR',
        apds9960.DIR_FAR:   'FAR',
    }.get(g, 'NONE')
    
# Pins (Edison)
# GND   GND
# VCC   3.3V
# SDA   GP20 (SDA, bus 1)
# SCL   GP19 (SCL, bus 1)
gs = apds9960.APDS9960(1);

# Initialize
if gs.init():
    print('APDS-9960 initialization complete');
else:
    print('Something went wrong during APDS-9960 init!');
    
# Start the light sensor (no interrupts)
if gs.enableLightSensor(False):
    print('Light sensor is now running')
else:
    print('Something went wrong during light sensor init!')
    
# Wait 200 ms for the sensor to begin
time.sleep(0.2)

# Run the light sensor for 5 seconds
t = 0
while t < 10:
    print('Ambient: ' + str(gs.readAmbientLight()) + 
          ' Red: ' + str(gs.readRedLight()) +
          ' Green: ' + str(gs.readGreenLight()) +
          ' Blue: ' + str(gs.readBlueLight()))
    t += 1
    time.sleep(0.5)

# Stop the light sensor
if gs.disableLightSensor():
    print('Light sensor stopped')
else:
    print('Something went wrong during light sensor disable!');
    
# Set proximity gain
if not gs.setProximityGain(apds9960.PGAIN_2X):
    print('Something went wrong trying to set PGAIN')

# Start running the proximity sensor (no interrupts)
if gs.enableProximitySensor(False):
    print('Proximity sensor is now running')
else:
    print('Something went wrong during proximity sensor init!')

# Wait 200 ms for the sensor to begin
time.sleep(0.2)

# Run the proximity sensor for 5 seconds
t = 0
while t < 10:
    print('Proximity: ' + str(gs.readProximity()))
    t += 1
    time.sleep(0.5)

# Stop the proximity sensor
if gs.disableProximitySensor():
    print('Proximity sensor stopped')
else:
    print('Something went wrong during proximity sensor disable!')

# Start the gesture engine (no interrupts)
if gs.enableGestureSensor(False):
    print('Gesture sensor is now running')
else:
    print('Something went wrong during gesture sensor init!')
    
# Wait 200 ms for the sensor to begin
time.sleep(0.2)


# Run the gesture sensor for 10 seconds
t = 0
while t < 100:
    if gs.isGestureAvailable():
        g = gs.readGesture()
        print(gestures(g))
    t += 1
    time.sleep(0.1)
    
# Stop the gesture engine
if gs.disableGestureSensor():
    print('Gesture sensor stopped')
else:
    print('Something went wrong during gesture sensor disable!')

# Don't forget to free up that memory!
del gs
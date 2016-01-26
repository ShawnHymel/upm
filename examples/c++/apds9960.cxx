/**
 * Author: Shawn Hymel
 * Copyright (c) 2016 SparkFun Electronics
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
#include <unistd.h>

#include "apds9960.h"

int main(int argc, char **argv) {
//! [Interesting]

    // Pins (Edison)
    // GND      GND
    // VCC      3.3V
    // SDA      GP20 (SDA, bus 1)
    // SCL      GP19 (SCL, bus 1)
    upm::APDS9960 * gs = new upm::APDS9960(1);
    
    int t;
    
    // Initialize
    if (gs->init()) {
        printf("APDS-9960 initialization complete\n");
    } else {
        printf("Something went wrong during APDS-9960 init!\n");
    }
    
    // Start the light sensor (no interrupts)
    if (gs->enableLightSensor(false)) {
        printf("Light sensor is now running\n");
    } else {
        printf("Something went wrong during light sensor init!\n");
    }
    
    // Wait 200 ms for the sensor to begin
    usleep(200000);
    
    // Run the light sensor for 5 seconds
    t = 0;
    while (t < 10) {
        printf("Ambient: %i Red: %i Green: %i Blue: %i\n",
                gs->readAmbientLight(),
                gs->readRedLight(),
                gs->readGreenLight(),
                gs->readBlueLight());
        t++;
        usleep(500000);
    }
    
    // Stop the light sensor
    if (gs->disableLightSensor()) {
        printf("Light sensor stopped\n");
    } else {
        printf("Something wnet wrong during light sensor disable!\n");
    }
    
    // Set proximity gain
    if (!gs->setProximityGain(PGAIN_2X)) {
        printf("Something went wrong trying to set PGAIN");
    }
    
    // Start running the proximity sensor (no interrupts)
    if (gs->enableProximitySensor(false)) {
        printf("Proximity sensor is now running\n");
    } else {
        printf("Something went wrong during proximity sensor init!\n");
    }
    
    // Wait 200 ms for the sensor to begin
    usleep(200000);
    
    // Run the proximity sensor for 5 seconds
    t = 0;
    while (t < 10) {
        printf("Proximity: %i\n", gs->readProximity());
        t++;
        usleep(500000);
    }

    // Stop the proximity sensor
    if (gs->disableProximitySensor()) {
        printf("Proximity sensor stopped\n");
    } else {
        printf("Something wnet wrong during light sensor disable!\n");
    }
    
    // Start gesture engine (no interrupts)
    if (gs->enableGestureSensor(false)) {
        printf("Gesture sensor is now running\n");
    } else {
        printf("Something went wrong during gesture sensor init!\n");
    }
    
    // Wait 200 ms for the sensor to begin
    usleep(200000);

    // Run the proximity sensor for 10 seconds
    t = 0;
    while (t < 100) {
        if (gs->isGestureAvailable()) {
            switch(gs->readGesture()) {
                case DIR_UP:
                    printf("UP\n");
                    break;
                case DIR_DOWN:
                    printf("DOWN\n");
                    break;
                case DIR_LEFT:
                    printf("LEFT\n");
                    break;
                case DIR_RIGHT:
                    printf("RIGHT\n");
                    break;
                case DIR_NEAR:
                    printf("NEAR\n");
                    break;
                case DIR_FAR:
                    printf("FAR\n");
                    break;
                default:
                    printf("NONE\n");
                    break;
            }   
        }      
        t++;
        usleep(100000);
    }
    
    // Stop the gesture engine
    if (gs->disableGestureSensor()) {
        printf("Gesture sensor stopped\n");
    } else {
        printf("Something went wrong during gesture sensor init!\n");
    }
    
    // Don't forget to free up that memory!
    delete gs;
//! [Interesting]
    return 0;
}
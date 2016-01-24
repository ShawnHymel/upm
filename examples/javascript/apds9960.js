/*jslint node:true, vars:true, bitwise:true, unparam:true */
/*jshint unused:true */

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
 
var apds9960 = require('jsupm_apds9960');

// Pins (Edison)
// GND      GND
// VCC      3.3V
// SDA      GP20 (SDA, bus 1)
// SCL      GP19 (SCL, bus 1)
var gs = new apds9960.APDS9960(1);

// Thread handle
var thread;

///////////////////////////////////////////////////////////////////////////////
// Functions
///////////////////////////////////////////////////////////////////////////////

// Poll the light sensor and print to console
function doLight() {
    var ambientLight = gs.readAmbientLight();
    var redLight = gs.readRedLight();
    var greenLight = gs.readGreenLight();
    var blueLight = gs.readBlueLight();

    console.log("Ambient: " + ambientLight +
                    " Red: " + redLight +
                    " Green: " + greenLight +
                    " Blue: " + blueLight);
}

// Poll the proximity sensor and print to console
function doProximity() {
    var prox = gs.readProximity();
    console.log("Proximity: " + prox);
}

// Poll the gesture sensor and print to console
function doGesture() {
    if (gs.isGestureAvailable()) {
        switch(gs.readGesture()) {
            case apds9960.DIR_UP:
                console.log("UP");
                break;
            case apds9960.DIR_DOWN:
                console.log("DOWN");
                break;
            case apds9960.DIR_LEFT:
                console.log("LEFT");
                break;
            case apds9960.DIR_RIGHT:
                console.log("RIGHT");
                break;
            case apds9960.DIR_NEAR:
                console.log("NEAR");
                break;
            case apds9960.DIR_FAR:
                console.log("FAR");
                break;
            default:
                console.log("NONE");
                break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// Execution starts here
///////////////////////////////////////////////////////////////////////////////

// Initialize
if (gs.init()) {
    console.log("APDS-9960 initialization complete");
} else {
    console.log("Something went wrong during APDS-9960 init!");
}

// Start running light sensor (no interrupts)
if (gs.enableLightSensor(false)) {
    console.log("Light sensor is now running");
} else {
    console.log("Something went wrong during light sensor init!");
}

// Run the light sensor for a while
thread = setInterval(doLight, 500);

// Stop sensing light, and sense proximity
setTimeout(function() {
    clearTimeout(thread);

    // Stop light sensor
    if (gs.disableLightSensor()) {
        console.log("Light sensor stopped");
    } else {
        console.log("Something wnet wrong during light sensor disable!");
    }

    // Start proximity sensor
    if (!gs.setProximityGain(apds9960.PGAIN_2X)) {
        console.log("Something went wrong trying to set PGAIN");
    }

    // Start running the proximity sensor (no interrupts)
    if (gs.enableProximitySensor(false)) {
        console.log("Proximity sensor is now running");
    } else {
        console.log("Something went wrong during proximity sensor init!");
        return;
    }

    // Run the proximity sensor for a while
    thread = setInterval(doProximity, 500);
}, 5000);

// Stop sensing proximity, and start looking for gestures
setTimeout(function() {
    clearTimeout(thread);

    // Stop proximity sensor
    if (gs.disableProximitySensor()) {
        console.log("Proximity sensor stopped");
    } else {
        console.log("Something wnet wrong during light sensor disable!");
    }

    // Start gesture sensor engine (no interrupts)
    if (gs.enableGestureSensor(false)) {
        console.log("Gesture sensor is now running");
    } else {
        console.log("Something went wrong during gesture sensor init!");
        return;
    }

    // Run the gesture sensor for a while
    thread = setInterval(doGesture, 100);
}, 10000);

// Stop looking for gestures
setTimeout(function() {
    clearTimeout(thread);

    // Stop gesture sensor engine
    if (gs.disableGestureSensor()) {
        console.log("Gesture sensor stopped");
    } else {
        console.log("Something went wrong during gesture sensor init!");
        return;
    }
}, 20000);
/*
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

#pragma once

// Includes
#include <stdio.h>
#include <mraa/common.hpp>
#include <mraa/i2c.hpp>

// Debug
#define DEBUG               0

// APDS-9960 I2C address
#define APDS9960_I2C_ADDR   0x39

// Gesture parameters
#define GESTURE_THRESHOLD_OUT   10
#define GESTURE_SENSITIVITY_1   50
#define GESTURE_SENSITIVITY_2   20

// Error code for returned values
#define ERROR                   0xFF

// Acceptable device IDs
#define APDS9960_ID_1           0xAB
#define APDS9960_ID_2           0x9C 

// Misc parameters
#define FIFO_PAUSE_TIME         30      // Wait period (ms) between FIFO reads

//* APDS-9960 register addresses
#define APDS9960_ENABLE         0x80
#define APDS9960_ATIME          0x81
#define APDS9960_WTIME          0x83
#define APDS9960_AILTL          0x84
#define APDS9960_AILTH          0x85
#define APDS9960_AIHTL          0x86
#define APDS9960_AIHTH          0x87
#define APDS9960_PILT           0x89
#define APDS9960_PIHT           0x8B
#define APDS9960_PERS           0x8C
#define APDS9960_CONFIG1        0x8D
#define APDS9960_PPULSE         0x8E
#define APDS9960_CONTROL        0x8F
#define APDS9960_CONFIG2        0x90
#define APDS9960_ID             0x92
#define APDS9960_STATUS         0x93
#define APDS9960_CDATAL         0x94
#define APDS9960_CDATAH         0x95
#define APDS9960_RDATAL         0x96
#define APDS9960_RDATAH         0x97
#define APDS9960_GDATAL         0x98
#define APDS9960_GDATAH         0x99
#define APDS9960_BDATAL         0x9A
#define APDS9960_BDATAH         0x9B
#define APDS9960_PDATA          0x9C
#define APDS9960_POFFSET_UR     0x9D
#define APDS9960_POFFSET_DL     0x9E
#define APDS9960_CONFIG3        0x9F
#define APDS9960_GPENTH         0xA0
#define APDS9960_GEXTH          0xA1
#define APDS9960_GCONF1         0xA2
#define APDS9960_GCONF2         0xA3
#define APDS9960_GOFFSET_U      0xA4
#define APDS9960_GOFFSET_D      0xA5
#define APDS9960_GOFFSET_L      0xA7
#define APDS9960_GOFFSET_R      0xA9
#define APDS9960_GPULSE         0xA6
#define APDS9960_GCONF3         0xAA
#define APDS9960_GCONF4         0xAB
#define APDS9960_GFLVL          0xAE
#define APDS9960_GSTATUS        0xAF
#define APDS9960_IFORCE         0xE4
#define APDS9960_PICLEAR        0xE5
#define APDS9960_CICLEAR        0xE6
#define APDS9960_AICLEAR        0xE7
#define APDS9960_GFIFO_U        0xFC
#define APDS9960_GFIFO_D        0xFD
#define APDS9960_GFIFO_L        0xFE
#define APDS9960_GFIFO_R        0xFF

namespace upm {

    /**
     * @brief APDS9960 gesture sensor library
     * @defgroup apds9960 libupm-apds9960
     * @ingroup sparkfun i2c light
     */
     
    /**
     * @library apds9960
     * @sensor apds9960
     * @comname APDS9960 color, light, proximity, and gesture sensor
     * @altname SparkFun RGB and Gesture Sensor
     * @type light
     * @man sparkfun
     * @con i2c
     *
     * @brief API for the APDS9960 RGB and gesture sensor
     * 
     * The APDS9960 is a color, light, proximity, and simple gesture sensor.
     * Datasheet: https://goo.gl/2JqbMe
     * The sensor offers ambient light and color measuring, proximity detection,
     * and touchless gesture sensing. 
     * 
     * @image html apds9960.jpg
     * @snippet apds9960.cxx Interesting
     */
    class APDS9960 {
        public:
        
            /**
             * Creates an APDS9960 object
             *
             * @param bus Bus number for I2C
             */
            APDS9960(int bus);
            
            /**
             * @brief Reads a single byte from the I2C device and given register
             *
             * @param[in] reg the register to read from
             * @param[out] the value returned from the register
             * @return True if successful read operation. False otherwise.
             */
            bool wireReadDataByte(uint8_t reg, uint8_t &val);
            
            void test();
        
        private:
            
            mraa::I2c m_i2c;
    };
}
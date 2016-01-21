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
#include <unistd.h>
#include <mraa/common.hpp>
#include <mraa/i2c.hpp>

// Debug
#define APDS9960_DEBUG          0

// APDS-9960 I2C address
#define APDS9960_I2C_ADDR       0x39

// Gesture parameters
#define GESTURE_THRESHOLD_OUT   10
#define GESTURE_SENSITIVITY_1   50
#define GESTURE_SENSITIVITY_2   20

// Error code for returned values
#define APDS9960_ERROR          0xFF

// Acceptable device IDs
#define APDS9960_ID_1           0xAB
#define APDS9960_ID_2           0x9C 

// Misc parameters
#define FIFO_PAUSE_TIME         30000      // Wait (us) between FIFO reads

// APDS-9960 register addresses
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

// Bit fields
#define APDS9960_PON            0b00000001
#define APDS9960_AEN            0b00000010
#define APDS9960_PEN            0b00000100
#define APDS9960_WEN            0b00001000
#define APSD9960_AIEN           0b00010000
#define APDS9960_PIEN           0b00100000
#define APDS9960_GEN            0b01000000
#define APDS9960_GVALID         0b00000001

// On/Off definitions
#define OFF                     0
#define ON                      1

// Acceptable parameters for setMode
#define POWER                   0
#define AMBIENT_LIGHT           1
#define PROXIMITY               2
#define WAIT                    3
#define AMBIENT_LIGHT_INT       4
#define PROXIMITY_INT           5
#define GESTURE                 6
#define ALL                     7

// LED Drive values
#define LED_DRIVE_100MA         0
#define LED_DRIVE_50MA          1
#define LED_DRIVE_25MA          2
#define LED_DRIVE_12_5MA        3

// Proximity Gain (PGAIN) values
#define PGAIN_1X                0
#define PGAIN_2X                1
#define PGAIN_4X                2
#define PGAIN_8X                3

// ALS Gain (AGAIN) values
#define AGAIN_1X                0
#define AGAIN_4X                1
#define AGAIN_16X               2
#define AGAIN_64X               3

// Gesture Gain (GGAIN) values
#define GGAIN_1X                0
#define GGAIN_2X                1
#define GGAIN_4X                2
#define GGAIN_8X                3

// LED Boost values
#define LED_BOOST_100           0
#define LED_BOOST_150           1
#define LED_BOOST_200           2
#define LED_BOOST_300           3    

// Gesture wait time values
#define GWTIME_0MS              0
#define GWTIME_2_8MS            1
#define GWTIME_5_6MS            2
#define GWTIME_8_4MS            3
#define GWTIME_14_0MS           4
#define GWTIME_22_4MS           5
#define GWTIME_30_8MS           6
#define GWTIME_39_2MS           7

// Default values
#define DEFAULT_ATIME           219     // 103ms
#define DEFAULT_WTIME           246     // 27ms
#define DEFAULT_PROX_PPULSE     0x87    // 16us, 8 pulses
#define DEFAULT_GESTURE_PPULSE  0x89    // 16us, 10 pulses
#define DEFAULT_POFFSET_UR      0       // 0 offset
#define DEFAULT_POFFSET_DL      0       // 0 offset      
#define DEFAULT_CONFIG1         0x60    // No 12x wait (WTIME) factor
#define DEFAULT_LDRIVE          LED_DRIVE_100MA
#define DEFAULT_PGAIN           PGAIN_4X
#define DEFAULT_AGAIN           AGAIN_4X
#define DEFAULT_PILT            0       // Low proximity threshold
#define DEFAULT_PIHT            50      // High proximity threshold
#define DEFAULT_AILT            0xFFFF  // Force interrupt for calibration
#define DEFAULT_AIHT            0
#define DEFAULT_PERS            0x11    // 2 consecutive prox or ALS for int.
#define DEFAULT_CONFIG2         0x01    // No saturation interrupts or LED boost  
#define DEFAULT_CONFIG3         0       // Enable all photodiodes, no SAI
#define DEFAULT_GPENTH          40      // Threshold for entering gesture mode
#define DEFAULT_GEXTH           30      // Threshold for exiting gesture mode    
#define DEFAULT_GCONF1          0x40    // 4 gesture events for int., 1 for exit
#define DEFAULT_GGAIN           GGAIN_4X
#define DEFAULT_GLDRIVE         LED_DRIVE_100MA
#define DEFAULT_GWTIME          GWTIME_2_8MS
#define DEFAULT_GOFFSET         0       // No offset scaling for gesture mode
#define DEFAULT_GPULSE          0xC9    // 32us, 10 pulses
#define DEFAULT_GCONF3          0       // All photodiodes active during gesture
#define DEFAULT_GIEN            0       // Disable gesture interrupts

// Direction definitions
enum {
  DIR_NONE,
  DIR_LEFT,
  DIR_RIGHT,
  DIR_UP,
  DIR_DOWN,
  DIR_NEAR,
  DIR_FAR,
  DIR_ALL
};

// State definitions
enum {
  NA_STATE,
  NEAR_STATE,
  FAR_STATE,
  ALL_STATE
};

// Container for gesture data
typedef struct gesture_data_type {
    uint8_t u_data[32];
    uint8_t d_data[32];
    uint8_t l_data[32];
    uint8_t r_data[32];
    uint8_t index;
    uint8_t total_gestures;
    uint8_t in_threshold;
    uint8_t out_threshold;
} gesture_data_type;

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
             * @brief Configures I2C and initializes registers to defaults
             *
             * @return True if initialized successfully. False otherwise.
             */
            bool init();
            
            /**
             * @brief Reads and returns the contents of the ENABLE register
             *
             * @return Contents of the ENABLE register. 0xFF if error.
             */
            uint8_t getMode();
            
            /**
             * @brief Enables or disables a feature in the APDS-9960
             *
             * @param[in] mode which feature to enable
             * @param[in] enable ON (1) or OFF (0)
             * @return True if operation success. False otherwise.
             */
            bool setMode(uint8_t mode, uint8_t enable);
            
            //////////////////////////////////////////////////////////////////
            // Turn APDS-9960 on and off
            //////////////////////////////////////////////////////////////////
            
            /**
             * Turn the APDS-9960 on
             *
             * @return True if operation successful. False otherwise.
             */
            bool enablePower();
            
            /**
             * Turn the APDS-9960 off
             *
             * @return True if operation successful. False otherwise.
             */
            bool disablePower();
            
            //////////////////////////////////////////////////////////////////
            // Enable or disable specific sensors
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Starts the light (R/G/B/Ambient) sensor on the APDS-9960
             *
             * @param[in] interrupts true to enable interrupt on hi or low light
             * @return True if sensor enabled correctly. False on error.
             */
            bool enableLightSensor(bool interrupts = false);
            
            /**
             * @brief Ends the light sensor on the APDS-9960
             *
             * @return True if sensor disabled correctly. False on error.
             */
            bool disableLightSensor();
            
            /**
             * @brief Starts the proximity sensor on the APDS-9960
             *
             * @param[in] interrupts true to enable interrupt on proximity
             * @return True if sensor enabled correctly. False on error.
             */
            bool enableProximitySensor(bool interrupts = false);
            
            /**
             * @brief Ends the proximity sensor on the APDS-9960
             *
             * @return True if sensor disabled correctly. False on error.
             */
            bool disableProximitySensor();
            
            /**
             * @brief Starts the gesture recognition engine on the APDS-9960
             *
             * @param[in] interrupts true to enable interrupt on gesture
             * @return True if engine enabled correctly. False on error.
             */
            bool enableGestureSensor(bool interrupts = true);
            
            /**
             * @brief Ends the gesture recognition engine on the APDS-9960
             *
             * @return True if engine disabled correctly. False on error.
             */
            bool disableGestureSensor();
            
            //////////////////////////////////////////////////////////////////
            // LED drive strength control
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Returns LED drive strength for proximity and ALS
             *
             * Value    LED Current
             *   0        100 mA
             *   1         50 mA
             *   2         25 mA
             *   3         12.5 mA
             *
             * @return the value of the LED drive strength. 0xFF on failure.
             */
            uint8_t getLEDDrive();
            
            /**
             * @brief Sets the LED drive strength for proximity and ALS
             *
             * Value    LED Current
             *   0        100 mA
             *   1         50 mA
             *   2         25 mA
             *   3         12.5 mA
             *
             * @param[in] drive the value (0-3) for the LED drive strength
             * @return True if operation successful. False otherwise.
             */
            bool setLEDDrive(uint8_t drive);
            
            /**
             * @brief Gets the drive current of the LED during gesture mode
             *
             * Value    LED Current
             *   0        100 mA
             *   1         50 mA
             *   2         25 mA
             *   3         12.5 mA
             *
             * @return the LED drive current value. 0xFF on error.
             */
            uint8_t getGestureLEDDrive();
            
            /**
             * @brief Sets the LED drive current during gesture mode
             *
             * Value    LED Current
             *   0        100 mA
             *   1         50 mA
             *   2         25 mA
             *   3         12.5 mA
             *
             * @param[in] drive the value for the LED drive current
             * @return True if operation successful. False otherwise.
             */
            bool setGestureLEDDrive(uint8_t drive);
            
            //////////////////////////////////////////////////////////////////
            // Gain control
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Returns receiver gain for the ambient light sensor (ALS)
             *
             * Value    Gain
             *   0        1x
             *   1        4x
             *   2       16x
             *   3       64x
             *
             * @return the value of the ALS gain. 0xFF on failure.
             */
            uint8_t getAmbientLightGain();
            
            /**
             * @brief Sets the receiver gain for the ambient light sensor (ALS)
             *
             * Value    Gain
             *   0        1x
             *   1        4x
             *   2       16x
             *   3       64x
             *
             * @param[in] drive the value (0-3) for the gain
             * @return True if operation successful. False otherwise.
             */
            bool setAmbientLightGain(uint8_t gain);
            
            /**
             * @brief Returns receiver gain for proximity detection
             *
             * Value    Gain
             *   0       1x
             *   1       2x
             *   2       4x
             *   3       8x
             *
             * @return the value of the proximity gain. 0xFF on failure.
             */
            uint8_t getProximityGain();
            
            /**
             * @brief Sets the receiver gain for proximity detection
             *
             * Value    Gain
             *   0       1x
             *   1       2x
             *   2       4x
             *   3       8x
             *
             * @param[in] drive the value (0-3) for the gain
             * @return True if operation successful. False otherwise.
             */
            bool setProximityGain(uint8_t gain);
            
            /**
             * @brief Gets the gain of the photodiode during gesture mode
             *
             * Value    Gain
             *   0       1x
             *   1       2x
             *   2       4x
             *   3       8x
             *
             * @return the current photodiode gain. 0xFF on error.
             */
            uint8_t getGestureGain();
            
            /**
             * @brief Sets the gain of the photodiode during gesture mode
             *
             * Value    Gain
             *   0       1x
             *   1       2x
             *   2       4x
             *   3       8x
             *
             * @param[in] gain the value for the photodiode gain
             * @return True if operation successful. False otherwise.
             */
            bool setGestureGain(uint8_t gain);
            
            //////////////////////////////////////////////////////////////////
            // Get and set light interrupt thresholds
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Gets the low threshold for ambient light interrupts
             *
             * @param[out] threshold current low threshold stored on the sensor
             * @return True if operation successful. False otherwise.
             */
            bool getLightIntLowThreshold(uint16_t &threshold);
            
            /**
             * @brief Sets the low threshold for ambient light interrupts
             *
             * @param[in] threshold low threshold value to trigger interrupt
             * @return True if operation successful. False otherwise.
             */
            bool setLightIntLowThreshold(uint16_t threshold);
            
            /**
             * @brief Gets the high threshold for ambient light interrupts
             *
             * @param[out] threshold current low threshold stored on the sensor
             * @return True if operation successful. False otherwise.
             */
            bool getLightIntHighThreshold(uint16_t &threshold);
            
            /**
             * @brief Sets the high threshold for ambient light interrupts
             *
             * @param[in] threshold high threshold value to trigger interrupt
             * @return True if operation successful. False otherwise.
             */
            bool setLightIntHighThreshold(uint16_t threshold);
            
            //////////////////////////////////////////////////////////////////
            // Get and set proximity interrupt thresholds
            //////////////////////////////////////////////////////////////////  
            
            /**
             * @brief Gets the low threshold for proximity interrupts
             *
             * @param[out] threshold current low threshold stored on the sensor
             * @return True if operation successful. False otherwise.
             */
            bool getProximityIntLowThreshold(uint8_t &threshold);
            
            /**
             * @brief Sets the low threshold for proximity interrupts
             *
             * @param[in] threshold low threshold value to trigger interrupt
             * @return True if operation successful. False otherwise.
             */
            bool setProximityIntLowThreshold(uint8_t threshold);
            
            /**
             * @brief Gets the high threshold for proximity interrupts
             *
             * @param[out] threshold current low threshold stored on the sensor
             * @return True if operation successful. False otherwise.
             */
            bool getProximityIntHighThreshold(uint8_t &threshold);
            
            /**
             * @brief Sets the high threshold for proximity interrupts
             *
             * @param[in] threshold high threshold value to trigger interrupt
             * @return True if operation successful. False otherwise.
             */
            bool setProximityIntHighThreshold(uint8_t threshold);
            
            //////////////////////////////////////////////////////////////////
            // Get and set interrupt enables
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Gets if ambient light interrupts are enabled or not
             *
             * @return 1 if interrupts are enabled, 0 if not. 0xFF on error.
             */
            uint8_t getAmbientLightIntEnable();
            
            /**
             * @brief Turns ambient light interrupts on or off
             *
             * @param[in] enable 1 to enable interrupts, 0 to turn them off
             * @return True if operation successful. False otherwise.
             */
            bool setAmbientLightIntEnable(uint8_t enable);
            
            /**
             * @brief Gets if proximity interrupts are enabled or not
             *
             * @return 1 if interrupts are enabled, 0 if not. 0xFF on error.
             */
            uint8_t getProximityIntEnable();
            
            /**
             * @brief Turns proximity interrupts on or off
             *
             * @param[in] enable 1 to enable interrupts, 0 to turn them off
             * @return True if operation successful. False otherwise.
             */
            bool setProximityIntEnable(uint8_t enable);
            
            /**
             * @brief Gets if gesture interrupts are enabled or not
             *
             * @return 1 if interrupts are enabled, 0 if not. 0xFF on error.
             */
            uint8_t getGestureIntEnable();
            
            /**
             * @brief Turns gesture-related interrupts on or off
             *
             * @param[in] enable 1 to enable interrupts, 0 to turn them off
             * @return True if operation successful. False otherwise.
             */
            bool setGestureIntEnable(uint8_t enable);
            
            //////////////////////////////////////////////////////////////////
            // Clear interrupts
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Clears the ambient light interrupt
             *
             * @return True if operation completed successfully. False otherwise
             */
            bool clearAmbientLightInt();
            
            /**
             * @brief Clears the proximity interrupt
             *
             * @return True if operation completed successfully. False otherwise.
             */
            bool clearProximityInt();
            
            //////////////////////////////////////////////////////////////////
            // Ambient light methods
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Reads the ambient (clear) light level as a 16-bit value
             *
             * @param[out] val value of the light sensor.
             * @return True if operation successful. False otherwise.
             */
            bool readAmbientLight(uint16_t &val);
            
            /**
             * @brief Reads the red light level as a 16-bit value
             *
             * @param[out] val value of the light sensor.
             * @return True if operation successful. False otherwise.
             */
            bool readRedLight(uint16_t &val);
            
            /**
             * @brief Reads the green light level as a 16-bit value
             *
             * @param[out] val value of the light sensor.
             * @return True if operation successful. False otherwise.
             */
            bool readGreenLight(uint16_t &val);
            
            /**
             * @brief Reads the blue light level as a 16-bit value
             *
             * @param[out] val value of the light sensor.
             * @return True if operation successful. False otherwise.
             */
            bool readBlueLight(uint16_t &val);
            
            //////////////////////////////////////////////////////////////////
            // Proximity methods
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Reads the proximity level as an 8-bit value
             *
             * @param[out] val value of the proximity sensor.
             * @return True if operation successful. False otherwise.
             */
            bool readProximity(uint8_t &val);
            
            //////////////////////////////////////////////////////////////////
            // Gesture methods
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Determines if there is a gesture available for reading
             *
             * @return True if gesture available. False otherwise.
             */
            bool isGestureAvailable();
            
            /**
             * @brief Processes a gesture event and returns best guessed gesture
             *
             * @return Number corresponding to gesture. -1 on error.
             */
            int readGesture();

            //////////////////////////////////////////////////////////////////
            // Gesture processing
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Resets all the parameters in the gesture data member
             */
            void resetGestureParameters();
            
            /**
             * @brief Processes the raw gesture data to determine swipe direction
             *
             * @return True if near or far state seen. False otherwise.
             */
            bool processGestureData();
            
            /**
             * @brief Determines swipe direction or near/far state
             *
             * @return True if near/far event. False otherwise.
             */
            bool decodeGesture();

            //////////////////////////////////////////////////////////////////
            // Proximity interrupt threshold
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Returns the lower threshold for proximity detection
             *
             * @return lower threshold
             */
            uint8_t getProxIntLowThresh();
            
            /**
             * @brief Sets the lower threshold for proximity detection
             *
             * @param[in] threshold the lower proximity threshold
             * @return True if operation successful. False otherwise.
             */
            bool setProxIntLowThresh(uint8_t threshold);
            
            /**
             * @brief Returns the high threshold for proximity detection
             *
             * @return high threshold
             */
            uint8_t getProxIntHighThresh();
            
            /**
             * @brief Sets the high threshold for proximity detection
             *
             * @param[in] threshold the high proximity threshold
             * @return True if operation successful. False otherwise.
             */
            bool setProxIntHighThresh(uint8_t threshold);
            
            //////////////////////////////////////////////////////////////////
            // LED boost control
            //////////////////////////////////////////////////////////////////
             
            /**
             * @brief Get the current LED boost value
             * 
             * Value  Boost Current
             *   0        100%
             *   1        150%
             *   2        200%
             *   3        300%
             *
             * @return The LED boost value. 0xFF on failure.
             */
            uint8_t getLEDBoost();
             
            /**
             * @brief Sets the LED current boost value
             *
             * Value  Boost Current
             *   0        100%
             *   1        150%
             *   2        200%
             *   3        300%
             *
             * @param[in] drive the value (0-3) for current boost (100-300%)
             * @return True if operation successful. False otherwise.
             */
            bool setLEDBoost(uint8_t boost);
            
            //////////////////////////////////////////////////////////////////
            // Proximity photodiode select
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Gets proximity gain compensation enable
             *
             * @return 1 if compensation is enabled. 0 if not. 0xFF on error.
             */
            uint8_t getProxGainCompEnable();
            
            /**
             * @brief Sets the proximity gain compensation enable
             *
             * @param[in] enable 1 to enable compensation. 0 to disable compensation.
             * @return True if operation successful. False otherwise.
             */
            bool setProxGainCompEnable(uint8_t enable);
            
            /**
             * @brief Gets the current mask for enabled/disabled proximity photodiodes
             *
             * 1 = disabled, 0 = enabled
             * Bit    Photodiode
             *  3       UP
             *  2       DOWN
             *  1       LEFT
             *  0       RIGHT
             *
             * @return Current proximity mask for photodiodes. 0xFF on error.
             */
            uint8_t getProxPhotoMask();
            
            /**
             * @brief Sets the mask for enabling/disabling proximity photodiodes
             *
             * 1 = disabled, 0 = enabled
             * Bit    Photodiode
             *  3       UP
             *  2       DOWN
             *  1       LEFT
             *  0       RIGHT
             *
             * @param[in] mask 4-bit mask value
             * @return True if operation successful. False otherwise.
             */
            bool setProxPhotoMask(uint8_t mask);
            
            //////////////////////////////////////////////////////////////////
            // Gesture threshold control
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Gets the entry proximity threshold for gesture sensing
             *
             * @return Current entry proximity threshold.
             */
            uint8_t getGestureEnterThresh();
            
            /**
             * @brief Sets the entry proximity threshold for gesture sensing
             *
             * @param[in] threshold proximity value needed to start gesture mode
             * @return True if operation successful. False otherwise.
             */
            bool setGestureEnterThresh(uint8_t threshold);
            /**
             * @brief Gets the exit proximity threshold for gesture sensing
             *
             * @return Current exit proximity threshold.
             */
            uint8_t getGestureExitThresh();
            
            /**
             * @brief Sets the exit proximity threshold for gesture sensing
             *
             * @param[in] threshold proximity value needed to end gesture mode
             * @return True if operation successful. False otherwise.
             */
            bool setGestureExitThresh(uint8_t threshold);
            
            //////////////////////////////////////////////////////////////////
            // Gesture LED, gain, and time control
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Gets the time in low power mode between gesture detections
             *
             * Value    Wait time
             *   0          0 ms
             *   1          2.8 ms
             *   2          5.6 ms
             *   3          8.4 ms
             *   4         14.0 ms
             *   5         22.4 ms
             *   6         30.8 ms
             *   7         39.2 ms
             *
             * @return the current wait time between gestures. 0xFF on error.
             */
            uint8_t getGestureWaitTime();
            
            /**
             * @brief Sets the time in low power mode between gesture detections
             *
             * Value    Wait time
             *   0          0 ms
             *   1          2.8 ms
             *   2          5.6 ms
             *   3          8.4 ms
             *   4         14.0 ms
             *   5         22.4 ms
             *   6         30.8 ms
             *   7         39.2 ms
             *
             * @param[in] the value for the wait time
             * @return True if operation successful. False otherwise.
             */
            bool setGestureWaitTime(uint8_t time);
            
            //////////////////////////////////////////////////////////////////
            // Gesture mode
            //////////////////////////////////////////////////////////////////            
            
            /**
             * @brief Tells if the gesture state machine is currently running
             *
             * @return 1 if gesture state machine is running. 0xFF on error.
             */
            uint8_t getGestureMode();
            
            /**
             * @brief Tells state machine to either enter or exit gesture mode
             *
             * @param[in] mode 1 to enter gesture state machine, 0 to exit.
             * @return True if operation successful. False otherwise.
             */
            bool setGestureMode(uint8_t mode);
            
            ///////////////////////////////////////////////////////////////////
            // Raw I2C Commands
            //////////////////////////////////////////////////////////////////
            
            /**
             * @brief Writes a single byte to the I2C device (no register)
             *
             * @param[in] val the 1-byte value to write to the I2C device
             * @return True if successful write operation. False otherwise.
             */
            bool wireWriteByte(uint8_t val);
            
            /**
             * @brief Writes a single byte to the I2C device and given register
             *
             * @param[in] reg the register in the I2C device to write to
             * @param[in] val the 1-byte value to write to the I2C device
             * @return True if successful write operation. False otherwise.
             */
            bool wireWriteDataByte(uint8_t reg, uint8_t val);
            
            /**
             * @brief Writes array of bytes to the I2C device and register
             *
             * @param[in] reg the register in the I2C device to write to
             * @param[in] val pointer to the beginning of the data byte array
             * @param[in] len the length (in bytes) of the data to write
             * @return True if successful write operation. False otherwise.
             */
            bool wireWriteDataBlock(uint8_t reg, 
                                    uint8_t *val, 
                                    unsigned int len);
            
            /**
             * @brief Reads a single byte from the I2C device and given register
             *
             * @param[in] reg the register to read from
             * @param[out] the value returned from the register
             * @return True if successful read operation. False otherwise.
             */
            bool wireReadDataByte(uint8_t reg, uint8_t &val);
            
            /**
             * @brief Reads array of bytes from the I2C device and register
             *
             * @param[in] reg the register to read from
             * @param[out] val pointer to the beginning of the data
             * @param[in] len number of bytes to read
             * @return Number of bytes read. -1 on read error.
             */
            int wireReadDataBlock(uint8_t reg, 
                                  uint8_t *val, 
                                  unsigned int len);
            
        private:
            
            // Members
            mraa::I2c m_i2c;
            gesture_data_type gesture_data_;
            int gesture_ud_delta_;
            int gesture_lr_delta_;
            int gesture_ud_count_;
            int gesture_lr_count_;
            int gesture_near_count_;
            int gesture_far_count_;
            int gesture_state_;
            int gesture_motion_;
    };
}
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

#include "apds9960.h"

using namespace upm;

APDS9960::APDS9960(int bus) : m_i2c(bus) {

    mraa::Result error = mraa::SUCCESS;

    // Initialize bus
    error = m_i2c.address(APDS9960_I2C_ADDR);
    if ( error != mraa::SUCCESS ) {
        mraa::printError(error);
    }
        
}

void APDS9960::test() {
    printf("Oh, hi.\n");
    
    // Read ID register and check against known values for APDS-9960
    uint8_t id;
    if ( !wireReadDataByte(APDS9960_ID, id) ) {
        printf("Error reading ID");
    }
    printf("ID: %i\n", id);
}

bool APDS9960::wireReadDataByte(uint8_t reg, uint8_t &val) 
{

    uint8_t result;

    // Read from register
    m_i2c.address(APDS9960_I2C_ADDR);
    m_i2c.writeByte(reg);
    m_i2c.address(APDS9960_I2C_ADDR);
    result = m_i2c.readByte();

    val = result;

    return true;
}

/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main() //Hola
{
    // Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);  //led
#else
    bool led;
#endif   

    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

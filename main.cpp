/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "ThisThread.h"
#include "mbed.h"
#include "InterruptIn.h"

InterruptIn int1(BUTTON1);
DigitalOut myled(LED1);
int delay =1000;

void pressed()
{
    if (delay == 2000)
        delay = 200; // 200 ms                                                  
    else
        delay = 2000; // 1 sec                                                  
}



int main() //Hola
{

    int measure[5];
    float averageValue;

    int1.rise(&pressed);

    while (true) {


        myled = !myled;
        ThisThread::sleep_for(delay);

        
    }
}

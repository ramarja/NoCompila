/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "ThisThread.h"
#include "mbed.h"
#include "InterruptIn.h"
#include "plt_iks4a1.h"

InterruptIn int1(BUTTON1);
DigitalOut myled(LED1);
LPS22DF sensor(I2C_SDA, I2C_SCL); 
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
float pressure, temperature; 
    int1.rise(&pressed);
    sensor.begin();
    sensor.Enable(); 

    while (true) {

        sensor.GetPressure(&pressure);
        sensor.GetTemperature(&temperature);
        printf("Pressure[hPa]: %f , Temperature[C]: %f\r\n", pressure, temperature);
        myled = !myled;
        ThisThread::sleep_for(delay);

        
    }
}

/*
 *  File Name:Delay.c
 *
 *  Created on: Jun 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 */
#include "Delay.h"


void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}


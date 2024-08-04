/*
 *
 *  File Name: Systick.c
 *
 *  Created on: Jun 28, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include std_types file */
#include "std_types.h"

/* Include tm4c123gh6pm_registers file */
#include "tm4c123gh6pm_registers.h"

/* Include Systick driver header file */
#include "Systick.h"

/*=========================================================================================================================================
                                                    Api's Definitions
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Start_Systick_Timer.
 *
 * Description: this function is used to start systick timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Start_Systick_Timer(void){
    SYSTICK_CTRL_REG = 0;  /* clear control register */
    SYSTICK_CURRENT_REG = 0x0; /* clear current register  */
    SYSTICK_RELOAD_REG =15732439; /* put 15732439 in reload register in order to count 1 sec  */
    SYSTICK_CTRL_REG = 0x07; /* set enable(to start timer) and interrupts and clk src so we will add 0x07 in ctrl register */
    NVIC_SYSTEM_PRI3_REG |= (2<<29); /* set systick timer priority */
}

/*******************************************************************
 *
 * Function Name: Stop_Systick_Timer.
 *
 * Description: this function is used to stop systick timer.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Stop_Systick_Timer(void){
    SYSTICK_CTRL_REG = 0; /* clear ctrl register to stop systick timer */
    SYSTICK_CURRENT_REG = 0x0; /* clear current register */
}

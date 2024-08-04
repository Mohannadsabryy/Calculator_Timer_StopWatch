/*
 *
 *  File Name: SystickIF.c
 *
 *  Created on: Jun 30, 2024
 *
 *  Author: Mohannad Sabry
 *
*/
/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include std_types file */
#include "std_types.h"

/* Include Systick Interface header file */
#include "SystickIF.h"

/* Include Systick driver header file */
#include "Systick.h"

/*=========================================================================================================================================
                                                       Notes
=========================================================================================================================================*/

/*
 *
 * I made SystickIF.c and SystickIF.h in order to make an extra layer of abstraction between application layer and Mcal layer.
 * To implement the concept of modularity that application layer(StopWatch,Calculator,TimerMode) to access only the Hal layer.
 *
*/

/*=========================================================================================================================================
                                                      Functions Definition
=========================================================================================================================================*/

/************************************************************************************
 *
 * Function Name: start_timer.
 *
 * Description: This function is used to call Start_Systick_Timer function in MCAL.
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void start_timer(void){
    Start_Systick_Timer(); /* call start systick timer */
}

/************************************************************************************
 *
 * Function Name: stop_timer.
 *
 * Description: This function is used to call Stop_Systick_Timer function in MCAL.
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void stop_timer(void){
    Stop_Systick_Timer(); /* call stop systick timer */
}

/*
 *
 *  File name: GptmIF.c
 *
 *  Created on: Jul 25, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include std_types file */
#include "std_types.h"

/* Include Gptm Interface header file */
#include "GptmIF.h"

/* Include Gptm driver Header file */
#include "Gptm.h"

/*=========================================================================================================================================
                                                       Notes
=========================================================================================================================================*/

/*
 *
 * I made GptmIF.c and GptmIF.h in order to make an extra layer of abstraction between application layer and Mcal layer.
 * To implement the concept of modularity that application layer(StopWatch,Calculator,TimerMode) access only the Hal layer.
 *
*/

/*=========================================================================================================================================
                                                    Api's Definitions
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Start_StopWatch_Timer.
 *
 * Description: this function used to start timer in MCAL Layer.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Start_StopWatch_Timer(void){
    Start_Gptm_Timer(); /* call start gptm timer in MCAL */
}

/*******************************************************************
 *
 * Function Name: Stop_StopWatch_Timer.
 *
 * Description: this function used to stop timer in MCAL Layer.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Stop_StopWatch_Timer(void){
    Stop_Gptm_Timer(); /* call stop gptm timer in MCAL */
}





/*
 *
 *  File Name:SystickIF.h
 *
 *  Created on: Jun 30, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef SYSTICKIF_H_
#define SYSTICKIF_H_

/*=========================================================================================================================================
                                                      Functions Prototypes
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
void start_timer(void);

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
void stop_timer(void);

#endif /* SYSTICKIF_H_ */

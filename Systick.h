/*
 *  File Name: Systick.h
 *
 *  Created on: Jun 28, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
/*=========================================================================================================================================
                                                    Functions Prototypes
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
void Start_Systick_Timer(void);

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
void Stop_Systick_Timer(void);

#endif /* SYSTICK_H_ */

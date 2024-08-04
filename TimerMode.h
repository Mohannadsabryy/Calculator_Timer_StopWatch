/*
 *  File Name: TimerMode.h
 *
 *  Created on: Jun 26, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef TIMERMODE_H_
#define TIMERMODE_H_

/*=========================================================================================================================================
                                                   Macros
=========================================================================================================================================*/

/* Start timer Button is number 10 */
#define START_TIMER_BTN  10

/* Reset timer Button is number 11*/
#define RESET_BTN        11

/* Button that control minutes value is number 1 */
#define MIN_BTN          1

/* Button that control seconds value is number 2*/
#define SEC_BTN          2

/*=========================================================================================================================================
                                                   Function Protoypes
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Reset_Timer_Handle.
 *
 * Description: this function is used to reset timer values.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Reset_Timer_Handle(void);


/*******************************************************************
 *
 * Function Name: Timer_Mode_App.
 *
 * Description: this function is used to Handle timer app.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Timer_Mode_App(void);

#endif /* TIMERMODE_H_ */


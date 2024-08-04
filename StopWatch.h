/*
 *  File Name: StopWatch.h
 *
 *  Created on: Jul 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

/*=========================================================================================================================================
                                                     Macros
=========================================================================================================================================*/

/* macro to avoid majic numbers */
#define ZERO 0

/* Start StopWatch button is number 10 */
#define START_BTN  10

/* Reset StopWatch button is number 11 */
#define RESET_BTN  11

/* Stop StopWatch button is number 12 */
#define STOP_BTN   12

/*=========================================================================================================================================
                                                    Functions Prototypes
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: StopWatch_App.
 *
 * Description: this function is used to handle StopWatch App.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void StopWatch_App(void);

/*******************************************************************
 *
 * Function Name: Reset_StopWatch.
 *
 * Description: this function is used to reset StopWatch values.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Reset_StopWatch(void);

#endif /* STOPWATCH_H_ */

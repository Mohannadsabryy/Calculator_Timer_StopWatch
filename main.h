/*
 *  File Name: main.h
 *
 *  Created on: Jun 26, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef MAIN_H_
#define MAIN_H_
/*=========================================================================================================================================
                                                    Macros
=========================================================================================================================================*/
/* Global interrupt enable macro */
#define Global_Interrupt_Enable()   __asm(" CPSIE I ")

/* Calculator Mode macro */
#define CALCULATOR_MODE  1

/* TimerMode  macro */
#define TIMER_MODE       2

/* StopWatch mode macro */
#define STOPWATCH_MODE   3

/* Nothing mode macro */
#define NOTHING          0

/* Clk value of gpio peripheral */
#define CLK_VALUE       0x37

/* clk value of gptm peripheral*/
#define TIMER_CLK_VAL   0x1

#endif /* MAIN_H_ */

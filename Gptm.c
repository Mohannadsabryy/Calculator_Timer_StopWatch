/*
 *  File Name: Gptm.c
 *
 *  Created on: Jul 24, 2024
 *
 *  Author: Mohannad sabry
 *
 */
/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include std_types file */
#include "std_types.h"

/* Include tm4c123gh6pm_registers file */
#include "tm4c123gh6pm_registers.h"

/* Include Gptm Header file */
#include "Gptm.h"

/*=========================================================================================================================================
                                                    Api's Definitions
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Gptm_Init.
 *
 * Description: this function is used to initialize gptm timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Gptm_Init(void){
    TIMER0_GPTMCTL &= ~(1<<0); /* clear enable bit */
    TIMER0_GPTMCFG = 0x00000000; /* configure timer a 16/32-bit timer, this value selects the 32-bit timer configuration.*/
    TIMER0_GPTMTAMR |= 0x2; /* configure timer as a  Periodic Timer mode */
    TIMER0_GPTMIMR |= 0x1; /* enable peripheral interrupt */
    NVIC_EN0_REG |= 1<<19; /* enable interrupt from NVIC */
    NVIC_PRI4_REG |= (1<<29); /* Set priority for gptm* timer */
}
/*******************************************************************
 *
 * Function Name: Start_Gptm_Timer.
 *
 * Description: this function is used to start gptm timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Start_Gptm_Timer(void){
    TIMER0_GPTMTAILR = 15732439; /* setting this value in TIMER0_GPTMTAILR in order to count 1 sec */
    TIMER0_GPTMCTL |= (1<<0); /* set enable bit */
}
/*******************************************************************
 *
 * Function Name: Stop_Gptm_Timer.
 *
 * Description: this function is used to stop gptm timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Stop_Gptm_Timer(void){
    TIMER0_GPTMCTL &= ~(1<<0); /* clear enable bit */
}

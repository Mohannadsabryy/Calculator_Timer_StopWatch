/*
 *
 *  File Name:Led.c
 *
 *  Created on: Jun 30, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include tm4c123gh6pm_registers file */
#include "tm4c123gh6pm_registers.h"

/* Inlcude header file of Led */
#include "Led.h"

/* Include Gpio driver header file */
#include "Gpio.h"

/*=========================================================================================================================================
                                                      Functions Definition
=========================================================================================================================================*/

/************************************************************************************
 *
 * Function Name: Led_On.
 *
 * Description: This function is used to call GPIO_Turn_Blue_Led_On function in gpio
 *              driver
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void Led_On(void){
    GPIO_Turn_Blue_Led_On();
}

/************************************************************************************
 *
 * Function Name: Led_Off.
 *
 * Description: This function is used to call GPIO_Turn_Blue_Led_Off function in gpio
 *              driver
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void Led_Off(void){
    GPIO_Turn_Blue_Led_Off();
}

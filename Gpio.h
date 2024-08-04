/*
 *  File Name:Gpio.h
 *
 *  Created on: Jun 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 *  MC:TM4C123GH6PM
 */

#ifndef GPIO_H_
#define GPIO_H_

/*=========================================================================================================================================
                                                   Functions Prototypes
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: LcdDataPins.
 *
 * Description: this function is used to configure lcd data pins.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void LcdDataPins(void);
/*******************************************************************
 *
 * Function Name: Lcd_CtrlPins.
 *
 * Description: this function is used to configure lcd ctrl pins.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Lcd_CtrlPins(void);
/*******************************************************************
 *
 * Function Name: KepadPinsInit.
 *
 * Description: this function is used to configure keypad pins.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void KepadPinsInit(void);
/*******************************************************************
 *
 * Function Name: PushButtonInit.
 *
 * Description: this function is used to configure push button.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void PushButtonInit(void);

/*******************************************************************
 *
 * Function Name: GPIO_BLUE_LED.
 *
 * Description: this function is used to configure blue led.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void GPIO_BLUE_LED(void);

/************************************************************************************
 *
 * Function Name: GPIO_Turn_Blue_Led_On.
 *
 * Description: This function is used to turn on blue led.
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void GPIO_Turn_Blue_Led_On(void);

/************************************************************************************
 *
 * Function Name: GPIO_Turn_Blue_Led_Off.
 *
 * Description: This function is used to turn off blue led.
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void GPIO_Turn_Blue_Led_Off(void);

#endif /* GPIO_H_ */

/*
 *  File Name: LCD.h
 *
 *  Created on: Jun 24, 2024
 *
 *  Author: Mohannad Sabry Ghareeb
 *
 */

#ifndef LCD_H_
#define LCD_H_

/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/
#include "std_types.h"
#include "Lcd_Config.h"

/*=========================================================================================================================================
                                                   Functions Prototypes
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Lcd_Init.
 *
 * Description: this function is used to Initialize Lcd.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Lcd_Init(void);
/*******************************************************************
 *
 * Function Name: Lcd_SendCommand.
 *
 * Description: this function is used to send command to Lcd
 *              (ex: clear command).
 *
 * Parameters: uint8 Command
 *
 * Return: void
 *
********************************************************************/
void Lcd_SendCommand(uint8 Command);
/*******************************************************************
 *
 * Function Name: Lcd_DisplayData.
 *
 * Description: this function is used to display charachter on Lcd
 *
 *
 * Parameters: uint8 Val
 *
 * Return: void
 *
********************************************************************/
void Lcd_DisplayData(uint8 Val);
/*******************************************************************
 *
 * Function Name: Lcd_DisplayCompleteNum.
 *
 * Description: this function is used to display Complete Number
 *              on Lcd
 *
 * Parameters: uint16 Copy_u16Num
 *
 * Return: void
 *
********************************************************************/
void Lcd_DisplayCompleteNum(uint16 Copy_u16Num);
/*******************************************************************
 *
 * Function Name: Lcd_DisplayString.
 *
 * Description: this function is used to display string on Lcd
 *
 * Parameters: char* String
 *
 * Return: void
 *
********************************************************************/
void Lcd_DisplayString(char* String);
/*******************************************************************
 *
 * Function Name: LCD_voidSetXYPosition.
 *
 * Description: this function is used to move cursor on lcd
 *              in certain places
 *
 * Parameters: uint8 Copy_u8XPosition,uint8 Copy_u8YPosition
 *
 * Return: void
 *
********************************************************************/
void LCD_voidSetXYPosition(uint8 Copy_u8XPosition,uint8 Copy_u8YPosition);
/*******************************************************************
 *
 * Function Name: Show_Timer_Value.
 *
 * Description: this function is used to show timer values on lcd.
 *
 * Parameters: uint8 Min_Value,uint8 Sec_Value
 *
 * Return: void
 *
********************************************************************/
void Show_Timer_Value(uint8 Min_Value,uint8 Sec_Value);

#endif /* LCD_H_ */

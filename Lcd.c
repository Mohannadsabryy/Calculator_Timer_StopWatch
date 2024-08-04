/*
 *
 *  File Name: Lcd.c
 *
 *  Created on: Jun 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 */
/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/
/* Include std_types file */
#include "std_types.h"

/* Include tm4c123gh6pm_registers file */
#include "tm4c123gh6pm_registers.h"

/* Include BIT_MATH file */
#include "BIT_MATH.h"

/* Include Stack header file */
#include "Stack.h"

/* Include Delay file */
#include "Delay.h"

/* Include Lcd header file */
#include "Lcd.h"

/* Include Lcd Configuration file */
#include "Lcd_Config.h"
/*=========================================================================================================================================
                                                    Global Variables
=========================================================================================================================================*/

Stack stack;

/*=========================================================================================================================================
                                                    Api's Definitions
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
void Lcd_Init(void){
    Delay_MS(VDD_DELAY);
    Lcd_SendCommand(FUNCTION_SET_COMMAND);
    Lcd_SendCommand(DISPLAY_COMMAND);
    Lcd_SendCommand(CLEAR_COMMAND);
}

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
void Lcd_SendCommand(uint8 Command){
    CLR_BIT(GPIO_PORTA_DATA_REG,RS_PIN);
    CLR_BIT(GPIO_PORTA_DATA_REG,RW_PIN);
    GPIO_PORTB_DATA_REG &= 0x00;
    GPIO_PORTB_DATA_REG |= Command;
    SET_BIT(GPIO_PORTA_DATA_REG,E_PIN);
    Delay_MS(2);
    CLR_BIT(GPIO_PORTA_DATA_REG,E_PIN);
}

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
void Lcd_DisplayData(uint8 Val){
    SET_BIT(GPIO_PORTA_DATA_REG,RS_PIN);
    CLR_BIT(GPIO_PORTA_DATA_REG,RW_PIN);
    GPIO_PORTB_DATA_REG &= 0x00;
    GPIO_PORTB_DATA_REG |= Val;
    SET_BIT(GPIO_PORTA_DATA_REG,E_PIN);
    Delay_MS(2);
    CLR_BIT(GPIO_PORTA_DATA_REG,E_PIN);
}
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
void Lcd_DisplayCompleteNum(uint16 Copy_u16Num){
    uint8 result,value;
    init(&stack);
    while(Copy_u16Num!=0){
        result=Copy_u16Num % 10;
        Copy_u16Num=Copy_u16Num/10;
        push(result,&stack);
    }
    while( isempty(&stack) == FALSE ){
        value=pop(&stack);
        Lcd_DisplayData(value+'0');
    }
}
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
void Lcd_DisplayString(char* String){
    while(*String!='\0'){
        Lcd_DisplayData(*String);
        String++;
    }
}
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
void LCD_voidSetXYPosition(uint8 Copy_u8XPosition,uint8 Copy_u8YPosition){
    uint8 Local_u8Address;
    if(Copy_u8YPosition==0){
        Local_u8Address=Copy_u8XPosition;
    }
    else{
        Local_u8Address=Copy_u8XPosition+0x40;
    }

    SET_BIT(Local_u8Address,7);

    Lcd_SendCommand(Local_u8Address);
}

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
void Show_Timer_Value(uint8 Min_Value,uint8 Sec_Value){
    if(Min_Value<10){
        LCD_voidSetXYPosition(0, 0);
        Lcd_DisplayData('0');
        LCD_voidSetXYPosition(1, 0);
        Lcd_DisplayData(Min_Value+'0');
    }
    else{
        LCD_voidSetXYPosition(0, 0);
        Lcd_DisplayCompleteNum(Min_Value);
    }
    if(Sec_Value<10){
        LCD_voidSetXYPosition(3, 0);
        Lcd_DisplayData('0');
        LCD_voidSetXYPosition(4, 0);
        Lcd_DisplayData(Sec_Value+'0');
    }
    else{
        LCD_voidSetXYPosition(3, 0);
        Lcd_DisplayCompleteNum(Sec_Value);
    }
}



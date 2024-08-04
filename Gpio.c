/*
 *  File Name:Gpio.c
 *
 *  Created on: Jun 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 *  MC:TM4C123GH6PM
*/
/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include tm4c123gh6pm_registers file */
#include "tm4c123gh6pm_registers.h"

/* Include Gpio header file */
#include "Gpio.h"

/*=========================================================================================================================================
                                                    Api's Definitions
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
void LcdDataPins(void){
    GPIO_PORTB_DATA_REG  &=0x00;
    GPIO_PORTB_DIR_REG   |= 0xFF;
    GPIO_PORTB_DEN_REG   |= 0xFF;
    GPIO_PORTB_AFSEL_REG &= 0x00;
    GPIO_PORTB_PCTL_REG  &= 0x00000000;
}
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
void Lcd_CtrlPins(void){
    GPIO_PORTA_DATA_REG   &= 0x1F;
    GPIO_PORTA_DIR_REG    |= 0xE0;
    GPIO_PORTA_DEN_REG    |= 0xE0;
    GPIO_PORTA_AFSEL_REG  &= 0x1F;
    GPIO_PORTA_PCTL_REG   &= 0x000FFFFF;
}

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
void KepadPinsInit(void){
    GPIO_PORTC_DIR_REG &= 0x0F;
    GPIO_PORTC_DEN_REG |= 0xF0;
    GPIO_PORTC_PUR_REG |= 0xF0;
    GPIO_PORTC_AFSEL_REG &=0x0F;
    GPIO_PORTC_PCTL_REG &=0x0000FFFF;

    GPIO_PORTE_DIR_REG |= 0x0F;
    GPIO_PORTE_DEN_REG |= 0x0F;
    GPIO_PORTE_AFSEL_REG &=0xF0;
    GPIO_PORTE_PCTL_REG &=0xFFFF0000;
    GPIO_PORTE_DATA_REG |= 0x0F;
}
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
void PushButtonInit(void){
    GPIO_PORTF_DIR_REG   &= ~(1<<4);
    GPIO_PORTF_AFSEL_REG &= ~(1<<4);
    GPIO_PORTF_DEN_REG   |=   1<<4;
    GPIO_PORTF_PUR_REG   |=   1<<4;
    GPIO_PORTF_PCTL_REG  &= 0xFFF0FFFF;

    GPIO_PORTF_IS_REG    &= ~(1<<4);
    GPIO_PORTF_IBE_REG   &= ~(1<<4);
    GPIO_PORTF_IEV_REG   &= ~(1<<4);
    GPIO_PORTF_IM_REG    |=  (1<<4);

    NVIC_EN0_REG |= 1<<30;
    NVIC_PRI7_REG |= (1<<21);
}
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
void GPIO_BLUE_LED(void){
    GPIO_PORTF_DIR_REG |= 1<<2;
    GPIO_PORTF_DEN_REG |= 1<<2;
    GPIO_PORTF_AFSEL_REG &= ~(1<<2);
    GPIO_PORTF_PCTL_REG &= 0xFFFFF0FF;
}
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
void GPIO_Turn_Blue_Led_On(void){
    GPIO_PORTF_DATA_REG |= 1<<2; /* turn on led */
}
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
void GPIO_Turn_Blue_Led_Off(void){
    GPIO_PORTF_DATA_REG &= ~(1<<2); /* turn off led */
}

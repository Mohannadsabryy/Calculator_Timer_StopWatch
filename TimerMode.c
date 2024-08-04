/*
 *  File Name: TimerMode.c
 *
 *  Created on: Jun 26, 2024
 *
 *  Author: Mohannad Sabry
 *
*/
/*=========================================================================================================================================
                                                    Includes
=========================================================================================================================================*/

/* Include std_types file */
#include "std_types.h"

/* Include TimerMode header file */
#include "TimerMode.h"

/* Include Lcd header file */
#include "Lcd.h"

/* Include keypad header file*/
#include "Keypad.h"

/* Inlcude header file of Led */
#include "Led.h"

/* Include Systick Interface header file */
#include "SystickIF.h"

/*=========================================================================================================================================
                                                    Global Variables
=========================================================================================================================================*/

/* Min_Value variable that is used to store minutes value inside it */
uint8 Min_Value;

/* Sec_Value variable that is used to store minutes value inside it */
uint8 Sec_Value;

/* is_displayed is a flag that used to display timer app on screen */
uint8 is_displayed=FALSE;

/* Timer_Flag is set every 1 sec by systick handler when systick elapsed. */
uint8 Timer_Flag=FALSE;

/*=========================================================================================================================================
                                                    Api's Definitions
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

void Reset_Timer_Handle(void){
    stop_timer(); /* stop systick timer */
    Led_Off(); /* turn off blue led */
    is_displayed=FALSE; /* clear is_displayed flag */
    Min_Value=0; /* clear minutes value */
    Sec_Value=0; /* clear seconds value */
}

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
void Timer_Mode_App(void){
    sint16 Key_Value=GetKeyPressed(); /* Get key pressed */

    /* check if timer app is not displayed */
    if(is_displayed==FALSE){
        Lcd_SendCommand(CLEAR_COMMAND); /* clear Lcd screen */
        Lcd_DisplayString("Min:"); /* display minutes string */
        LCD_voidSetXYPosition(7, 0); /* move cursor right 7 places */
        Lcd_DisplayString("Sec:"); /* display seconds string*/
        is_displayed=TRUE; /* set is_displayed flag */
    }
    else{
        /* Do nothing misra c rule */
    }

    /* switch on key_value to take specfic action */
    switch(Key_Value){
        case MIN_BTN:
            Min_Value++; /* increment min value */
            LCD_voidSetXYPosition(4, 0); /* move cursor 4 places right */
            Lcd_DisplayCompleteNum(Min_Value); /* display minutes value */
            break;

        case SEC_BTN:
            Sec_Value++; /* increment seconds value */
            LCD_voidSetXYPosition(11, 0); /* move cursor 11 places right */
            Lcd_DisplayCompleteNum(Sec_Value); /* display seconds value */
            break;
        case RESET_BTN:
            Reset_Timer_Handle(); /* clear timer values and stop timer */
            break;
        case START_TIMER_BTN:
            Lcd_SendCommand(CLEAR_COMMAND); /* clear screen */
            Lcd_DisplayString("00:00"); /* display 00:00 on screen */
            Sec_Value!=0?Show_Timer_Value(Min_Value,Sec_Value):Show_Timer_Value(--Min_Value,Sec_Value=59); /* show timer values on screen */
            start_timer(); /* start timer */
            break;
    }

    /* check if flag set by systick handler */
    if(Timer_Flag==TRUE){
        Timer_Flag=FALSE; /* clear flag */
        Sec_Value--; /* decrement seconds value by 1 */
        Show_Timer_Value(Min_Value,Sec_Value); /* show timer values on screen */
        /* check if seconds value is equal to zero and minutes not equal to zero */
        if((Sec_Value==0 && Min_Value!=0)){
            Min_Value--;  /* decrement minutes value by 1 */
            Sec_Value=60; /* set seconds value by 60 */
        }
        /* check if timer finished */
        else if( (Min_Value==0 && Sec_Value==0) ){
            Led_On(); /* turn on blue led */
            stop_timer(); /* stop systick timer */
        }
        else{
            /* Do nothing misra c rule */
        }
    }
    else{
        /* Do nothing misra c rule */
    }

}



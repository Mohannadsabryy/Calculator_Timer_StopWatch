/*
 *  File name:StopWatch.c
 *
 *  Created on: Jul 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include Std_types file */
#include "std_types.h"

/* Include stopwatch header file */
#include "StopWatch.h"

/* Include Lcd header file */
#include "Lcd.h"

/* Include keypad header file */
#include "Keypad.h"

/* Include Gptm Interface header file */
#include "GptmIF.h"

/*=========================================================================================================================================
                                                    Global Variables
=========================================================================================================================================*/

/* Is_StopWatch_Displayed flag used to control display of stopwatch on lcd */
uint8 Is_StopWatch_Displayed=FALSE;

/* Gptm flag is set every 1 sec when gptm timer elapsed */
uint8 Gptm_Flag=FALSE;

/*
 *
 * Sec_Val variable that stores inside it value of seconds.
 * Min_Val variable that stores inside it value of minutes.
 *
*/
uint8 Sec_Val=ZERO,Min_Val=ZERO;

/*=========================================================================================================================================
                                                    Functions Definitions
=========================================================================================================================================*/

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
void Reset_StopWatch(void){
    Stop_StopWatch_Timer(); /* Stop gptm timer */
    Is_StopWatch_Displayed=FALSE; /* reset Is_StopWatch_Displayed flag */
    Sec_Val=ZERO; /* clear seconds variable */
    Min_Val=ZERO; /* clear minutes variable */
    Gptm_Flag=FALSE; /* clear gptm flag */
}

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
void StopWatch_App(void){
    /* Get key pressed */
    sint16 Key_Value=GetKeyPressed();

    if(Is_StopWatch_Displayed==FALSE){ /* check if stopwatch app is not displayed on screen */
        Lcd_SendCommand(CLEAR_COMMAND); /* clear Lcd screen */
        Lcd_DisplayString("00:00"); /* display 00:00 on screen */
        Is_StopWatch_Displayed=TRUE; /* SET Is_StopWatch_Displayed flag */
    }
    else{
        /* Do nothing misra c rule */
    }

    /* switch on key_value */
    switch(Key_Value){
        case START_BTN:
            Start_StopWatch_Timer(); /* start timer */
            break;
        case RESET_BTN:
            Reset_StopWatch(); /* reset timer */
            break;
        case STOP_BTN:
            Stop_StopWatch_Timer(); /* stop timer */
            break;
    }

    /* check if Gptm_flag is set */
    if(Gptm_Flag==TRUE){
        Gptm_Flag=FALSE; /* clear flag */
        Sec_Val++; /* increment second value by 1 */
        if(Sec_Val==60){ /* check if sec_val==60 in order to reset seconds */
            Min_Val++;  /* increment minutes value by 1 */
            Sec_Val=ZERO; /* reset second value */
        }
        Show_Timer_Value(Min_Val, Sec_Val); /* show minutes and seconds on screen */
    }
    else{
        /* Do nothing misra c rule */
    }
}





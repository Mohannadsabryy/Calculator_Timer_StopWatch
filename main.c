/*
 *
 * Author: Mohannad Sabry
 *
 * File Name: main.c
 *
 * MC:TM4C123GH6PM
 *
*/
/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Include tm4c123gh6pm_registers file */
#include "tm4c123gh6pm_registers.h"

/* Include main header file */
#include "main.h"

/* Include gpio driver header file */
#include "Gpio.h"

/* Include Gptm driver header file */
#include "Gptm.h"

/* Include Lcd driver header file */
#include "Lcd.h"

/* Include keypad driver header file */
#include "Keypad.h"

/* Include Calculator app header file */
#include "Calculator_App.h"

/* Include Timer app header file */
#include "TimerMode.h"

/* Include StopWatch app header file */
#include "StopWatch.h"

/*=========================================================================================================================================
                                                    Global Variables
=========================================================================================================================================*/

/* Exti_Flag this is a flag that will be set by external interrupt handler when interrupt occurs */
uint8 Exti_Flag;

/* this variable holdes the mode selected by user */
uint8 Mode;

/* Main Flags
 * Is_Modes_Displayed:this flag is set when modes of application is displayed
 * Is_Mode_Selected: this flag is set when
*/
typedef struct{
    uint8 Is_Modes_Displayed:1;
    uint8 Is_Mode_Selected:1;
}Main_Flags;
Main_Flags Flag;

/*=========================================================================================================================================
                                                    Main Function
=========================================================================================================================================*/
void main(void)
{
    SYSCTL_RCGCGPIO_REG |= CLK_VALUE; /* enable gpio peripheral clk */
    SYSCTL_RCGCTIMER_REG |= TIMER_CLK_VAL; /* enable gptm preiphral clk */
    while( !(SYSCTL_PRGPIO_REG & CLK_VALUE) ); /* wait until clk is set */
    Global_Interrupt_Enable(); /* Enable global interrupts */
    PushButtonInit(); /* Enable pushButton */
    LcdDataPins(); /* Configure Lcd data pins */
    Lcd_CtrlPins(); /* Configure Lcd Ctrl pins */
    Lcd_Init(); /* Enable Lcd */
    KepadPinsInit(); /* Enable Keypad */
    Gptm_Init(); /* Configure Gptm timer */
    while(TRUE){
        if(Flag.Is_Modes_Displayed==FALSE){ /* check if modes displayed */
            Lcd_SendCommand(CLEAR_COMMAND); /* clear Lcd */
            Lcd_DisplayString("Pick:1.C 2.T 3.S"); /* display modes on lcd */
            Flag.Is_Modes_Displayed=TRUE; /* set Is_Modes_Displayed flag */
        }
        else{
            /* Do nothing misra rule */
        }

        if(Exti_Flag==TRUE){ /* check if exti_flag is set */
            Flag.Is_Modes_Displayed=FALSE; /* clear Is_Modes_Displayed flag */
            Flag.Is_Mode_Selected=FALSE;/* clear Is_Mode_Selected flag */
            Mode == CALCULATOR_MODE ? Clear_Operation_Handle() :  Mode == TIMER_MODE ?  Reset_Timer_Handle():Reset_StopWatch(); /* handle reset operation */
            Mode = NOTHING; /* reset mode */
            Exti_Flag=FALSE; /* clear Exti_Flag */
        }
        else{
            /* Do nothing misra rule */
        }

        if(Flag.Is_Mode_Selected==FALSE){ /* check if mode is not selected */
            Mode=GetKeyPressed(); /* select a certain mode or nothing if user doesn't press anything */
        }
        else{
            /* do nothing misra c rule */
        }

        switch(Mode){ /* switch to selected mode or nothing */
            case CALCULATOR_MODE:
                Flag.Is_Mode_Selected=TRUE; /* set Is_Mode_Selected flag */
                Calculator_Init();/* call calculator App */
                break;
            case TIMER_MODE:
                Flag.Is_Mode_Selected=TRUE; /* set Is_Mode_Selected flag */
                GPIO_BLUE_LED(); /* Configure Blue Led */
                Timer_Mode_App();/* call timerMode App */
                break;
            case STOPWATCH_MODE:
                Flag.Is_Mode_Selected=TRUE; /* set Is_Mode_Selected flag */
                StopWatch_App(); /* call stopWatch App */
                break;
        }
    }
}


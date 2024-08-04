/*
 *  File Name:Keypad.c
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

/* Include Delay file */
#include "Delay.h"

/* Include System file */
#include "Keypad.h"

/* Include Keypad Configuration file */
#include "Keypad_Config.h"

/*=========================================================================================================================================
                                                    Api's Definitions
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: GetKeyPressed.
 *
 * Description: this function is used to return the button pressed
 *
 * Parameters: void
 *
 * Return: uint8
 *
********************************************************************/
uint8 GetKeyPressed(void){
    /* 2d-array of keypad values */
    uint8 Key_Pad_Values[4][4]={
                                {0,1,2,3},
                                {4,5,6,7},
                                {8,9,10,11},
                                {12,13,14,15}
                               };
    uint8 result=255; /* dummy value stored in result */
    sint8 is_found=-1; /* flag that shows if there is button pressed or not*/
    uint8 col,row; /* col represent each column in keypad and row represent each row in keypad */

    /* this loop to iterate through each button in keypad and return button number if it pressed*/
    for(col=0;col<4;col++){
        CLR_BIT(COMMON_COLUMN_PORT,col);
        for(row=0;row<4;row++){
            if(GET_BIT(COMMON_ROW_PORT,row+4)==Pressed){
                result=Key_Pad_Values[row][col];
                is_found=1;
                /* Delay for bouncing */
                Delay_MS(2);
                while(GET_BIT(COMMON_ROW_PORT,row+4)==Pressed){
                }
                break;
            }
        }
        if(is_found==TRUE){
            return result;
        }
        else{
            SET_BIT(COMMON_COLUMN_PORT,col);
        }
    }
    return result;
}



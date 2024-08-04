/*
 *  File Name:Calculator_App.c
 *
 *  Created on: Jun 25, 2024
 *
 *  Author: Mohannad Sabry
 *
*/

/*=========================================================================================================================================
                                                    Include files
=========================================================================================================================================*/

/* Inlcude std_types.h file */
#include "std_types.h"

/* Include Calculator_App.h file */
#include "Calculator_App.h"

/* Include Lcd.h file */
#include "Lcd.h"

/* Include keypad.h file */
#include "Keypad.h"

/*=========================================================================================================================================
                                                    Global Variables
=========================================================================================================================================*/

/*
 *
 * Num1 holds the value of the first variable.
 * Num2 holds the value of the second variable.
 *
*/
sint16 Num1,Num2;

/* Op variable that stores the operation(*,/,+,-) of the expression */
char Op;


/* this struct contains all flags of the calculator app.
 *
 * Is_Num1_Set flag ensures that Num1 is completely set with value.
 * Is_Num2_Set flag ensures that Num2 is completely set with value.
 * Is_Displayed flag ensures calculator app appears on lcd.
 * IS_NUM1_NEGATIVE flag ensures that num1 is negative or not.
 * IS_NUM2_NEGATIVE flag ensures that num2 is negative or not.
 * IS_Num1_Written flag ensures that num1 was written inside it but not set yet.
 * Is_Op_Set flag ensures that operation was set or not
 *
 * */
typedef struct{
    unsigned char Is_Num1_Set:1;
    unsigned char Is_Num2_Set:1;
    unsigned char Is_Displayed:1;
    unsigned char IS_NUM1_NEGATIVE:1;
    unsigned char IS_NUM2_NEGATIVE:1;
    unsigned char IS_Num1_Written:1;
    unsigned char Is_Op_Set:1;
}Calculator_Flags;

Calculator_Flags Flags;

/*=========================================================================================================================================
                                                    Api's Definitions
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Clear_Operation_Handle.
 *
 * Description: this function is used to handle clear operation when
 *              we clicked on clear button in order to reset the
 *              values that was stored in Num1,Num2,op and clear
 *              flags also.
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Clear_Operation_Handle(void){
    Num1=ZERO; /* clear value stored in Num1 */
    Flags.Is_Num1_Set=FALSE; /* Reset Is_Num1_Set flag this now indicates that Num1 is not set yet */
    Flags.IS_Num1_Written=FALSE; /* Reset IS_Num1_Written flag this now indicates that Num1 written inside it */
    Num2=ZERO; /* clear value stored in Num2 */
    Flags.Is_Num2_Set=FALSE; /* Reset Is_Num2_Set flag this now indicates that Num2 is not set yet */
    Op=ZERO; /* clear op value */
    Flags.Is_Displayed=FALSE; /* clear Is_Displayed flag */
    Flags.IS_NUM1_NEGATIVE=FALSE; /* clear IS_NUM1_NEGATIVE flag */
    Flags.IS_NUM2_NEGATIVE=FALSE; /* clear IS_NUM2_NEGATIVE flag */
    Flags.Is_Op_Set=FALSE; /* clear Is_Op_Set flag */
    Lcd_SendCommand(CLEAR_COMMAND); /* clear the values that shown on lcd */
}

/************************************************************************************
 *
 * Function Name: Store_Result_Handle.
 *
 * Description: this function is used to store the result after pressing on equal btn
 *              in order to if we want to make a certain operation on the result value.
 *
 * Parameters: sint16 val: result value that will be stored in Num1.
 *
 * Return: void
 *
*************************************************************************************/
void Store_Result_Handle(sint16 val){
    Num1=val; /* store result value in Num1 */
    Flags.Is_Num1_Set=TRUE; /* set Is_Num1_Set flag */
    Num2=ZERO; /* clear Num2 value */
    Flags.Is_Num2_Set=FALSE; /* Reset Is_Num2_Set flag */
    Flags.IS_NUM1_NEGATIVE=FALSE; /* Reset IS_NUM1_NEGATIVE flag */
    Flags.IS_NUM2_NEGATIVE=FALSE; /* Reset IS_NUM2_NEGATIVE flag */
    Flags.Is_Op_Set=FALSE; /* Reset Is_Op_Set flag */
}

/************************************************************************************
 *
 * Function Name: Calculator_Init.
 *
 * Description: This function is used to make the expression that will be calculated.
 *
 * Parameters: void
 *
 * Return: void
 *
*************************************************************************************/
void Calculator_Init(void){
    sint16 Key_Value=GetKeyPressed(); /* Get the pressed key value */
    if( Flags.Is_Displayed==FALSE){
        Lcd_SendCommand(CLEAR_COMMAND); /* Clear the Screen in order to display calculator screen */
        Lcd_DisplayString("Expr:"); /* Display Expr: string */
        Flags.Is_Displayed=TRUE; /* Set Is_Displayed flag */
    }
    else{
        /* Do nothing misra c rule */
    }

    /* if key value between 0 and 9 and num1 is not set yet so that the value that user enters for the first value in the expression */
    if( (Key_Value>=0 && Key_Value<=9) && ( Flags.Is_Num1_Set==FALSE)  ){
        Num1=Num1*10+Key_Value; /* store value in Num1 */
        Lcd_DisplayData(Key_Value+'0'); /* display Num1 value */
        Flags.IS_Num1_Written=TRUE; /* set IS_Num1_Written flag this means that num1 is written inside it but not set yet. */
    }
    /* this condition checks if that first number is negative */
    else if( (Key_Value==MINUS_OP) && ( Flags.Is_Num1_Set == FALSE) && ( Flags.IS_Num1_Written==FALSE) ){
        Flags.IS_NUM1_NEGATIVE=TRUE; /* set IS_NUM1_NEGATIVE flag */
        Lcd_DisplayData('-');  /* Display negative sign on Lcd */
    }
    /* check if keypressed is (+,-,*,/) then we will store operation and this means that num1 is set finally */
    else if( (Key_Value>=PLUS_OP && Key_Value<EQUAL_OP) && (  Flags.Is_Op_Set == FALSE ) ){
        Flags.Is_Num1_Set=TRUE; /* set Is_Num1_Set flag */
        Flags.Is_Op_Set=TRUE;  /* set Is_Op_Set flag */
        Op=Key_Value;   /* store the operation in op */
        /* Show operation on the screen */
        Key_Value==PLUS_OP ? Lcd_DisplayData('+'): Key_Value==MINUS_OP?Lcd_DisplayData('-'):Key_Value==MULT_OP?Lcd_DisplayData('*'):Lcd_DisplayData('/') ;
    }
    /* check after setting the op if the next keypressed is Minus_Op this means that num2 is negative number */
    else if( (Key_Value==MINUS_OP) && ( Flags.Is_Num2_Set == FALSE) ){
            Flags.IS_NUM2_NEGATIVE=TRUE; /* set IS_NUM2_NEGATIVE flag */
            Lcd_DisplayData('-'); /* Display negative sign on Lcd */
    }
    /* if key value between 0 and 9 and num2 is not set yet so that the value that user enters for the second value in the expression */
    else if( (Key_Value>=0 && Key_Value<=9) && ( Flags.Is_Num2_Set==FALSE) ){
        Num2=Num2*10+Key_Value; /* store the second value in Num2 variable */
        Lcd_DisplayData(Key_Value+'0'); /* Display num2 on screen */
    }
    /* check if the key pressed is EQUAL_OP */
    else if( Key_Value==EQUAL_OP ){
        Flags.Is_Num2_Set=TRUE; /* set Is_Num2_Set flag */
        Num1= Flags.IS_NUM1_NEGATIVE ? Num1*-1:Num1; /* if IS_NUM1_NEGATIVE is set this means that num1 is negative else it is positive value */
        Num2= Flags.IS_NUM2_NEGATIVE ? Num2*-1:Num2; /* if IS_NUM2_NEGATIVE is set this means that num2 is negative else it is positive value */
        Calculator(Num1,Num2,Op); /* Calculate the result of expression */
    }
    /* check if the key pressed is the clear button */
    else if(Key_Value==CLEAR_OP){
        Clear_Operation_Handle(); /* Handle clear operation */
    }
    else{
        /* Do nothing misra c rule */
    }

}

/************************************************************************************
 *
 * Function Name:Calculator
 *
 * Description: This function was used to calculate result of expression.
 *
 * Parameters: sint16 First_Num,sint16 Second_Num,uint8 Operation.
 *
 * Return: void
 *
*************************************************************************************/
void Calculator(sint16 First_Num,sint16 Second_Num,uint8 Operation){
    /* variable that will store inside it the result of the expression */
    sint16 result;

    /* calculate the result */
    switch(Operation){
        case PLUS_OP:
            result=First_Num + Second_Num;
            break;
        case MINUS_OP:
            result=First_Num - Second_Num;
            break;
        case MULT_OP:
            result= First_Num * Second_Num;
            break;
        case DIV_OP:
            result= First_Num / Second_Num;
            break;
    }

    Lcd_SendCommand(CLEAR_COMMAND); /* clear screen in order to display result */
    Store_Result_Handle(result); /* store the result value */

    /* check if result less than 0 */
    if(result<ZERO){
        Lcd_DisplayData('-'); /* display negative sign */
        result*=-1; /* change number into a positive number */
        Lcd_DisplayCompleteNum(result); /* diplay num */
    }
    /* check if result is equal to zero */
    else if(result==ZERO){
        Lcd_DisplayData(ZERO+'0'); /* display zero value */
    }
    /* check if result is positive number */
    else{
        Lcd_DisplayCompleteNum(result); /* display result on screen */
    }
}

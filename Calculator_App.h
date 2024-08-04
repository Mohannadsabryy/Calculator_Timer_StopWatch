/*
 *  File Name:Calculator_App.h
 *
 *  Created on: Jun 25, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef CALCULATOR_APP_H_
#define CALCULATOR_APP_H_

/*=========================================================================================================================================
                                                    Macros and Enums
=========================================================================================================================================*/

#define ZERO 0

/*
 * Enumeration that contains all operations
*/
typedef enum{
    PLUS_OP=10,
    MINUS_OP,
    MULT_OP,
    DIV_OP,
    EQUAL_OP,
    CLEAR_OP
}Operations;

/*=========================================================================================================================================
                                                    Functions Prototypes
=========================================================================================================================================*/

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
void Calculator_Init(void);


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
void Calculator(sint16 First_Num,sint16 Second_Num,uint8 Operation);


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
void Clear_Operation_Handle(void);


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
void Store_Result_Handle(sint16 val);


#endif /* CALCULATOR_APP_H_ */

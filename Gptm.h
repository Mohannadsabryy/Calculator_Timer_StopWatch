/*
 *  File Name: Gptm.h
 *
 *  Created on: Jul 24, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef GPTM_H_
#define GPTM_H_
/*=========================================================================================================================================
                                                    Functions Prototypes
=========================================================================================================================================*/

/*******************************************************************
 *
 * Function Name: Gptm_Init.
 *
 * Description: this function is used to initialize gptm timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Gptm_Init(void);
/*******************************************************************
 *
 * Function Name: Start_Gptm_Timer.
 *
 * Description: this function is used to start gptm timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Start_Gptm_Timer(void);
/*******************************************************************
 *
 * Function Name: Stop_Gptm_Timer.
 *
 * Description: this function is used to stop gptm timer
 *
 * Parameters: void
 *
 * Return: void
 *
********************************************************************/
void Stop_Gptm_Timer(void);

#endif /* GPTM_H_ */

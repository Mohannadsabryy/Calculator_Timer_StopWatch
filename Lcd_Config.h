/*
 *
 * File Name: Lcd_Config.h
 *
 * Created on: Jun 24, 2024
 *
 * Author: Mohannad Sabry
 *
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*=========================================================================================================================================
                                                   Macors
=========================================================================================================================================*/
#define VDD_DELAY 35 /* VDD_DELAY Value */
#define FUNCTION_SET_COMMAND 0b00111000 /* Function Set command */
#define DISPLAY_COMMAND      0b00001100 /* Display on lcd command */
#define CLEAR_COMMAND        0b00000001 /* Clear command */
#define RS_PIN                  5 /* Number of RS_PIN in it's port */
#define RW_PIN                  6 /* Number of RW_PIN in it's port */
#define E_PIN                   7 /* Number of E_PIN in it's port */

#endif /* LCD_CONFIG_H_ */

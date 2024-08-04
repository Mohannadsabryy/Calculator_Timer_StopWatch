/*
 *  File Name:BIT_MATH.h
 *
 *  Created on: Feb 3, 2024
 *
 *  Author: Mohannad Sabry
 *
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Function Like Macro to set bit value */
#define SET_BIT(var,bit_num) var|=1<<bit_num

/* Function Like Macro to clear bit value */
#define CLR_BIT(var,bit_num) var&=(~(1<<bit_num))

/* Function Like Macro to toggle bit value */
#define TOGGLE_BIT(var,bit_num) var^=(1<<bit_num)

/* Function Like Macro to get bit value */
#define GET_BIT(var,bit_num) ((var>>bit_num)&1)

#endif /* BIT_MATH_H_ */

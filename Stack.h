/*
 * Stack.h
 *
 *  Created on: Jun 25, 2024
 *      Author: user
 */

#ifndef STACK_H_
#define STACK_H_

#define MAX_SIZE 30
#define DATA_TYPE int


typedef struct{
    DATA_TYPE elements[MAX_SIZE];
    int top;
}Stack;

void init(Stack *s);
int isFull(Stack *s);
int isempty(Stack *s);
int push(DATA_TYPE element,Stack *s);
int pop(Stack *s);
int stack_size(Stack *s);
void clearStack(Stack *s);


#endif /* STACK_H_ */

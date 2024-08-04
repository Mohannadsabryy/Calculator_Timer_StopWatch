/*
 * Stack.c
 *
 *  Created on: Jun 25, 2024
 *      Author: user
 */

#include "std_types.h"
#include "Stack.h"


void init(Stack *s){
    s->top=-1;
}
int isFull(Stack *s){
    if(s->top==MAX_SIZE-1){
            return 1;
    }
    else{
        return 0;
    }
}
int isempty(Stack *s){
    if(s->top==-1){
            return 1;
    }
    else{
        return 0;
    }
}
int push(DATA_TYPE element,Stack *s){
    if(isFull(s)==0){
        s->top++;
        s->elements[s->top]=element;
        return 1;
    }
    else{
        return 0;
    }
}
int pop(Stack *s){
    if(isempty(s)==0){
        int element=s->elements[s->top];
        s->top--;
        return element;
    }
    else{
        return 0;
    }
}
int stack_size(Stack *s){
    return s->top+1;
}
void clearStack(Stack *s){
    s->top=-1;
}


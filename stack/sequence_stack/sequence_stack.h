#ifndef SEQUENCE_STACK_H
#define SEQUENCE_STACK_H

#include "../../common/status.h"

#define STACK_INIT_SIZE 5
#define STACK_INCREMENT 3

typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack_Sq(SqStack &);

Status DestroyStack_Sq(SqStack &);

Status ClearStack_Sq(SqStack &);

Status StackEmpty_Sq(SqStack);

int StackLength_Sq(SqStack);

Status GetTop_Sq(SqStack, SElemType &);

Status Push_Sq(SqStack &, SElemType);

Status Pop_Sq(SqStack &, SElemType &);

void StackTraverse_Sq(SqStack);

#endif
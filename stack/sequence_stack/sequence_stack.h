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

Status InitStack(SqStack &);

Status DestoryStack(SqStack &);

Status ClearStack(SqStack &);

Status StackEmpty(SqStack);

int StackLength(SqStack);

Status GetTop(SqStack, SElemType &);

Status Push(SqStack &, SElemType);

Status Pop(SqStack &, SElemType &);

void StackTraverse(SqStack);

#endif
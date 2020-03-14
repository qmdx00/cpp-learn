#include <iostream>
#include "sequence_stack.h"

using namespace std;

Status InitStack(SqStack &S)
{
    
    return OK;
}

Status DestoryStack(SqStack &);

Status ClearStack(SqStack &);

Status StackEmpty(SqStack);

int StackLength(SqStack);

Status GetTop(SqStack, SElemType &);

Status Push(SqStack &, SElemType);

Status Pop(SqStack &, SElemType &);

Status StackTraverse(SqStack);
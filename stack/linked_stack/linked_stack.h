#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "../../common/status.h"

typedef int SElemType;

typedef struct SNode
{
    SElemType data;
    SNode *next;
} SNode, *LStack;

Status InitStack_L(LStack &, int);

Status GetTop_L(LStack, SElemType &);

Status Push_L(LStack &, SElemType);

Status Pop_L(LStack &, SElemType &);

Status StackEmpty_L(LStack);

int StackLength_L(LStack);

void StackTraverse_L(LStack, Status (*Visit)(SElemType));

Status DestroyStack_L(LStack &);

#endif
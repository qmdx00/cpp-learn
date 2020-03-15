#include <iostream>
#include "sequence_stack.h"

using namespace std;

Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestoryStack(SqStack &S)
{
    free(S.base);
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    int length = 0;
    if (S.top == S.base)
        return 0;
    while (S.top != S.base)
    {
        length++;
        S.top--;
    }
    return length;
}

Status GetTop(SqStack S, SElemType &ele)
{
    if (S.top == S.base)
        return ERROR;
    ele = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, SElemType ele)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, ((S.stacksize + STACK_INCREMENT) * sizeof(SElemType)));
        if (!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACK_INCREMENT;
    }
    *(S.top++) = ele;
    return OK;
}

Status Pop(SqStack &S, SElemType &ele)
{
    if (S.top == S.base)
        return ERROR;
    ele = *(--S.top);
    return OK;
}

void StackTraverse(SqStack S)
{
    if (S.base == S.top)
        cout << "top-> ]" << endl;
    int i = 1;
    cout << "top-> ";
    while (i < S.top - S.base)
    {
        cout << *(S.top - i) << ", ";
        ++i;
    }
    cout << *S.base << " ]" << endl;
}
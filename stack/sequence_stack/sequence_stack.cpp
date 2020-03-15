#include <iostream>
#include "sequence_stack.h"

using namespace std;

Status InitStack_Sq(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack_Sq(SqStack &S)
{
    free(S.base);
    S.stacksize = 0;
    return OK;
}

Status ClearStack_Sq(SqStack &S)
{
    S.top = S.base;
    return OK;
}

Status StackEmpty_Sq(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength_Sq(SqStack S)
{
    int length = 0;
    if (S.top == S.base)
        return 0;
    while (S.top != S.base)
    {
        ++length;
        --S.top;
    }
    return length;
}

Status GetTop_Sq(SqStack S, SElemType &ele)
{
    if (S.top == S.base)
        return ERROR;
    ele = *(S.top - 1);
    return OK;
}

Status Push_Sq(SqStack &S, SElemType ele)
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

Status Pop_Sq(SqStack &S, SElemType &ele)
{
    if (S.top == S.base)
        return ERROR;
    ele = *(--S.top);
    return OK;
}

void StackTraverse_Sq(SqStack S)
{
    if (S.base == S.top)
        cout << "top->[ ]" << endl;
    int i = 1;
    cout << "top->[ ";
    while (i < S.top - S.base)
    {
        cout << *(S.top - i) << ", ";
        ++i;
    }
    cout << *S.base << " ]" << endl;
}
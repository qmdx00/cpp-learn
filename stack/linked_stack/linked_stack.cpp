#include <iostream>
#include "linked_stack.h"

using namespace std;
Status InitStack_L(LStack &L, int n)
{
    L = (LStack)malloc(sizeof(SNode));
    L->next = NULL;
    L->data = 0;

    for (int i = n; i > 0; i--)
    {
        LStack p = (LStack)malloc(sizeof(SNode));
        cin >> p->data;
        p->next = L->next;
        L->next = p;
        // 栈长度加 1
        ++L->data;
    }

    return OK;
}

Status GetTop_L(LStack L, SElemType &ele)
{
    if (L->next == NULL)
        return ERROR;
    else
        ele = L->next->data;
    return OK;
}

Status Push_L(LStack &L, SElemType ele)
{
    LStack s = (LStack)malloc(sizeof(SNode));
    if (!s)
        exit(OVERFLOW);
    s->data = ele;
    s->next = L->next;
    L->next = s;

    ++L->data;
    return OK;
}

Status Pop_L(LStack &L, SElemType &ele)
{
    if (L->next == NULL)
    {
        return ERROR;
    }
    else
    {
        LStack p = L->next;
        ele = p->data;
        L->next = p->next;
        free(p);

        --L->data;
        return OK;
    }
}

Status StackEmpty_L(LStack L)
{
    if (L->next == NULL)
        return TRUE;
    else
        return FALSE;
}

int StackLength_L(LStack L)
{
    return L->data;
}

void StackTraverse_L(LStack L, Status (*Visit)(SElemType))
{
    LStack p = L->next;
    while (p)
    {
        Visit(p->data);
        p = p->next;
    }
}

Status DestroyStack_L(LStack &L)
{
    LStack p;
    while (L->next)
    {
        p = L->next;
        L->next = p->next;
        free(p);
        // 链表长度减 1
        --L->data;
    }
    free(L);

    return OK;
}
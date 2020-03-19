#include "sequence_list.h"
#include <iostream>

using namespace std;

Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList &L, int idx, ElemType ele)
{
    if (idx < 1 || idx > L.length + 1)
        return ERROR;

    if (L.length >= L.listsize)
    {
        // 扩容
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LIST_INCREMENT;
    }

    // 循环右移
    ElemType *q = &(L.elem[idx - 1]);
    for (ElemType *p = &(L.elem[L.length - 1]); p >= q; --p)
    {
        *(p + 1) = *p;
    }
    *q = ele;
    ++L.length;
    return OK;
}

Status ListDelete_Sq(SqList &L, int idx, ElemType &ele)
{
    if (idx < 1 || idx > L.length)
        return ERROR;

    // 指向第 idx 个元素的指针
    ElemType *p = &(L.elem[idx - 1]);
    ele = *p;
    // 循环左移
    ElemType *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
    {
        *(p - 1) = *p;
    }
    --L.length;
    return OK;
}

void ListTraverse_Sq(SqList L, Status (*Visit)(ElemType))
{
    for (int i = 0; i < L.length; i++)
    {
        Visit(L.elem[i]);
    }
}

Status DestroyList_Sq(SqList &L)
{
    delete[] L.elem;
    L.length = 0;
    L.listsize = 0;
    return OK;
}
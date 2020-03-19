#include "static_linked_list.h"
#include <iostream>

using namespace std;

void InitSpace_SL(SLinkList &space)
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAX_SIZE - 1].cur = 0;
}

int LocateElem_SL(SLinkList S, ElemType ele)
{
    // 获取链表中第一个值为 ele 的元素，返回位序，否则返回 0
    int i = S[0].cur;
    while (i && S[i].data != ele)
    {
        i = S[i].cur;
    }
    return i;
}

int ListLength_SL(SLinkList S, int k)
{
    int len = 0;
    int i = k;
    while (i)
    {
        i = S[i].cur;
        ++len;
    }
    return len;
}

Status ListInsert_SL(SLinkList &space, int &k, int idx, ElemType ele)
{
    if (idx < 1 || idx > ListLength_SL(space, k) + 1)
        return ERROR;

    if (idx == 1)
    {
        int p = k;
        int new_idx = Malloc_SL(space);
        space[new_idx].cur = p;
        space[new_idx].data = ele;
        k = new_idx;
        return OK;
    }

    int p = k;
    int new_idx = Malloc_SL(space);
    if (new_idx != 0)
    {
        space[new_idx].data = ele;
        for (int i = 1; i < idx - 1; i++)
        {
            p = space[p].cur;
        }
        space[new_idx].cur = space[p].cur;
        space[p].cur = new_idx;
        return OK;
    }

    return ERROR;
}

Status ListDelete_SL(SLinkList &space, int &k, int idx, ElemType &ele)
{
    if (idx < 1 || idx > ListLength_SL(space, k))
        return ERROR;

    if (idx == 1)
    {
        int p = k;
        k = space[p].cur;
        ele = space[p].data;
        Free_SL(space, p);
        return OK;
    }

    int p = k;
    for (int i = 1; i < idx - 1; i++)
    {
        p = space[p].cur;
    }

    int q = space[p].cur;
    space[p].cur = space[q].cur;
    ele = space[q].data;
    Free_SL(space, q);

    return OK;
}

int Malloc_SL(SLinkList &space)
{
    // 备用空间非空，返回分配的节点下标，否则返回 0
    int i = space[0].cur;
    if (space[0].cur != 0)
    {
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SL(SLinkList &space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void ListTraverse_SL(SLinkList S, int k, Status (*Visit)(ElemType))
{
    int p = k;
    while (p != 0)
    {
        Visit(S[p].data);
        p = S[p].cur;
    }
}
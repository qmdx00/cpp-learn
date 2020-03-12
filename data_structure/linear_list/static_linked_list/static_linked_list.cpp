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

int ListLength_SL(SLinkList S)
{
    int len = 0;
    int i = S[0].cur;
    while (i)
    {
        i = S[i].cur;
        ++len;
    }
    return len;
}

Status ListInsert_SL(SLinkList &space, int idx, ElemType ele)
{
    if (idx < 1 || idx > ListLength_SL(space) + 1) return ERROR;
    
    int p = space[0].cur;
    int new_idx = Malloc_SL(space);
    if (new_idx != 0)
    {
        space[new_idx].data = ele;
        for(int i = 1; i < idx; i++)
        {
            p = space[p].cur;
        }
        space[new_idx].cur = space[p].cur;
        space[p].cur = new_idx;
        return OK;
    }
    
    return ERROR;
}

Status ListDelete_SL(SLinkList &space, int idx, ElemType &ele)
{
    if (idx < 1 || idx > ListLength_SL(space)) return ERROR;
    
    int p = space[0].cur;

    for(int i = 1; i < idx; i++)
    {
        p = space[p].cur;
    }
    int q = space[p].cur;
    space[p].cur = space[q].cur;
    ele = space[p].data;
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

void ListTraverse_SL(SLinkList S)
{
    int p = S[0].cur;
    if (p == 0)
    {
        cout << "[ ]" << endl;
        return;
    }

    cout << "[ ";
    while (p != 0)
    {
        if (S[p].cur == 0)
            cout << S[p].data << " - " << S[p].cur << " - " << LocateElem_SL(S, S[p].data) << " ";
        else
            cout << S[p].data << " - " << S[p].cur << " - " << LocateElem_SL(S, S[p].data) << ", ";
        p = S[p].cur;
    }
    cout << "]" << endl;
}
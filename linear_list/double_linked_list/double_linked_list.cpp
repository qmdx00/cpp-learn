#include "double_linked_list.h"
#include <iostream>

using namespace std;
void CreateList_DuL(DuLinkList &L, int n)
{
    L = (DuLinkList)malloc(sizeof(DuLNode));
    L->next = L;
    L->prior = L;
    L->data = 0;

    for (int i = n; i > 0; i--)
    {
        DuLinkList p = (DuLinkList)malloc(sizeof(DuLNode));
        cin >> p->data;
        // 向头节点后插入新的节点
        p->next = L->next;
        p->prior = L;
        L->next->prior = p;
        L->next = p;
        // 链表长度加 1
        ++L->data;
    }
}

DuLinkList GetElemP_DuL(DuLinkList L, int idx)
{
    DuLinkList p = L->next;
    int i = 1;

    while (p && i < idx)
    {
        p = p->next;
        ++i;
    }

    if (!p || i > idx)
        return NULL;

    return p;
}

Status ListInsert_DuL(DuLinkList &L, int idx, ElemType ele)
{
    DuLinkList p, s;

    if (!(p = GetElemP_DuL(L, idx)))
        return ERROR;

    if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
        return ERROR;

    s->data = ele;

    // s 节点插入在 p 之前
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;

    // 链表长度加 1
    ++L->data;
    return OK;
}

Status ListDelete_DuL(DuLinkList &L, int idx, ElemType &ele)
{
    DuLinkList p;

    if (!(p = GetElemP_DuL(L, idx)))
        return ERROR;

    ele = p->data;

    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    // 链表长度减 1
    --L->data;
    return OK;
}

Status ClearList_DuL(DuLinkList &L)
{
    DuLinkList p;
    while (L->next != L)
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

void ListTraverse_DuL(DuLinkList L, Status (*Visit)(ElemType))
{
    DuLinkList p = L->next;
    while (p != L)
    {
        Visit(p->data);
        p = p->next;
    }
}

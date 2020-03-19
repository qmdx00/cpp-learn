#include "linked_list.h"
#include <iostream>

using namespace std;

void CreateList_L(LinkList &L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = 0;

    for (int i = n; i > 0; i--)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        cin >> p->data;
        p->next = L->next;
        L->next = p;
        // 链表长度加 1
        ++L->data;
    }
}

Status ListInsert_L(LinkList &L, int idx, ElemType ele)
{
    LinkList p = L;
    int i = 0;
    // 寻找第 idx-1 个节点(p 指向第idx个节点的前驱)
    while (p && i < idx - 1)
    {
        p = p->next;
        ++i;
    }

    // 不存在第 idx-1 个节点或者插入位置 idx 大于表长 +1
    if (!p || i > idx - 1)
        return ERROR;
    
    // 新建节点并插入
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = ele;
    s->next = p->next;
    p->next = s;
    // 链表长度加 1
    ++L->data;
    return OK;
}

Status ListDelete_L(LinkList &L, int idx, ElemType &ele)
{
    LinkList p = L;
    int i = 0;
    // p 指向第 idx 个节点的前驱
    while (p->next && i < idx - 1)
    {
        p = p->next;
        ++i;
    }

    // 不存在第 idx-1 个节点或者删除位置 idx 大于表长 +1
    if (!(p->next) || i > idx - 1)
        return ERROR;
    
    LinkList q = p->next;
    p->next = q->next;
    ele = q->data;
    free(q);
    // 链表长度减 1
    --L->data;
    return OK;
}

Status GetElem_L(LinkList L, int idx, ElemType &ele)
{
    LinkList p = L->next;
    int i = 1;
    // 寻找第idx个节点(p 指向第idx个节点)
    while (p && i < idx)
    {
        p = p->next;
        ++i;
    }
    
    // 第 idx 个节点不存在(p 为 null 或者链表长度小于 idx)
    if (!p || i < idx) return ERROR;

    ele = p->data;

    return OK;
}

void ListTraverse_L(LinkList L, Status (*Visit)(ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        Visit(p->data);
        p = p->next;
    }
}

Status ClearList_L(LinkList &L)
{
    LinkList p;
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
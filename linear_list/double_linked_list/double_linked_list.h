#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "../../common/status.h"

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

void CreateList_DuL(DuLinkList &, int);

// 获取第 i 个元素节点指针
DuLinkList GetElemP_DuL(DuLinkList, int);

// 在双向链表的第 i 个位置插入元素e
Status ListInsert_DuL(DuLinkList &, int, ElemType);

// 删除第 i 个位置的元素并由元素e返回其值
Status ListDelete_DuL(DuLinkList &, int, ElemType &);

// 清空链表
Status ClearList_DuL(DuLinkList &);

void ListTraverse_DuL(DuLinkList);

#endif
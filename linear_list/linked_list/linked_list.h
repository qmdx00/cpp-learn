#ifndef LINKED_LIST_H

#include "../../common/status.h"

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

// 带头节点的单链表，且头节点的数据域存储链表的长度

// 创建带头节点的单链表，并逆序输入 n 个元素的值
void CreateList_L(LinkList &, int);

// 在链表的第 i 个位置插入元素e
Status ListInsert_L(LinkList &, int, ElemType);

// 删除第 i 个位置的元素并由元素e返回其值
Status ListDelete_L(LinkList &, int, ElemType &);

// 获取第 i 个元素
Status GetElem_L(LinkList, int, ElemType &);

// 遍历链表
void ListTraverse_L(LinkList);

// 清空链表
Status ClearList_L(LinkList &);

#endif
#ifndef SEQUENCE_LIST_H

#include "../../common/status.h"

// 静态链表最大长度
#define MAX_SIZE 5

typedef int ElemType;

typedef struct
{
    ElemType data;
    int cur;
} component, SLinkList[MAX_SIZE];

// 初始化备用空间
void InitSpace_SL(SLinkList &);

// 获取指定元素的位序
int LocateElem_SL(SLinkList, ElemType);

// 获取静态链表长度
int ListLength_SL(SLinkList);

// 在链表的第 i 个节点插入元素e
Status ListInsert_SL(SLinkList &, int, ElemType);

// 删除链表第 i 个节点
Status ListDelete_SL(SLinkList &, int, ElemType &);

// 分配备用节点，返回分配节点的下标
int Malloc_SL(SLinkList &);
// 回收节点k到备用链表
void Free_SL(SLinkList &, int);

// 遍历静态链表表
void ListTraverse_SL(SLinkList);

#endif
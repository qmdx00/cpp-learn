#ifndef SEQUENCE_LIST_H

#include "../../common/status.h"

// 初始化长度
#define LIST_INIT_SIZE 5
// 扩容增量
#define LIST_INCREMENT 2

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

// 初始化顺序表，长度为 MAX_SIZE 100
Status InitList_Sq(SqList &);

/// 在第i个位置插入元素e
Status ListInsert_Sq(SqList &, int, ElemType);

// 删除第i个元素
Status ListDelete_Sq(SqList &, int, ElemType &);

// 遍历顺序表
void ListTraverse_Sq(SqList);

// 销毁顺序表，释放内存
Status DestroyList_Sq(SqList &);

#endif
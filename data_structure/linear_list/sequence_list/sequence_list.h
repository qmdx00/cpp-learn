#ifndef SEQUENCE_LIST_H

#include "../../common/status.h"

#define MAX_SIZE 100
typedef int ElementType;

// 静态分配空间
// typedef struct
// {
//     ElementType data[MAX_SIZE];
//     int length;
// } SqList;

// 动态分配空间
typedef struct
{
    ElementType *data;
    int length;
} SqList;

// 初始化顺序表，长度为 MAX_SIZE 100
Status InitSqList(SqList &);

// 向顺序表 L 中下标为 idx 的位置上插入元素 ele
Status InsertElement(SqList &, int, ElementType);

// 从顺序表 L 中删除下标为 idx 的元素，返回被删除的元素
Status DeleteElement(SqList &, int, ElementType &);

// 遍历列表
void TraversalList(SqList);

// 销毁列表，释放内存
Status DestroyList(SqList &);

#endif
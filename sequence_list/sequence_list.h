#ifndef SEQUENCE_H

#include "status.h"

#define MAX_SIZE 50
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

// 初始化顺序表，长度为 len
Status InitSqList(SqList &L, int len);

// 向顺序表 L 中下标为 idx 的位置上插入元素 ele
Status InsertElement(SqList &L, int idx, ElementType ele);

// 从顺序表 L 中删除下标为 idx 的元素，返回被删除的元素
Status DeleteElement(SqList &L, int idx, ElementType &ele);

#endif
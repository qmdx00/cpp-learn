#ifndef SORT_H
#define SORT_H

#include "../common/status.h"

#define MAX_SIZE 20     // 需要排序的顺序表的长度

typedef int KeyType;    // 关键字类型

typedef struct 
{
    KeyType key;
} RedType;              // 记录类型

typedef struct 
{
    RedType r[MAX_SIZE + 1];    // r[0]闲置或用作哨兵单元
    int length;         // 顺序表长度
} SqList;

// 初始化顺序表
Status InitList(SqList &, int);
// 遍历顺序表
Status TraverseList(SqList, Status (*Visit)(RedType));
// 直接插入排序
void InsertSort(SqList &);
// 希尔排序 dlta为增量序列，t为序列长度
void ShellSort(SqList &, int dlta[], int t);
// 冒泡排序
void BubbleSort(SqList &);
// 快速排序
void QuickSort(SqList &);
// 简单选择排序
void SelectSort(SqList &);
// 堆排序
void HeapSort(SqList &);
// 归并排序
void MergeSort(SqList &);
// 基数排序
void RadixSort(SqList &);


#endif // SORT_H
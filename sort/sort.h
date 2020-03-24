#ifndef SORT_H
#define SORT_H

#include "../common/status.h"

#define MAX_SIZE 20  // 需要排序的顺序表的长度
typedef int KeyType; // 关键字类型
typedef struct
{
    KeyType key;
} RedType; // 记录类型

typedef struct
{
    RedType r[MAX_SIZE + 1]; // r[0]闲置或用作哨兵单元
    int length;              // 顺序表长度
} SqList;

// 初始化顺序表
Status InitList(SqList &, int, int *);
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

#define MAX_NUM_OF_KEY 8 // 关键字位数的最大值
#define RADIX 10         // 关键字基数，十进制即 0～9 共10个
#define MAX_SPACE 100
typedef int KeysType; // 关键字类型
typedef struct
{
    KeysType keys[MAX_NUM_OF_KEY];
    int next;
} SLCell; // 静态链表的节点类型
typedef struct
{
    SLCell r[MAX_SPACE]; // 静态链表空间，r[0] 为头节点
    int keynum;          // 当前链表关键字个数
    int recnum;          // 静态链表当前长度
} SLList;
typedef int ArrType[RADIX]; // 指针数组类型

// m 为关键字最大位数, n 为关键字个数
Status InitList_SL(SLList &L, int m, int n, int *);
// 遍历 SLList
Status TraverseList_SL(SLList, Status (*Visit)(SLCell, int));
// 基数排序
void RadixSort(SLList &);

#endif // SORT_H
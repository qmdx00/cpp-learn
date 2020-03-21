#include <iostream>
#include "sort.h"

using namespace std;
// 初始化
Status InitList(SqList &L, int n)
{
    L.length = 0;
    if (n > MAX_SIZE) return ERROR;

    RedType ele;
    while (L.length < n)
    {
        cin >> ele.key;
        L.r[++L.length] = ele;
    }
    
    return OK;
}
// 遍历
Status TraverseList(SqList L, Status (*Visit)(RedType))
{
    for (int i = 1; i <= L.length; i++)
    {
        Visit(L.r[i]);
    }
    return OK;
}

// 直接插入排序
void InsertSort(SqList &L)
{
    int len = L.length;
    for (int i = 2; i <= len; i++)
    {
        if (L.r[i].key < L.r[i-1].key)
        {
            L.r[0] = L.r[i];        // 取出 L.r[i]
            L.r[i] = L.r[i - 1];    // L.r[i - 1]后移一位
            int j;
            for (j = i - 2; L.r[0].key < L.r[j].key; --j)   // 从 i-1 往前遍历，找到比 L.r[i] 小的元素的位置
                L.r[j + 1] = L.r[j];
            L.r[j + 1] = L.r[0];    // 将 L.r[i] 插入到该位置
        }
    }
}
// 希尔排序
void ShellSort(SqList &, int)
{
    // Todo
}
// 冒泡排序
void BubbleSort(SqList &)
{
    // Todo
}
// 快速排序
void QuickSort(SqList &)
{
    // Todo
}
// 简单选择排序
void SelectSort(SqList &)
{
    // Todo
}
// 堆排序
void HeapSort(SqList &)
{
    // Todo
}
// 归并排序
void MergeSort(SqList &)
{
    // Todo
}
// 基数排序
void RadixSort(SqList &)
{
    // Todo
}

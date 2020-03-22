#include <iostream>
#include "sort.h"

using namespace std;
// 初始化
Status InitList(SqList &L, int n)
{
    L.length = 0;
    if (n > MAX_SIZE)
        return ERROR;

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
        if (L.r[i].key < L.r[i - 1].key)
        {
            L.r[0] = L.r[i];     // 取出 L.r[i]
            L.r[i] = L.r[i - 1]; // L.r[i - 1]后移一位
            int j;
            for (j = i - 2; L.r[0].key < L.r[j].key; --j) // 从 i-1 往前遍历，找到比 L.r[i] 小的元素的位置
                L.r[j + 1] = L.r[j];
            L.r[j + 1] = L.r[0]; // 将 L.r[i] 插入到该位置
        }
    }
}

void ShellInsert(SqList &L, int dk)
{
    int i, j;
    for (i = dk + 1; i <= L.length; i++)
    {
        if (L.r[i].key < L.r[i - dk].key)
        {
            L.r[0] = L.r[i]; // 获取无序的元素
            for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
                L.r[j + dk] = L.r[j]; // 记录后移，查找插入位置
            L.r[j + dk] = L.r[0];     // 插入该元素
        }
    }
}
// 希尔排序 dlta为增量序列，t为序列长度
void ShellSort(SqList &L, int dlta[], int t)
{
    for (int k = 0; k < t; k++)
        ShellInsert(L, dlta[k]);
}
// 冒泡排序
void BubbleSort(SqList &L)
{
    for (int i = 1; i < L.length; i++)
    {
        for (int j = 1; j < L.length - i + 1; j++)
        {
            if (L.r[j].key > L.r[j + 1].key)
            {
                // L.r[0] 为缓存单元
                L.r[0] = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = L.r[0];
            }
        }
    }
}

int Partition(SqList &L, int low, int high)
{
    // low 位置元素为枢轴
    L.r[0] = L.r[low];
    int pivot = L.r[low].key;
    while (low < high)
    {
        // 从两端向中间扫描
        while (low < high && L.r[high].key >= pivot) --high;
        L.r[low] = L.r[high];   // 比 pivot 小的交换到 low 位置
        while (low < high && L.r[high].key <= pivot) ++low;
        L.r[high] = L.r[low];   // 比 pivot 大的交换到 high 位置
    }
    L.r[low] = L.r[0];
    return low;
}
void QSort(SqList &L, int low, int high)
{
    if (low < high)
    {
        int pivot_loc = Partition(L, low, high);
        QSort(L, low, pivot_loc - 1);
        QSort(L, pivot_loc + 1, high);
    }
}
// 快速排序
void QuickSort(SqList &L)
{
    QSort(L, 1, L.length);
}

int SelectMinKey(SqList &L, int idx)
{
    int min_loc = idx;
    for (int i = idx; i <= L.length; i++)
        if (L.r[i].key < L.r[min_loc].key)
            min_loc = i;
    return min_loc;
}
// 简单选择排序
void SelectSort(SqList &L)
{
    // 对 n 个元素只需做 n-1 次选择即可，最后一个必为最大
    for (int i = 1; i < L.length; i++)
    {
        int min = SelectMinKey(L, i);
        if (i != min)
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[min];
            L.r[min] = L.r[0];
        }
    }   
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

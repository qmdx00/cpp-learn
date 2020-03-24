#include "../common/compare.h"
#include "sort.h"


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
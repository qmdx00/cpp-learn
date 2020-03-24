#include "../common/compare.h"
#include "sort.h"

// 希尔排序
void ShellInsert(SqList &L, int dk)
{
    int i, j;
    for (i = dk + 1; i <= L.length; i++)
    {
        if (LT(L.r[i].key, L.r[i - dk].key))
        {
            L.r[0] = L.r[i]; // 获取无序的元素
            for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk)
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
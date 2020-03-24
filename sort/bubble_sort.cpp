#include "../common/compare.h"
#include "sort.h"

// 冒泡排序
void BubbleSort(SqList &L)
{
    for (int i = 1; i < L.length; i++)
    {
        for (int j = 1; j < L.length - i + 1; j++)
        {
            if (GT(L.r[j].key, L.r[j + 1].key))
            {
                // L.r[0] 为缓存单元
                L.r[0] = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = L.r[0];
            }
        }
    }
}
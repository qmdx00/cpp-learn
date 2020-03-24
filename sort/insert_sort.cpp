#include "../common/compare.h"
#include "sort.h"

// 直接插入排序
void InsertSort(SqList &L)
{
    int len = L.length;
    for (int i = 2; i <= len; i++)
    {
        if (LT(L.r[i].key, L.r[i - 1].key))
        {
            L.r[0] = L.r[i];     // 取出 L.r[i]
            L.r[i] = L.r[i - 1]; // L.r[i - 1]后移一位
            int j;
            for (j = i - 2; LT(L.r[0].key, L.r[j].key); --j) // 从 i-1 往前遍历，找到比 L.r[i] 小的元素的位置
                L.r[j + 1] = L.r[j];
            L.r[j + 1] = L.r[0]; // 将 L.r[i] 插入到该位置
        }
    }
}
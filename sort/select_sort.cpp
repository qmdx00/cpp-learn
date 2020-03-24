#include "../common/compare.h"
#include "sort.h"


int SelectMinKey(SqList &L, int idx)
{
    int min_loc = idx;
    for (int i = idx; i <= L.length; i++)
        if (LT(L.r[i].key, L.r[min_loc].key))
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
#include "../common/compare.h"
#include "sort.h"


void HeapAdjust(HeapType &H, int s, int m)
{
    // 调整 H.r[s] 使得 H.r[s..m] 成为一个大顶堆
    int j;
    RedType rc = H.r[s];
    for (j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && LT(H.r[j].key, H.r[j + 1].key))
            ++j;
        if (!LT(rc.key, H.r[j].key))
            break;
        H.r[s] = H.r[j];
        s = j;
    }
    H.r[s] = rc;
}
// 堆排序
void HeapSort(HeapType &H)
{
    for (int i = H.length / 2; i > 0; i--)
        HeapAdjust(H, i, H.length);
    for (int i = H.length; i > 1; i--)
    {
        H.r[0] = H.r[1];
        H.r[1] = H.r[i];
        H.r[i] = H.r[0];

        HeapAdjust(H, 1, i - 1);
    }
}
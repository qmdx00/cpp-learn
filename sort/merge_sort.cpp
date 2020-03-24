#include "../common/compare.h"
#include "sort.h"


void Merge(RedType SR[], RedType TR[], int i, int m, int n)
{
    int j, k;
    // 将有序的 SR[i..m] 和 SR[m+1..n] 归并为有序的 TR[i..n]
    for (j = m + 1, k = i; i <= m && j <= n; k++)
    {
        // 将 SR 中记录由小到大并入 TR
        if (LQ(SR[i].key, SR[j].key)) TR[k] = SR[i++];
        else TR[k] = SR[j++];
    }
    // 将左边剩余记录并入 TR
    while (i <= m)
    {
        TR[k++] = SR[i++];
    }
    // 将右边剩余记录并入 TR
    while (j <= n)
    {
        TR[k++] = SR[j++];
    }
}
void MSort(RedType SR[], RedType TR[], int s, int t)
{
    RedType TP[MAX_SIZE];
    // 将 SR[s..t] 归并排序为 TR[s..t]
    if (s == t) TR[s] = SR[t];
    else 
    {
        int m = (s+t) / 2;
        MSort(SR, TP, s, m);    // 将 SR[s..m] 归并为 TP[s..m]
        MSort(SR, TP, m+1, t);  // 将 SR[m+1..t] 归并为 TP[m+1..t]
        Merge(TP, TR, s, m , t);// 将 TP[s..m] 和 TP[m+1..t] 归并到 TR[s..t]
    }
}
// 归并排序
void MergeSort(SqList &L)
{
    MSort(L.r, L.r, 1, L.length);
}
#include <iostream>
#include "sort.h"

using namespace std;
// 初始化
Status InitList(SqList &L, int n, int arr[])
{
    L.length = 0;
    if (n > MAX_SIZE)
        return ERROR;

    RedType ele;
    while (L.length < n)
    {
        ele.key = arr[L.length];
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
// 初始化SLList, m 为关键字最大位数, n 为关键字个数
Status InitList_SL(SLList &L, int m, int n, int arr[])
{
    if (m > MAX_NUM_OF_KEY || n > MAX_SPACE)
        return ERROR;

    L.keynum = m;
    L.recnum = n;
    for (int i = 1; i <= L.recnum; i++)
    {
        int a = 1;
        for (int j = 1; j <= L.keynum; j++)
        {
            L.r[i].keys[j - 1] = (arr[i - 1] / a) % 10;
            a *= 10;
        }
    }
    for (int i = 0; i < L.recnum; i++)
        L.r[i].next = i + 1;
    L.r[L.recnum].next = 0;

    return OK;
}

Status TraverseList_SL(SLList L, Status (*Visit)(SLCell, int))
{
    for (int p = L.r[0].next; p; p = L.r[p].next)
    {
        Visit(L.r[p], L.keynum);
    }
    // for (int i = 1; i <= L.recnum; i++)
    // {
    //     Visit(L.r[i], L.keynum);
    // }
    return OK;
}

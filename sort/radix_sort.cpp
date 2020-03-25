#include "../common/compare.h"
#include "sort.h"

//将 k 映射到[0...RADIX-1]
int ord(KeysType k)
{
    return k;
}
// 求 f[j] 后的第一个非空子表
int succ(int j)
{
    return j + 1;
}

void Distribute(SLCell r[], int i, ArrType &f, ArrType &e)
{
    // 第 i 个关键字 keys[i] 建立 RADIX 个子表，使同一字表中的 keys[i] 相同
    // f[0..RADIX-1] 和 e[0..RADIX-1] 分别指向第一个和最后一个记录
    int j, p; // j 表示 r中记录的第 i 位的基数。如 i=2 时 j 表示 7823 中的 2
    for (j = 0; j < RADIX; j++)
    {
        f[j] = 0;
        e[j] = 0;
    }
    for (p = r[0].next; p; p = r[p].next)
    {
        j = ord(r[p].keys[i]);
        if (!f[j])
            f[j] = p;
        else
            r[e[j]].next = p;
        // 将 p 所指的节点插入第 j 个子表中
        e[j] = p;
    }
}

void Collect(SLCell r[], int i, ArrType f, ArrType e)
{
    // 按 keys[i] 从小到大将 f[0..RADIX-1] 所指字表连接成一个链表
    // e[0..RADIX-1] 为各子表的尾指针
    int j, t;
    // 找第一个非空子表
    for (j = 0; j < RADIX && !f[j]; j = succ(j))
        ;
    if (j < RADIX)
    {
        // r[0].next 指向第一个非空子表的第一个节点， t指向第一个非空子表的最后一个节点
        r[0].next = f[j];
        t = e[j];
        while (j < RADIX)
        {
            //找下一个非空子表
            for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j))
                ;
            if (f[j] && j < RADIX)
            {
                r[t].next = f[j];
                t = e[j];
            }
        }
        r[t].next = 0;
    }
}
// 基数排序
void RadixSort(SLList &L)
{
    for (int i = 0; i < L.recnum; i++)
        L.r[i].next = i + 1;
    L.r[L.recnum].next = 0;
    ArrType f, e;
    for (int i = 0; i < L.keynum; i++)
    {
        Distribute(L.r, i, f, e);
        Collect(L.r, i, f, e);
    }
}
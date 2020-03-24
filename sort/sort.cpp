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

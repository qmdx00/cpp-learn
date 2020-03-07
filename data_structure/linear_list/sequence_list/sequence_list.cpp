#include "sequence_list.h"
#include <iostream>

using namespace std;

Status InitSqList(SqList &L)
{
    L.data = new ElemType[MAX_SIZE];
    L.length = 0;
    return OK;
}

Status InsertElement(SqList &L, int idx, ElemType ele)
{
    if (L.length >= MAX_SIZE)
    {
        cerr << "sequence list is full" << endl;
        return OVERFLOW;
    }

    if (idx < 0 || idx > L.length)
    {
        cerr << "invalid position to insert" << idx << endl;
        return ERROR;
    }
    for (int i = L.length; i >= idx; i--)
    {
        L.data[i] = L.data[i - 1];
    }
    L.data[idx] = ele;
    L.length++;
    return OK;
}

Status DeleteElement(SqList &L, int idx, ElemType &ele)
{
    if (idx < 0 || idx >= L.length)
    {
        cerr << "invalid position to delete :" << idx << endl;
        ele = -1;
        return ERROR;
    }

    ele = L.data[idx];
    for (int i = idx; i < L.length - 1; i++)
    {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
    return OK;
}

void TraversalList(SqList L)
{
    if (L.length == 0)
    {
        cout << "[ ]" << endl;
        return;
    }
    cout << "[ ";
    for (int i = 0; i < L.length - 1; i++)
    {
        cout << L.data[i] << ", ";
    }
    cout << L.data[L.length - 1] << " ]" << endl;
}

Status DestroyList(SqList &L)
{
    delete[] L.data;
    L.length = 0;
    return OK;
}
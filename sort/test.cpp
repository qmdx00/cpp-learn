#include <iostream>
#include "sort.h"

using namespace std;

Status visit(RedType ele)
{
    cout << ele.key << " ";
    return OK;
}

Status visit_SL(SLCell cell, int n)
{
    for (int i = n - 1; i >= 0; i--)
        cout << cell.keys[i];
    cout << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    // SqList L;
    // cout << "unsorted array: " << endl
    //      << "9 4 1 3 5 8 10 7 2 6" << endl;
    // // 9 4 1 3 5 8 10 7 2 6
    // int arr[] = {9, 4, 1, 3, 5, 8, 10, 7, 2, 6};
    // InitList(L, 10, arr);

    // // 直接插入排序
    // InsertSort(L);
    // cout << "result after sort: " << endl;
    // TraverseList(L, visit);
    // cout << endl;

    // // 希尔排序
    // // 增量序列
    // int dlta[] = {5, 3, 1};
    // ShellSort(L, dlta, 3);
    // TraverseList(L, visit);
    // cout << endl;

    // // 冒泡排序
    // BubbleSort(L);
    // cout << "result after sort: " << endl;
    // TraverseList(L, visit);
    // cout << endl;

    // // 快速排序
    // QuickSort(L);
    // cout << "result after sort: " << endl;
    // TraverseList(L, visit);
    // cout << endl;

    // // 简单选择排序
    // SelectSort(L);
    // cout << "result after sort: " << endl;
    // TraverseList(L, visit);
    // cout << endl;

    // // 二路归并排序
    // SelectSort(L);
    // cout << "result after sort: " << endl;
    // TraverseList(L, visit);
    // cout << endl;

    SLList SL;
    cout << "unsorted array: " << endl
         << "123 214 120 315 403 552" << endl;
    // 123 214 120 315 403 552
    int arr1[] = {123, 214, 120, 315, 403, 552};
    InitList_SL(SL, 3, 6, arr1);

    // 基数排序
    RadixSort(SL);
    cout << "result after sort: " << endl;
    TraverseList_SL(SL, visit_SL);
    cout << endl;

    return 0;
}

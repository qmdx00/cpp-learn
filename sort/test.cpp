#include <iostream>
#include "sort.h"

using namespace std;

Status visit(RedType ele)
{
    cout << ele.key << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    SqList L;
    cout << "enter 10 elements separated by one space: " << endl;
    // 9 4 1 3 5 8 10 7 2 6
    InitList(L, 10);

    // // 直接插入排序
    // InsertSort(L);
    // cout << "result after sort: " << endl;
    // TraverseList(L, visit);
    // cout << endl;

    // // 希尔排序
    // // 增量序列
    // int arr[] = {5, 3, 1};
    // ShellSort(L, arr, 3);
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

    // 二路归并排序
    SelectSort(L);
    cout << "result after sort: " << endl;
    TraverseList(L, visit);
    cout << endl;

    return 0;
}

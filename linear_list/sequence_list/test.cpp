#include <iostream>
#include "sequence_list.h"

using namespace std;

Status visit(ElemType ele)
{
    cout << ele << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    SqList list;

    InitList_Sq(list);
    cout << "length: " << list.length << ", size: " << list.listsize << endl;
    ListTraverse_Sq(list, visit);
    cout << endl;

    for (int i = 1; i < 5; i++)
    {
        ListInsert_Sq(list, i, i * i);
    }
    cout << "add some elements" << endl;
    cout << "length: " << list.length << ", size: " << list.listsize << endl;
    ListTraverse_Sq(list, visit);
    cout << endl;

    int del;
    ListDelete_Sq(list, 3, del);
    cout << "delete element: " << del << endl;
    cout << "length: " << list.length << ", size: " << list.listsize << endl;
    ListTraverse_Sq(list, visit);
    cout << endl;

    ListInsert_Sq(list, 2, 7);
    cout << "insert element 7 at position 2" << endl;
    cout << "length: " << list.length << ", size: " << list.listsize << endl;
    ListTraverse_Sq(list, visit);
    cout << endl;

    ListInsert_Sq(list, list.length + 1, 10);
    cout << "insert element 10 at tail" << endl;
    cout << "length: " << list.length << ", size: " << list.listsize << endl;
    ListTraverse_Sq(list, visit);
    cout << endl;

    ListInsert_Sq(list, 4, 2);
    cout << "insert element 2 at position 4" << endl;
    cout << "length: " << list.length << ", size: " << list.listsize << endl;
    ListTraverse_Sq(list, visit);
    cout << endl;

    DestroyList_Sq(list);
    cout << "destory sequence list" << endl;
    cout << "length: " << list.length << ", size: " << list.listsize << endl;

    return 0;
}

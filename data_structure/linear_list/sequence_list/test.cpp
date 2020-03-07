#include <iostream>
#include "sequence_list.h"

using namespace std;
int main(int argc, char const *argv[])
{
    SqList list;

    InitSqList(list);
    cout << "initialize sequence list" << endl;
    TraversalList(list);

    for (int i = 0; i < 5; i++)
    {
        InsertElement(list, i, i * i);
    }
    cout << "add some elements" << endl;
    TraversalList(list);

    int del;
    DeleteElement(list, 3, del);
    cout << "delete element: " << del << endl;
    TraversalList(list);

    InsertElement(list, 2, 7);
    cout << "insert element 7 at position 2" << endl;
    TraversalList(list);

    InsertElement(list, list.length, 10);
    cout << "insert element 10 at tail" << endl;
    TraversalList(list);

    cout << "destory sequence list" << endl;
    DestroyList(list);

    return 0;
}

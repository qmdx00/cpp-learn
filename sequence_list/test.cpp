#include <iostream>
#include "sequence_list.h"

using namespace std;
int main(int argc, char const *argv[])
{
    SqList list;

    InitSqList(list);
    TraversalList(list);

    for (int i = 0; i < 5; i++)
    {
        InsertElement(list, i, i * i);
    }
    TraversalList(list);

    int del;
    DeleteElement(list, 3, del);
    cout << "delete element: " << del << endl;
    TraversalList(list);

    InsertElement(list, 2, 7);
    TraversalList(list);
    InsertElement(list, list.length, 100);
    TraversalList(list);

    DestroyList(list);

    return 0;
}

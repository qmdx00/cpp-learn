#include <iostream>
#include "double_linked_list.h"

using namespace std;

Status visit(ElemType ele)
{
    cout << ele << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    DuLinkList L;
    cout << "enter 3 elements by reverse order: " << endl;
    CreateList_DuL(L, 3);
    ListTraverse_DuL(L, visit);
    cout << endl;
    cout << "length of double linked list: " << L->data << endl;

    ListInsert_DuL(L, 3, 5);
    cout << "insert 5 at position 3" << endl;
    ListTraverse_DuL(L, visit);
    cout << endl;
    cout << "length of double linked list: " << L->data << endl;

    ElemType ele;
    ListDelete_DuL(L, 2, ele);
    cout << "delete " << ele << " at position 2" << endl;
    ListTraverse_DuL(L, visit);
    cout << endl;
    cout << "length of double linked list: " << L->data << endl;

    ClearList_DuL(L);
    cout << "clear list: " << endl;
    cout << "length of double linked list: " << L->data << endl;

    return 0;
}

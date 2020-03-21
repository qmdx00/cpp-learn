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
    cout << "enter 5 elements separated by one space: " << endl;
    InitList(L, 5);

    InsertSort(L);
    cout << "result after sort: " << endl;
    TraverseList(L, visit);
    cout << endl;
    
    return 0;
}

#include <iostream>
#include "linked_stack.h"

using namespace std;

Status visit(SElemType ele)
{
    cout << ele << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    LStack L;
    cout << "enter 3 elements: " << endl;
    InitStack_L(L, 3);
    cout << "length of stack: " << StackLength_L(L) << endl;
    StackTraverse_L(L, visit);
    cout << endl;

    SElemType ele;
    GetTop_L(L, ele);
    cout << "get top element: " << ele << endl;

    Push_L(L, 12);
    Push_L(L, 7);
    cout << "length of stack: " << StackLength_L(L) << endl;
    StackTraverse_L(L, visit);
    cout << endl;

    Pop_L(L, ele);
    cout << "pop element: " << ele << endl;
    cout << "length of stack: " << StackLength_L(L) << endl;
    StackTraverse_L(L, visit);
    cout << endl;

    cout << "pop all elements of stack: " << endl;
    while (!StackEmpty_L(L))
    {
        Pop_L(L, ele);
        cout << ele << " ";
    }
    cout << endl;

    cout << "destroy stack" << endl;
    DestroyStack_L(L);

    return 0;
}

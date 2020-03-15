#include <iostream>
#include "linked_stack.h"

using namespace std;
int main(int argc, char const *argv[])
{
    LStack L;
    cout << "enter 3 elements: " << endl;
    InitStack_L(L, 3);
    cout << "length of stack: " << StackLength_L(L) << endl;
    StackTraverse_L(L);

    SElemType ele;
    GetTop_L(L, ele);
    cout << "get top element: " << ele << endl;

    Push_L(L, 12);
    Push_L(L, 7);
    cout << "length of stack: " << StackLength_L(L) << endl;
    StackTraverse_L(L);

    Pop_L(L, ele);
    cout << "pop element: " << ele << endl;
    cout << "length of stack: " << StackLength_L(L) << endl;
    StackTraverse_L(L);

    cout << "pop all elements of stack: " << endl;
    while(!StackEmpty_L(L))
    {
        Pop_L(L, ele);
        cout << ele << endl;
    }

    cout << "destroy stack" << endl;
    DestroyStack_L(L);

    return 0;
}

#include <iostream>
#include "sequence_stack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    SqStack S;
    InitStack_Sq(S);
    cout << "init stack size: " << S.stacksize << endl;
    cout << "stack length: " << StackLength_Sq(S) << endl;
    for (int i = 0; i < 6; i++)
    {
        Push_Sq(S, i + 1);
    }
    cout << "stack size: " << S.stacksize << endl;
    cout << "stack length: " << StackLength_Sq(S) << endl;
    StackTraverse_Sq(S);

    SElemType ele;
    GetTop_Sq(S, ele);
    cout << "get top element: " << ele << endl;

    Pop_Sq(S, ele);
    cout << "pop element: " << ele << endl;
    cout << "stack length: " << StackLength_Sq(S) << endl;
    StackTraverse_Sq(S);

    ClearStack_Sq(S);
    cout << "stack size: " << S.stacksize << endl;
    cout << "stack length: " << StackLength_Sq(S) << endl;
    if (StackEmpty_Sq(S)) cout << "stack empty" << endl;
    else cout << "stack not empty" << endl;

    DestroyStack_Sq(S);

    return 0;
}

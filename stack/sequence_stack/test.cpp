#include <iostream>
#include "sequence_stack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    SqStack S;
    InitStack(S);
    cout << "init stack size: " << S.stacksize << endl;
    cout << "stack length: " << StackLength(S) << endl;
    for (int i = 0; i < 6; i++)
    {
        Push(S, i + 1);
    }
    cout << "stack size: " << S.stacksize << endl;
    cout << "stack length: " << StackLength(S) << endl;
    StackTraverse(S);

    SElemType ele;
    GetTop(S, ele);
    cout << "get top element: " << ele << endl;

    Pop(S, ele);
    cout << "pop element: " << ele << endl;
    cout << "stack length: " << StackLength(S) << endl;
    StackTraverse(S);

    ClearStack(S);
    cout << "stack size: " << S.stacksize << endl;
    cout << "stack length: " << StackLength(S) << endl;
    if (StackEmpty(S)) cout << "stack empty" << endl;
    else cout << "stack not empty" << endl;

    DestoryStack(S);

    return 0;
}

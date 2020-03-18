#include <iostream>
#include "../linked_stack/linked_stack.h"

/**
 * 数制转换：十进制转八进制
 */
using namespace std;
void conversion()
{
    LStack S;
    InitStack_L(S, 0);
    cout << "enter N: " << endl;
    int N;
    cin >> N;
    while (N)
    {
        Push_L(S, N % 8);
        N = N / 8;
    }
    
    cout << "result: " << endl;
    while (!StackEmpty_L(S))
    {
        SElemType e;
        Pop_L(S, e);
        cout << e;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    conversion();
    return 0;
}

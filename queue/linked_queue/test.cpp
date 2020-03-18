#include <iostream>
#include "linked_queue.h"

using namespace std;
int main(int argc, char const *argv[])
{
    LinkQueue Q;   
    InitQueue_L(Q);

    for (int i = 1; i < 5; i++)
    {
        EnQueue_L(Q, i);
    }
    QElemType ele;
    cout << "get head element: " << GetHead_L(Q, ele) << endl;
    cout << "length of queue: " << QueueLength_L(Q) << endl;
    TraverseQueue_L(Q);

    EnQueue_L(Q, 7);
    cout << "enqueue 7: " << endl;
    cout << "length of queue: " << QueueLength_L(Q) << endl;
    TraverseQueue_L(Q);

    DeQueue_L(Q, ele);
    cout << "dequeue " << ele << endl;
    cout << "length of queue: " << QueueLength_L(Q) << endl;
    TraverseQueue_L(Q);

    while (!QueueEmpty_L(Q))
    {
        DeQueue_L(Q, ele);
        cout << ele << " ";
    }
    cout << endl;
    cout << "length of queue: " << QueueLength_L(Q) << endl;

    DestroyQueue_L(Q);

    return 0;
}

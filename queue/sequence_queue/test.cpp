#include <iostream>
#include "sequence_queue.h"

using namespace std;
int main(int argc, char const *argv[])
{
    SqQueue Q;
    InitQueue_Sq(Q);

    for (int i = 1; i < 5; i++)
    {
        EnQueue_Sq(Q, i);
    }
    cout << "queue length: " << QueueLength_Sq(Q) << endl;
    TraverseQueue_Sq(Q);

    if (EnQueue_Sq(Q, 9))
        cout << "enqueue element 9" << endl;
    else
        cout << "queue full" << endl;
    TraverseQueue_Sq(Q);

    QElemType ele;
    DeQueue_Sq(Q, ele);
    cout << "dequeue element: " << ele << endl;
    cout << "queue length: " << QueueLength_Sq(Q) << endl;
    TraverseQueue_Sq(Q);

    GetHead_Sq(Q, ele);
    cout << "get head element: " << ele << endl;

    EnQueue_Sq(Q, 9);
    cout << "enqueue element 9: " << endl;
    TraverseQueue_Sq(Q);

    while (!QueueEmpty_Sq(Q))
    {
        DeQueue_Sq(Q, ele);
        cout << ele << " ";
    }
    cout << endl;

    DestroyQueue_Sq(Q);

    return 0;
}

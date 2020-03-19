#include <iostream>
#include "sequence_queue.h"

using namespace std;

Status visit(QElemType ele)
{
    cout << ele << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    SqQueue Q;
    InitQueue_Sq(Q);

    for (int i = 1; i < 5; i++)
    {
        EnQueue_Sq(Q, i);
    }
    cout << "queue length: " << QueueLength_Sq(Q) << endl;
    TraverseQueue_Sq(Q, visit);
    cout << endl;

    if (EnQueue_Sq(Q, 9))
        cout << "enqueue element 9" << endl;
    else
        cout << "enqueue failed, queue full" << endl;
    TraverseQueue_Sq(Q, visit);
    cout << endl;

    QElemType ele;
    DeQueue_Sq(Q, ele);
    cout << "dequeue element: " << ele << endl;
    cout << "queue length: " << QueueLength_Sq(Q) << endl;
    TraverseQueue_Sq(Q, visit);
    cout << endl;

    GetHead_Sq(Q, ele);
    cout << "get head element: " << ele << endl;

    EnQueue_Sq(Q, 9);
    cout << "enqueue element 9: " << endl;
    TraverseQueue_Sq(Q, visit);
    cout << endl;

    cout << "dequeue all elements: " << endl;
    while (!QueueEmpty_Sq(Q))
    {
        DeQueue_Sq(Q, ele);
        cout << ele << " ";
    }
    cout << endl;

    DestroyQueue_Sq(Q);

    return 0;
}

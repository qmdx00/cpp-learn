#include <iostream>
#include "sequence_queue.h"

Status InitQueue_Sq(SqQueue &Q)
{
    Q.base = (QElemType *)malloc(MAX_QUEUE_SIZE * sizeof(QElemType));
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength_Sq(SqQueue Q)
{
    return (Q.rear - Q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Status EnQueue_Sq(SqQueue &Q, QElemType ele)
{
    // 队列满了
    if ((Q.rear + 1) % MAX_QUEUE_SIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = ele;
    Q.rear = (Q.rear + 1) % MAX_QUEUE_SIZE;
    return OK;
}

Status DeQueue_Sq(SqQueue &Q, QElemType &ele)
{
    if (Q.front == Q.rear)
        return ERROR;
    ele = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX_QUEUE_SIZE;
    return OK;
}

Status DestroyQueue_Sq(SqQueue &Q)
{
    free(Q.base);
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty_Sq(SqQueue Q)
{
    if (Q.front == Q.rear) return TRUE;
    else return FALSE;    
}

Status GetHead_Sq(SqQueue Q, QElemType &ele)
{
    if (Q.front == Q.rear) return ERROR;
    ele = Q.base[Q.front];
    return OK;
}

void TraverseQueue_Sq(SqQueue Q, Status (*Visit)(QElemType))
{
    while (Q.front != Q.rear)
    {
        Visit(Q.base[Q.front]);
        Q.front = (Q.front + 1) % MAX_QUEUE_SIZE;
    }
}

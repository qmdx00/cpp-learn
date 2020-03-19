#include <iostream>
#include "linked_queue.h"

using namespace std;
Status InitQueue_L(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;

    return OK;
}

Status DestroyQueue_L(LinkQueue &Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }

    return OK;
}

Status QueueEmpty_L(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength_L(LinkQueue Q)
{
    int length = 0;
    while (Q.front->next)
    {
        Q.front = Q.front->next;
        ++length;
    }
    return length;
}

Status GetHead_L(LinkQueue Q, QElemType &ele)
{
    if (Q.front->next == NULL)
        return ERROR;
    ele = Q.front->next->data;
    return OK;
}

Status EnQueue_L(LinkQueue &Q, QElemType ele)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = ele;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue_L(LinkQueue &Q, QElemType &ele)
{
    if (Q.front == Q.rear)
        return ERROR;
    QueuePtr p = Q.front->next;
    ele = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}

void TraverseQueue_L(LinkQueue Q, Status (*Visit)(QElemType))
{
    if (Q.front != Q.rear)
    {
        QueuePtr p = Q.front->next;
        while (p)
        {
            Visit(p->data);
            p = p->next;
        }
    }
}
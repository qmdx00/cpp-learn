#ifndef SEQUENCE_QUEUE_H
#define SEQUENCE_QUEUE_H

#include "../../common/status.h"

#define MAX_QUEUE_SIZE 5

typedef int QElemType;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;


Status InitQueue_Sq(SqQueue &);

int QueueLength_Sq(SqQueue);

Status EnQueue_Sq(SqQueue &, QElemType);

Status DeQueue_Sq(SqQueue &, QElemType &);

Status DestroyQueue_Sq(SqQueue &);

Status QueueEmpty_Sq(SqQueue);

Status GetHead_Sq(SqQueue, QElemType &);

void TraverseQueue_Sq(SqQueue, Status (*Visit)(QElemType));

#endif
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "../../common/status.h"

typedef int QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; // 队列头指针
    QueuePtr rear;  // 队列尾指针
} LinkQueue;

Status InitQueue_L(LinkQueue &);

Status DestroyQueue_L(LinkQueue &);

Status QueueEmpty_L(LinkQueue);

int QueueLength_L(LinkQueue);

Status GetHead_L(LinkQueue, QElemType &);
// 插入到队尾
Status EnQueue_L(LinkQueue &, QElemType);
// 从队头删除
Status DeQueue_L(LinkQueue &, QElemType &);

void TraverseQueue_L(LinkQueue);

#endif
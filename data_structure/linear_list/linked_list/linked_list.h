#ifndef _LINKED_LIST_H

#include "../../common/status.h"

typedef int ElemType;

typedef struct LkList {
    ElemType data;
    LkList* next;
} LkList;

Status InitLkList(LkList &);

Status InsertElement(LkList &, int, ElemType);

Status DeleteElement(LkList &, int, ElemType &);

Status DestroyList(LkList &);

void TraversalList(LkList);

#endif
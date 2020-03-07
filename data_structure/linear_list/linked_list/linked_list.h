#ifndef _LINKED_LIST_H

#include "../../common/status.h"

typedef int ElementType;

typedef struct LkList {
    ElementType data;
    LkList* next;
} LkList;

Status InitLkList(LkList &);

Status InsertElement(LkList &, int, ElementType);

Status DeleteElement(LkList &, int, ElementType &);

Status DestroyList(LkList &);

void TraversalList(LkList);

#endif
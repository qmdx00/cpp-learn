#include "sequence_list.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Status InitSqList(SqList &L, int len)
{
    if (len > MAX_SIZE || len < 0)
    {
        L.length = 0;
        cerr << len << " is a invalid length of sequence list !, it's from 0 to " << MAX_SIZE << endl;
        return ERROR;
    }
    L.data = (ElementType*)malloc(sizeof(ElementType)*len);
    L.length = len;
    return OK;
}
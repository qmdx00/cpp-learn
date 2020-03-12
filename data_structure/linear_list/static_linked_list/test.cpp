#include <iostream>
#include "static_linked_list.h"

using namespace std;
int main(int argc, char const *argv[])
{
    SLinkList S;
    InitSpace_SL(S);
    for (int i = 1; i < MAX_SIZE; i++)
    {
        S[i].data = i+1;
    }
    ListTraverse_SL(S);
    cout << "length of list: " << ListLength_SL(S) << endl;

    ElemType ele;
    ListDelete_SL(S, 2, ele);
    cout << "delete " << ele << " at position 2" << endl;
    ListTraverse_SL(S);
    cout << "length of list: " << ListLength_SL(S) << endl;
    return 0;
}

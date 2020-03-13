#include <iostream>
#include "static_linked_list.h"

using namespace std;
int main(int argc, char const *argv[])
{
    SLinkList SP;
    InitSpace_SL(SP); // 生成备用空间

    component S; // 头节点
    S.cur = Malloc_SL(SP);

    // 初始化静态链表
    int head = S.cur;
    for (int i = 1; i < 5; i++)
    {
        SP[head].cur = Malloc_SL(SP);
        SP[head].data = i;
        head = SP[head].cur;
    }
    SP[head - 1].cur = 0;
    cout << "initialize static linked list: " << endl;
    ListTraverse_SL(SP, S.cur);

    ElemType ele;
    ListDelete_SL(SP, S.cur, 2, ele);
    cout << "delete " << ele << " at position 2" << endl;
    ListTraverse_SL(SP, S.cur);

    ListDelete_SL(SP, S.cur, 1, ele);
    cout << "delete " << ele << " at position 1" << endl;
    ListTraverse_SL(SP, S.cur);

    ListInsert_SL(SP, S.cur, 1, 21);
    cout << "insert 21 at position 1" << endl;
    ListTraverse_SL(SP, S.cur);

    ListInsert_SL(SP, S.cur, 2, 7);
    cout << "insert 7 at position 2" << endl;
    ListTraverse_SL(SP, S.cur);
    
    return 0;
}

#include <iostream>
#include "threaded_binary_tree.h"

using namespace std;
Status CreateBiTree_Thr(BiThrTree &T)
{
    char ch;
    cin >> ch;
    // 空节点用 # 表示
    if (ch == '#')
        T = NULL;
    else
    {
        if (!(T = (BiThrNode *)malloc(sizeof(BiThrNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree_Thr(T->lchild);
        CreateBiTree_Thr(T->rchild);
    }
    return OK;
}

void InThreading(BiThrTree T, BiThrTree &pre)
{
    if (!T) return;
    InThreading(T->lchild, pre);
    if (!T->lchild)
    {
        T->LTag = Thread;
        T->lchild = pre;
    }
    if (!pre->rchild)
    {
        pre->RTag = Thread;
        pre->rchild = T;
    }
    pre = T;
    InThreading(T->rchild, pre);
}
// 中序遍历T，中序线索化二叉树，Thrt指向头节点
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
    // 创建头节点
    if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;
    // 右指针回指
    Thrt->rchild = Thrt;

    if (!T) Thrt->lchild = Thrt;
    else 
    {
        BiThrTree pre;
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T, pre);
        pre->rchild = Thrt;
        pre->RTag = Thread;
        Thrt->rchild = pre;
    }

    return OK;
}
// 中序遍历线索二叉树
Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType))
{
    BiThrTree p = T->lchild;
    while (p != T)
    {
        while (p->LTag == Link) p = p->lchild;
        if (!Visit(p->data)) return ERROR;
        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            Visit(p->data);
        }
        p = p->rchild;
    }
    
    return OK;
}
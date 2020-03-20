#include <iostream>
#include <queue>
#include "binary_tree.h"

using namespace std;
// 创建二叉树，用前序顺序输入
Status CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    // 空节点用 # 表示
    if (ch == '#')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}
// 前序遍历(递归)   根-左-右
Status PreOrderTraverse_recursion(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (Visit(T->data))
            if (PreOrderTraverse_recursion(T->lchild, Visit))
                if (PreOrderTraverse_recursion(T->rchild, Visit))
                    return OK;
                else
                    return ERROR;
    }
    else
        return OK;
}
// 中序遍历(递归)   左-根-右
Status InOrderTraverse_recursion(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (InOrderTraverse_recursion(T->lchild, Visit))
            if (Visit(T->data))
                if (InOrderTraverse_recursion(T->rchild, Visit))
                    return OK;
                else
                    return ERROR;
    }
    else
        return OK;
}
// 后序遍历(递归)   左-右-根
Status PostOrderTraverse_recursion(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (PostOrderTraverse_recursion(T->lchild, Visit))
            if (PostOrderTraverse_recursion(T->rchild, Visit))
                if (Visit(T->data))
                    return OK;
                else
                    return ERROR;
    }
    else
        return OK;
}
// 层次遍历(递归)
Status LevelOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    BiTree p;
    queue<BiTree> q;
    if (T)
        q.push(T);
    while (!q.empty())
    {
        p = q.front();
        Visit(p->data);
        q.pop();
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
    return OK;
}
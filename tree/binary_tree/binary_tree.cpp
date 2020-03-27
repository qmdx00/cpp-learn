#include <iostream>
#include <queue>
#include <stack>
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
// 层次遍历(非递归)
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

// 前序遍历(非递归)   根-左-右
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty())
    {
        while (p)
        {
            Visit(p->data);
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    return OK;
}
// 中序遍历(非递归)   左-根-右
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->lchild;
        }
        p = s.top();
        s.pop();
        Visit(p->data);
        p = p->rchild;
    }
    return OK;
}
// 后序遍历(非递归)   左-右-根
Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    stack<BiTree> s;
    BiTree p = T, r = NULL;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            if (p->rchild && p->rchild != r) p = p->rchild;
            else
            {
                p = s.top();
                s.pop();
                Visit(p->data);
                r = p;
                p = NULL;
            }
            
        }
        
    }
    return OK;
}
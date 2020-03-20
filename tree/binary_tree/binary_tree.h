#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../../common/status.h"

typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 创建二叉树，用前序顺序输入
Status CreateBiTree(BiTree &);

// 前序遍历(递归)   根-左-右
Status PreOrderTraverse_recursion(BiTree, Status (*Visit)(TElemType));
// 中序遍历(递归)   左-根-右
Status InOrderTraverse_recursion(BiTree, Status (*Visit)(TElemType));
// 后序遍历(递归)   左-右-根
Status PostOrderTraverse_recursion(BiTree, Status (*Visit)(TElemType));

// 层次遍历
Status LevelOrderTraverse(BiTree, Status (*Visit)(TElemType));

#endif // BINARY_TREE_H

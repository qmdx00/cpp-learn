#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../../common/status.h"

typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &);
// 前序遍历
Status PreOrderTraverse(BiTree, Status(*Visit)(TElemType));
// 中序遍历
Status InOrderTraverse(BiTree, Status(*Visit)(TElemType));
// 后序遍历
Status PostOrderTraverse(BiTree, Status(*Visit)(TElemType));
// 层次遍历
Status LevelOrderTraverse(BiTree, Status(*Visit)(TElemType));

#endif // BINARY_TREE_H

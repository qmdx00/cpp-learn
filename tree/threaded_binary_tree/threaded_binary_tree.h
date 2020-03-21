// 增加头节点的线索二叉树
#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H

#include "../../common/status.h"

typedef char TElemType;

typedef enum PointerTag { Link, Thread }; // 0(Link) 指针，1(Thread) 线索

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;

Status CreateBiTree_Thr(BiThrTree &);
// 中序遍历T，中序线索化二叉树，Thrt指向头节点
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T);
// 中序遍历线索二叉树
Status InOrderTraverse_Thr(BiThrTree, Status (*Visit)(TElemType));

#endif // THREADED_BINARY_TREE_H
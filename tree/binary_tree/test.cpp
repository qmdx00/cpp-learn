#include <iostream>
#include "binary_tree.h"

using namespace std;

Status visit(TElemType ele)
{
    cout << ele << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    BiTree T;
    cout << "enter tree structure by inter order: " << endl;
    // ABD##E##CF###
    CreateBiTree(T);

    //=======================递归======================//
    cout << "previous order traverse (recursion): " << endl;
    // A B D E C F 
    PreOrderTraverse_recursion(T, visit);
    cout << endl;

    cout << "inter order traverse (recursion): " << endl;
    // D B E A F C 
    InOrderTraverse_recursion(T, visit);
    cout << endl;

    cout << "post order traverse (recursion): " << endl;
    // D E B F C A
    PostOrderTraverse_recursion(T, visit);
    cout << endl;

    //=======================非递归======================//
    cout << "previous order traverse: " << endl;
    // A B D E C F 
    PreOrderTraverse(T, visit);
    cout << endl;

    cout << "inter order traverse: " << endl;
    // D B E A F C 
    InOrderTraverse(T, visit);
    cout << endl;

    cout << "post order traverse: " << endl;
    // D E B F C A
    PostOrderTraverse(T, visit);
    cout << endl;

    cout << "level order traverse: " << endl;
    // A B C D E F
    LevelOrderTraverse(T, visit);
    cout << endl;

    return 0;
}

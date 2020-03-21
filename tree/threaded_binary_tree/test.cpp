#include <iostream>
#include "threaded_binary_tree.h"

using namespace std;

Status visit(TElemType ele)
{
    cout << ele << " ";
    return OK;
}

int main(int argc, char const *argv[])
{
    BiThrTree Thrt, T;
    cout << "enter tree structure by inter order: " << endl;
    // ABD##E##CF###
    CreateBiTree_Thr(T);
    InOrderThreading(Thrt, T);
    cout << "threading ..." << endl;
    // D B E A F C
    cout << "inter order traverse: " << endl;
    InOrderTraverse_Thr(Thrt, visit);
    cout << endl;
    return 0;
}

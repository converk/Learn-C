#include <stdio.h>
#include <stdlib.h>
#include "AVL-Tree.h"

int main(int argc, char const *argv[])
{
    AVLTree T=malloc(sizeof(struct AVLNode));
    T->left = T->right = NULL;
    T->Heigth=0;
    T->Element=3;

    //插入元素
    T = Insert(2, T); //这里一定要用T=来接收返回值,不然T不会改变
    T = Insert(1, T);
    T = Insert(4, T);
    T = Insert(5, T);
    T = Insert(6, T);
    T = Insert(7, T);
    T = Insert(16, T);
    T = Insert(15, T);
    T = Insert(14, T);
    T = Insert(13, T);
    T = Insert(12, T);
    T = Insert(11, T);
    T = Insert(10, T);
    T = Insert(8, T);
    T = Insert(9, T);
    fputs("begin:", stdout);
    PtrTree(T);
    printf("\n");

    //删除一个元素
    T=Delete(13,T);
    fputs("Delete8:", stdout);
    PtrTree(T);
    printf("\n");

    return 0;
}

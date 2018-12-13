#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryLookupTree.h"

int main(void)
{

    //初始化一个树,只有一个节点
    SearchTree T = malloc(sizeof(struct TreeNode));
    T->x = 50;
    T->left = T->right = NULL;
    fputs("begin:", stdout);
    PtrTree(T);
    printf("\n");

    //插入节点
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
        InSert_2((rand() % (100 - 1 + 1)) + 1, T);
    fputs("Insert:", stdout);
    PtrTree(T);
    printf("\n");

    //找到最小,大值并删除
    Delete(FindMin(T)->x, T);
    fputs("DeleteMin:", stdout);
    PtrTree(T);
    printf("\n");
    Delete(FindMax(T)->x, T);
    fputs("DeleteMax:", stdout);
    PtrTree(T);
    printf("\n");

    return 0;
}
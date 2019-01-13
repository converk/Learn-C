#include "Left-Heap.h"
#include <stdio.h>
#include <stdlib.h>

LeftHeap InitHeap(void)
{
    LeftHeap L;
    L = malloc(sizeof(struct TreeNode));
    if (!L)
        return NULL;
    L->NPL = 0;
    L->left = L->rigth = NULL;
    return L;
}

static LeftHeap Merge1(LeftHeap L1, LeftHeap L2)
{
    if (L1->left == NULL && L1->rigth == NULL)
        L1->left = L2; //如果该节点是一个单节点的话,直接将L2接上去,这个也是递归退出的条件
    else {
        L1->rigth = Merge(L1->rigth, L2);
        if (L1->left->NPL < L1->rigth->NPL) { //如果左子树的NPL小于右子树,那么就交换两个子树
            LeftHeap temp;
            temp = L1->left;
            L1->left = L1->rigth;
            L1->rigth = temp;
        }
        L1->NPL = L1->rigth->NPL + 1; //更新当前节点的NPL信息
    }
    return L1;
}

LeftHeap Merge(LeftHeap L1, LeftHeap L2)
{
    if (L1 == NULL)
        return L2;
    else if (L2 == NULL)
        return L1;
    else if (L1->Element < L2->Element)
        return Merge1(L1, L2); //将L1当做根节点
    else
        return Merge1(L2, L1); //将L2当做根节点
}

LeftHeap Insert1(int InsertElement, LeftHeap L)
{
    LeftHeap L2 = malloc(sizeof(struct TreeNode));
    L2->left = NULL;
    L2->rigth = NULL;
    L2->NPL = 0;
    L2->Element = InsertElement;
    return Merge(L2, L);
}

LeftHeap DeleteMin1(LeftHeap L)
{
    LeftHeap Left, Rigth;
    Left = L->left;
    Rigth = L->rigth;
    free(L);
    return Merge(Left, Rigth);
}
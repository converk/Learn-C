#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree InSert_1(int x, SearchTree T);
SearchTree InSert_2(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
void PtrTree(SearchTree T);

struct TreeNode
{
    int x;
    SearchTree left;
    SearchTree right;
};

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

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->left); //递归清空左右子树
        MakeEmpty(T->right);
        free(T); //清空完毕释放指针空间,指针变为野指针
    }
    return NULL; //根据树的递归定义,最后全部清空
}

Position Find(int x, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (x < T->x)
        return Find(x, T->left);
    else if (x > T->x)
        return Find(x, T->right);
    else
        return T;
}

Position FindMin(SearchTree T)
{ //非递归实现
    if (T == NULL)
        return NULL;
    if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}

Position FindMax(SearchTree T)
{ //非递归实现
    Position P = T;
    if (P != NULL)
        while (P->right != NULL)
            P = P->right;
    return P;
}

SearchTree InSert_1(int x, SearchTree T)
{
    Position P = T;
    if (P->left || P->right)
    {
        if (x < P->x && P->left != NULL)
            InSert_1(x, P->left);
        else if (x > T->x && P->right != NULL)
            InSert_1(x, P->right);
        else
        {
            Position insert = malloc(sizeof(struct TreeNode));
            insert->x = x;
            insert->left = insert->right = NULL;
            if (x < P->x && P->left == NULL)
                P->left = insert;
            if (x > P->x && P->right == NULL)
                P->right = insert;
        }
    }
    else
    {
        Position insert = malloc(sizeof(struct TreeNode));
        insert->x = x;
        insert->left = insert->right = NULL;
        if (x < P->x)
            P->left = insert;
        if (x > P->x)
            P->right = insert;
    }
    return T;
}

//Insert_2的基本方法:递归插入,如果,小于当前节点的关键字,则重复调用,并且让这个节点的
//left指向下一个插入的返回结果(也是一个树),当递归到T为NULL的时候,说明要插入这个地方
//但是为空,则停止递归,在此处插入
//记住插入的节点,最后一定是个树叶,不可能在树的中间插入
SearchTree InSert_2(int x, SearchTree T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T != NULL)
        {
            T->x = x;
            T->left = T->right = NULL;
        }
    }
    else if (x < T->x)
        T->left = InSert_2(x, T->left);
    else if (x > T->x)
        T->right = InSert_2(x, T->right);
    return T;
}

//对于所有的数据结构来说,删除操作都是最难的
//三种情况:树叶,有一个子节点,有两个子节点

SearchTree Delete(int x, SearchTree T)
{
    Position P;
    if (T == NULL)
        return NULL;
    else if (x < T->x)
        T->left = Delete(x, T->left); //将当前节点的左子树指向删除x后的左子树
    else if (x > T->x)
        T->right = Delete(x, T->right);
    else if (T->left && T->right)
    {
        //如果两个儿子都存在,先找到右子树最小的,用其代替当前节点的关键字,然后再递归删除右子树最小节点
        P = FindMin(T->right);
        T->x = P->x;
        T->right = Delete(P->x, T->right);
    }
    else
    { //如果只有一个儿子或者没有儿子
        P = T;
        if (T->left == NULL)
            T = T->right; //改变子树的指向,返回的时候T的指向已经改变了
        if (T->right == NULL)
            T = T->left;
        free(P); //释放原有树节点的空间
    }
    return T;
}

void PtrTree(SearchTree T)
{
    if (T->left)
        PtrTree(T->left);
    if (T->right)
        PtrTree(T->right);
    printf("%d ", T->x);
}
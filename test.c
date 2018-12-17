#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

//查找和之前没什么区别
AVLTree MakeEmpty(AVLTree T);
Position SingleRotateWhithLeft(Position K2);  //情景1
Position SingleRotateWhithRight(Position K2); //情景4
Position DoubleRotateWhithLeft(Position K3);  //情景2
Position DoubleRotateWhithRight(Position K3); //情景3
AVLTree Insert(int x, AVLTree T);
AVLTree Delete(int x, AVLTree);
void PtrTree(AVLTree T);

struct AVLNode
{
    int Element;
    AVLTree left;
    AVLTree right;
    int Heigth;
};

int main(int argc, char const *argv[])
{
    AVLTree T = malloc(sizeof(struct AVLNode));
    T->left = T->right = NULL;
    T->Heigth = 0;
    T->Element = 3;

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
    T = Delete(5, T);
    fputs("Delete8:", stdout);
    PtrTree(T);
    printf("\n");

    return 0;
}

AVLTree MakeEmpty(AVLTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return T;
}

static int Heigth(AVLTree T) //获取一个节点的高度
{
    if (!T)
        return -1;
    else
        return T->Heigth;
}

//插入要分四种情景,分别讨论,插入和旋转完成后,
//要更改根节点到插入节点之间各个节点的高度
AVLTree Insert(int x, AVLTree T)
{
    if (T == NULL)
    { //当初始化一个AVL树
        T = malloc(sizeof(struct AVLNode));
        if(T==NULL)
            printf("ERROR!!!");
        else{
            T->left = T->right = NULL;
            T->Element = x;
            T->Heigth = 0;
        } 
    }
    else if (x < T->Element)
    {
        T->left = Insert(x, T->left); //树的递归定义
        if (Heigth(T->left) - Heigth(T->right) == 2)
        {
            if (T->left->Element > x)
                T = SingleRotateWhithLeft(T); //1
            else
                T = DoubleRotateWhithLeft(T); //2
        }
    }
    else if (x > T->Element)
    {
        T->right = Insert(x, T->right); //树的递归定义
        if (Heigth(T->right) - Heigth(T->left) == 2)
        {
            if (T->right->Element < x)
                T = SingleRotateWhithRight(T); //1
            else
                T = DoubleRotateWhithRight(T); //2
        }
    }
    T->Heigth = Heigth(T->left) >= Heigth(T->right) ? Heigth(T->left) + 1 : Heigth(T->right) + 1;
    return T;
}

Position SingleRotateWhithLeft(Position K2)
{
    Position temp = K2->left; //根据单旋转的规则改变指向
    K2->left = temp->right;
    temp->right = K2;

    K2->Heigth = Heigth(K2->left) >= Heigth(K2->right) ? Heigth(K2->left) + 1 : Heigth(K2->right) + 1;
    temp->Heigth = Heigth(temp->left) >= K2->Heigth ? Heigth(temp->left) + 1 : K2->Heigth + 1;
    return temp;
}

Position DoubleRotateWhithLeft(Position K3)
{ //两次单旋转
    K3->left = SingleRotateWhithRight(K3->left);
    return SingleRotateWhithLeft(K3);
}

Position SingleRotateWhithRight(Position K2)
{
    Position temp = K2->right; //根据单旋转的规则改变指向
    K2->right = temp->left;
    temp->left = K2;

    K2->Heigth = Heigth(K2->left) >= Heigth(K2->right) ? Heigth(K2->left) + 1 : Heigth(K2->right) + 1;
    temp->Heigth = Heigth(temp->right) >= K2->Heigth ? Heigth(temp->right) + 1 : K2->Heigth + 1;
    return temp;
}

Position DoubleRotateWhithRight(Position K3)
{ //两次单旋转
    K3->right = SingleRotateWhithLeft(K3->right);
    return SingleRotateWhithRight(K3);
}

Position FindMin(AVLTree T)
{ //递归实现
    if (T == NULL)
        return NULL;
    if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}

AVLTree Delete(int x, AVLTree T)
{ //删除操作跟之前的搜索时一样,只不过在后面增加了一个判断平衡的条件
    Position P;
    if (T == NULL)
        return NULL;
    else if (x < T->Element)
        T->left = Delete(x, T->left); //将当前节点的左子树指向删除x后的左子树
    else if (x > T->Element)
        T->right = Delete(x, T->right);
    else if (T->left && T->right)
    {
        //如果两个儿子都存在,先找到右子树最小的,用其代替当前节点的关键字,然后再递归删除右子树最小节点
        P = FindMin(T->right);
        T->Element = P->Element;
        T->right = Delete(P->Element, T->right);
    }
    else
    { //如果只有一个儿子或者没有儿子
        P = T;
        if (T->left == NULL&&T->right)
            T = T->right; //改变子树的指向,返回的时候T的指向已经改变了
        else if (T->right == NULL&&T->left)
            T = T->left;
        else
            T=NULL;
        free(P); //释放原有树节点的空间
    }
    if(T){
        if (Heigth(T->left) - Heigth(T->right) == 2)
        {
            if (Heigth(T->left->left) > Heigth(T->left->right))
                T = SingleRotateWhithLeft(T);
            else if (Heigth(T->left->right) > Heigth(T->left->left))
                T = DoubleRotateWhithLeft(T);
        }
        else if (Heigth(T->right) - Heigth(T->left) == 2)
        {
            if (Heigth(T->right->left) > Heigth(T->right->right))
                T = DoubleRotateWhithRight(T);
            else if (Heigth(T->right->right) > Heigth(T->right->left))
                T = SingleRotateWhithRight(T);
        }
        T->Heigth = Heigth(T->left) >= Heigth(T->right) ? Heigth(T->left) + 1 : Heigth(T->right) + 1;
    }
    
    return T;
}

void PtrTree(AVLTree T)
{
    if (T->left)
        PtrTree(T->left);
    if (T->right)
        PtrTree(T->right);
    printf("%d ", T->Element);
}

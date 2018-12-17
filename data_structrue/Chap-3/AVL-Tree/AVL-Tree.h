struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;


//查找和之前没什么区别
AVLTree MakeEmpty(AVLTree T);
Position SingleRotateWhithLeft(Position K2);  //情景1
Position SingleRotateWhithRight(Position K2); //情景4
Position DoubleRotateWhithLeft(Position K3);  //情景2
Position DoubleRotateWhithRight(Position K3); //情景3
AVLTree Insert(int x,AVLTree T);
AVLTree Delete(int x,AVLTree T);
void PtrTree(AVLTree T);

struct AVLNode
{
    int Element;
    AVLTree left;
    AVLTree right;
    int Heigth;
};

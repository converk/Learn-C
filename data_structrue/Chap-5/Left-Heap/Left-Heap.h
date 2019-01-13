struct TreeNode; //由于是一棵二叉树,所以使用树节点来进行声明
typedef struct TreeNode* LeftHeap;

LeftHeap InitHeap(void);
LeftHeap Insert1(int InsertElement, LeftHeap L); //这两个需要宏定义来与二叉堆保持一致
LeftHeap DeleteMin1(LeftHeap L);
LeftHeap Merge(LeftHeap L1, LeftHeap L2);
int IsEmpty(LeftHeap L);
void PtrHeap(LeftHeap L);

#define Insert(X, L) (L = Insert1((X), L)) //宏定义函数,看起来不用返回值
#define DeleteMin(L) (L = DeleteMin1(L))

struct TreeNode {
    int Element;
    LeftHeap left;
    LeftHeap rigth;
    int NPL;
};

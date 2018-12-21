// 这里取M的阶数为4

#define M 4 //阶数
#define LIMIT_M_2 2 

struct BTreeNode;
typedef struct BTreeNode *BTree,*Position;
typedef int keytype;   //定义数据的类型名

struct BTreeNode
{
    int keynum;   //定义这个节点所包含的关键词的个数
    keytype key[M+1];    //定义一个节点内存储的数据,把第一个儿子的最小值也包含了进去
    BTree Childerns[M+1];  //定义指向四个孩子节点的指针
};

BTree InitBtree();  //初始化一棵树
BTree Insert(keytype x,BTree T);  //插入节点
BTree Delete(keytype x,BTree T);  //删除节点
BTree Destroy(keytype x, BTree T);  //销毁一棵树
void PtrTree(BTree T);   //打印节点
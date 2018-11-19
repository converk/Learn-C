struct Node;
typedef struct Node *Stack;
typedef struct Node *Position;

int IsEmpty(Stack S);              //判断是否为空
int IsFull(Stack S);               //判断是否满栈
Stack CreatStack(int MaxElements); //创建一个新栈
void DisposeStack(Stack S);        //释放栈空间
void MakeEmpty(Stack S);           //清空一个栈,保留头结点
void Push(int x, Stack S);         //插入一个元素,只能插入在头部位置
void Pop(Stack S);                 //删除第一个元素
void PrtStack(Stack S);            //打印栈

#define MinStackSize 5
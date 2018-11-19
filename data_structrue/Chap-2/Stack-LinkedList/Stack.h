struct Node;
typedef struct Node* Stack;
typedef struct Node* Position;

int IsEmpty(Stack S);       //判断是否为空
Stack CreatStack(void);     //创建一个新栈
void DisposeStack(Stack S); //消除一个栈
void MakeEmpty(Stack S);    //清空一个栈,保留头结点
void Push(int x, Stack S);  //插入一个元素,只能插入在头部位置
void Pop(Stack S);          //删除第一个元素
void PrtStack(Stack S);     //打印栈

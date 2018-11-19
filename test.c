//数组实现栈
#include <stdio.h>
#include <stdlib.h>

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

struct Node
{
    int Capacity;   //最长栈的个数
    int TopOfStack; //栈顶元素,为-1时为空栈
    int *Array;
};

int main(void)
{
    Stack S;
    int flag = 0;

    //初始化创建栈
    S = CreatStack(8);

    //判断是否为空
    flag = IsEmpty(S);
    printf("%d\n", flag);

    //添加元素
    for (int i = 0; i < 8; Push(i, S), i++)
        ;
    PrtStack(S);

    //判断是否满
    flag = IsFull(S);
    printf("%d\n", flag);

    //删除第一个元素
    Pop(S);
    PrtStack(S);

    //释放栈空间
    DisposeStack(S);
    PrtStack(S);

    return 0;
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == -1;
}

int IsFull(Stack S)
{
    return S->TopOfStack >= S->Capacity - 1;
}

Stack CreatStack(int MaxElements)
{
    Stack S;
    if (MaxElements < MinStackSize)
    {
        puts("the stack is too small!!");
        return NULL;
    }
    S->Array = malloc(sizeof(int) * MaxElements);
    if (S->Array == NULL)
        return NULL;
    S->Capacity = MaxElements;
    S->TopOfStack = -1;
    return S;
}

void DisposeStack(Stack S)
{
    if (S)
    {
        free(S->Array); //先释放数组空间
        free(S);        //再释放栈空间
    }
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = -1;
}

void Push(int x, Stack S)
{
    if (!IsFull(S))
    {
        S->TopOfStack += 1;
        S->Array[S->TopOfStack] = x;
    }
    else
    {
        puts("the stack is full");
    }
}

void Pop(Stack S)
{
    if (!IsEmpty(S))
    {
        S->TopOfStack--;
    }
    else
    {
        puts("the stack is Empty");
    }
}

void PrtStack(Stack S)
{
    int index = 0;
    if (!IsEmpty(S))
        while (index <= S->TopOfStack)
            printf("%d ", S->Array[index++]);
    printf("\n");
}

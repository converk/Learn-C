//数组实现栈
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"


struct Node
{
    int Capacity;     //最长栈的个数
    int TopOfStack;   //栈顶元素,为-1时为空栈
    int *Array;
};


int main(void){
    Stack S;
    int flag=0;

    //初始化创建栈
    S=CreatStack(8);

    //判断是否为空
    flag=IsEmpty(S);
    printf("%d\n",flag);

    //添加元素
    for (int i=0;i<8;Push(i,S),i++);
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

int IsEmpty(Stack S){
    return S->TopOfStack==-1;
}

int IsFull(Stack S){
    return S->TopOfStack>=S->Capacity-1;
}

Stack CreatStack(int MaxElements)
{
    Stack S;
    if(MaxElements<MinStackSize){
        puts("the stack is too small!!");
        return NULL;
    }
    S=malloc(sizeof(struct Node));  //这里注意要先malloc整个结构,再给数组分配空间
    if (S == NULL)
        return NULL;
    S->Array=malloc(sizeof(int)*MaxElements);
    //初始化的时候就确定了大小
    if(S->Array==NULL)
        return NULL;
    S->Capacity=MaxElements;
    S->TopOfStack=-1;
    return S;
}

void DisposeStack(Stack S){
    if(S){
        free(S->Array);   //先释放数组空间
        free(S);     //再释放栈空间
    }
}

void MakeEmpty(Stack S){
    S->TopOfStack=-1;
}

void Push(int x, Stack S){
    if(!IsFull(S)){
        S->TopOfStack+=1;
        S->Array[S->TopOfStack]=x;
    }
    else{
        puts("the stack is full");
    }
}

void Pop(Stack S){
    if(!IsEmpty(S)){
        S->TopOfStack--;
    }
    else
    {
        puts("the stack is Empty");
    }
}

void PrtStack(Stack S){
    int index=0;
    if(!IsEmpty(S))
        while(index<=S->TopOfStack)
            printf("%d ",S->Array[index++]);
    printf("\n");
}

//链表实现栈
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

struct Node{
    int Element;
    Stack Next;
};

int main(void){
    Stack S;

    //创建一个栈
    S=CreatStack();

    //插入几个元素
    for(int i = 0;i<=6;i++)
        Push(i,S);
    PrtStack(S);

    //删除第一个元素
    Pop(S);
    PrtStack(S);

    //清空栈
    MakeEmpty(S);
    PrtStack(S);

    return 0;
}

int IsEmpty(Stack S){
    return S->Next==NULL;
}

Stack CreatStack(void){
    Stack S;
    S=malloc(sizeof(struct Node));
    if(!S)
        puts("there is not space!!!!");
    S->Next=NULL;
    return S;
}

void Push(int x, Stack S){
    Position P;
    P=malloc(sizeof(struct Node));
    if(!P){
        puts("there is no space");
        return;
    }
    else{
        P->Element = x;
        P->Next = S->Next;
        S->Next = P;
    }
}

void Pop(Stack S){
    if(IsEmpty(S)){
        puts("the stack is empty,you can't pop it");
        return;
    }
    Position P=S->Next;
    S->Next=P->Next;
    free(P);
}

void MakeEmpty(Stack S){
    if(S==NULL){
        puts("you should creat a stack");
        return;
    }   //不要忘了判断   
    else
        while(!IsEmpty(S))
            Pop(S);
}
void PrtStack(Stack S){
    Position P=S->Next;
    while(P){
        printf("%d ",P->Element);
        P=P->Next;
    }
    printf("\n");
}
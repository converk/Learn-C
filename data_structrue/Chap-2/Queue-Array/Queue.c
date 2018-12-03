#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

struct QueueArray
{
    int head;     //头位置
    int tail;     //尾位置
    int size;     //最大尺寸
    int Capacity; //目前的元素个数
    int *Array;   //队列主体
};


int main(void){
    Queue Q;

    //创建队列
    Q=CreatQueue(10);

    //判断是否是空的
    int flag=IsEmpty(Q);
    printf("isempty: %d\n",flag);

    //初始化队列
    for(int i=0;i<7;i++)
        EnQueue(i,Q);
    fputs("初始化:",stdout);
    PrtQueue(Q);
    
    //判断是否是满的
    flag = IsFull(Q);
    printf("isfull: %d\n", flag);

    //插入元素
    EnQueue(10,Q);
    fputs("插入一个元素:", stdout);
    PrtQueue(Q);

    //删除一个元素
    DeQueue(Q);
    fputs("删除一个元素:", stdout);
    PrtQueue(Q);

    //置空队列
    MakeEmpty(Q);
    printf("置空队列:");
    PrtQueue(Q);

    //删除队列
    Diospose(Q);

    return 0;
}

int IsEmpty(Queue Q){
    return Q->Capacity==0;
}

int IsFull(Queue Q){
    return Q->Capacity==Q->size;
}

Queue CreatQueue(int MaxElements){
    Queue Q;
    Q=malloc(sizeof(struct QueueArray));
    if(Q==NULL)
        return NULL;
    Q->Array=malloc(sizeof(int)*MaxElements);
    Q->size=MaxElements;
    Q->Capacity=0;
    Q->head=0;
    Q->tail=0;
    return Q;
}

void Diospose(Queue Q){
    if(Q!=NULL){
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q){
    if(Q){
        Q->head=0;
        Q->tail=0;
    }
}

void EnQueue(int x, Queue Q){
    if(!IsFull(Q)){
        for (int i = Q->head;i>Q->tail;i--){
            Q->Array[i]=Q->Array[i-1];
        }
        Q->Array[0]=x;
        Q->Capacity++;
        Q->head++;
    }
}

void DeQueue(Queue Q){
    if(!IsEmpty(Q)){
        Q->head--;
        Q->Capacity--;
    }
}

void PrtQueue(Queue Q){
    if(!IsEmpty(Q)){
        for(int i=Q->tail;i<Q->head;i++)
            printf("%d ",Q->Array[i]);
    }
    printf("\n");
}

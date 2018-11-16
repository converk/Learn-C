//线性存储

#include<stdio.h>
#include<stdlib.h>
#include"Linear.h"

struct LinearTable
{
    int Data[LEN];
    int len;
};

int main(){
    List L;

    //初始化
    L=MakeEmpty();
    for(int i=0; i<6; i++){  //初始化
        L->Data[i]=i;
        L->len++;
    }
    PtrList(L);

    //根据坐标查找;
    printf("FindKth %d\n",FindKth(3,L));

    //根据值查找
    printf("Find %d\n", Find(3, L));

    //插入
    Insert(10,3,L);
    PtrList(L);

    //删除
    Delete(4,L);
    PtrList(L);

    return 0;
}

List MakeEmpty(){
    List L;
    L=(List)malloc(sizeof(struct LinearTable));
    L->len=0;  //初始化长度
    return L;
}

int FindKth(int k, List L){
    return L->Data[k];
}

int Find(int x, List L){
    int i;
    for (i = 0; i < L->len&&L->Data[i] != x; i++)
    if(i>=L->len)
        return -1;
    return i;
}

void Insert(int x, int k, List L){
    if(L->len>=LEN)
        return;
    if(k<0||k>=L->len){
        puts("k值不合法!!!");
        return;
    }
    int index=L->len-1;
    while(index>=k){
        L->Data[index+1]=L->Data[index];
        index--;
    }
    L->Data[k]=x;
    L->len++;    //别忘了这个
}

void Delete(int k, List L){
    if (k < 0 || k >= L->len){
        puts("k值不合法!!!");
        return;
    }
    int index=k+1;
    while(index<=L->len-1){
        L->Data[index-1]=L->Data[index];
        index++;
    }
    L->len--;
    return;
}

void PtrList(List L){
    for(int i=0; i<L->len; i++)
        printf("%d ", L->Data[i]);
    printf("\n");
}

int Length(List L){
    return L->len;
}
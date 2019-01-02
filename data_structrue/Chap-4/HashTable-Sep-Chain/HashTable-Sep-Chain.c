#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "HashTable-Sep-Chain.h"

static Index Hash(int key, int TableSize){  //哈希函数,寻找索引
    return key % TableSize;
}

HashTable InitHashtable(int Tablesize){
    HashTable H;
    if(Tablesize<MinSize){
        puts("the size you enter is too small");
        return NULL;
    }
    H=malloc(sizeof(struct HashTle));   //为哈希表分配空间
    if(!H)
        puts("there is no space");
    H->TableSize=Tablesize;
    H->ListHead=malloc(sizeof(List)*Tablesize);   //为哈希表里面的表头数组分配空间
    if(!H->ListHead)
        puts("there is no space for H->ListHead");
    for(int i=0;i<H->TableSize;i++){
        H->ListHead[i]=malloc(sizeof(struct ListNode));    //为表头数组里面每一个表头分配空间
        if(!H->ListHead[i])
            puts("there is no space for H->ListHead[i]");
        else
            H->ListHead[i]->Next=NULL;  //初始化哈希表里面的表头指针
    }
    return H;
}

Position Find(int x, HashTable H){
    Position Key=NULL;   //返回的找到的元素的位置,没有则返回NULL
    Index index = Hash(x, H->TableSize); //得到如果x存在那么在哈希表里面的索引应该是多少
    List L = H->ListHead[index];         //哈希表的每一个元素都是一个List

    Key = L->Next;
    while (Key != NULL){
        if(Key->Element==x)
            break;
        Key=Key->Next;
    }
    return Key;
}

HashTable Insert(int x, HashTable H){
    Index index = Hash(x, H->TableSize);
    if(Find(x,H))
        return NULL;
    else{
        List L=H->ListHead[index];
        Position P=malloc(sizeof(struct ListNode));
        P->Next=L->Next;
        P->Element=x;
        L->Next=P;
    }
    return H;
}

void DestroyHashTable(HashTable H){
    Position P1,P2;
    List L;
    if(H){
        for(int i=0;i<H->TableSize;i++){
            L=H->ListHead[i];
            P1=P2=L->Next;
            while(P2){
                P1=P2;
                P2=P2->Next;
                free(P1);
            }
            free(L);
        }
        free(H);
    }
}

static Position FindPrevious(int x,HashTable H){
    Position Key = NULL;                 //返回的找到的元素的位置,没有则返回NULL
    Index index = Hash(x, H->TableSize); //得到如果x存在那么在哈希表里面的索引应该是多少
    List L = H->ListHead[index];         //哈希表的每一个元素都是一个List
    Key = L;
    while (Key->Next != NULL)
    {
        if (Key->Next->Element == x)
            break;
        Key = Key->Next;
    }
    return Key;
}

HashTable Delete(int x, HashTable H){
    Position P=FindPrevious(x,H);
    if(P->Next){    //只有当这个位置存在的时候才进行删除
        Position DeleteNode=P->Next;
        P->Next=P->Next->Next;
        free(DeleteNode); 
    }
    return H;
}

void PtrHashtable(HashTable H){
    if(H){
        for(int i=0; i<H->TableSize; i++){
            List L=H->ListHead[i];
            Position P=L->Next;
            printf("(%d) ",i);
            while (P){
                printf("%d ",P->Element);
                P=P->Next;
            }
        }
    }
}
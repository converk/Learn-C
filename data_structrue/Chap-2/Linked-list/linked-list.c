#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"

struct Node
{
    int Element;
    Position Next;
};

int main(void)
{
    List L;
    Position P;
    int InsertElement = 10;
    int DeleteElement = 10;
    int FindElement=6;

    //创建空表
    L = MakeEmpty();

    //插入元素
    P = L;
    for (int i = 0; i < 5; P = P->Next, i++);
    Insert(InsertElement, L, P);
    PtrList(L);

    //删除元素
    Delete(DeleteElement, L);
    PtrList(L);

    //查找元素或前面那个元素
    P = FindPrevious(FindElement,L);
    printf("%d\n", P->Element);

    //删除表;
    DeleteList(L);
    PtrList(L);

    return 0;
}

List MakeEmpty()
{
    Position Ltail, Lhead; //头结点和尾节点
    Position Lnew;         //一个新节点
    Lhead = malloc(sizeof(struct Node));
    Ltail = Lhead;
    Ltail->Next = NULL;
    for (int i = 0; i < LEN; i++)
    {
        Lnew = malloc(sizeof(struct Node));
        Lnew->Element = i;
        Lnew->Next = NULL;
        Ltail->Next = Lnew;
        Ltail = Ltail->Next;
    }
    return Lhead;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(int x, List L)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != x)
        P = P->Next;
    return P;
}

void Delete(int x, List L)
{
    Position P, temp;
    P = FindPrevious(x, L);
    if (!IsLast(P, L))
    { //这里要判断是否是最后一个元素
        temp = P->Next;
        P->Next = temp->Next;
        free(temp);
    }
}

Position FindPrevious(int x, List L)
{
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != x)
        P = P->Next;
    return P;
}

void Insert(int x, List L, Position P)
{
    Position temp;
    temp = malloc(sizeof(struct Node));
    if (temp == NULL)
        puts("There is no space!!!!");
    temp->Element = x;
    temp->Next = P->Next;
    P->Next = temp;
}

void DeleteList(List L)
{
    Position P;
    while (L)
    {
        P = L->Next; //先定义一个元素用来存储下一个元素的位置
        free(L);
        L = P;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

void PtrList(List L)
{
    Position P = L->Next;
    while (P)
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}
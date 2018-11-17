#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List; //头节点
typedef PtrToNode Position;

struct Node
{
    int Element;
    Position Next;
};

#define LEN 81

List MakeEmpty();                    //创建空表
List MergeTwoList(List L1, List L2); //合并表
void Insert(int x, List L, Position P);
void PtrList(List L);

int main(void)
{
    List L1, L2, L3;
    Position P;
    L1 = MakeEmpty();
    L2 = MakeEmpty();
    int Element;

    //初始化L1
    P = L1;
    scanf("%d", &Element);
    //Element = 0;
    while (Element != -1)
    {
        Insert(Element, L1, P);
        P = P->Next;
        scanf("%d", &Element);
    }

    //初始化L2
    P = L2;
    scanf("%d", &Element);
    //Element = 0;
    while (Element != -1)
    {
        Insert(Element, L2, P);
        P = P->Next;
        scanf("%d", &Element);
    }

    L3 = MergeTwoList(L1, L2);
    PtrList(L3);

    return 0;
}

List MakeEmpty()
{
    Position Ltail, Lhead; //头结点和尾节点
    Position Lnew;         //一个新节点
    Lhead = malloc(sizeof(struct Node));
    Ltail = Lhead;
    Ltail->Next = NULL;
    return Lhead;
}

List MergeTwoList(List L1, List L2)
{
    List L3;
    Position P1, P2, P3;
    L3 = MakeEmpty();
    P1 = L1->Next;
    P2 = L2->Next;
    P3 = L3;
    while (P1 != NULL && P2 != NULL)
    {
        if (P1->Element <= P2->Element)
        {
            Insert(P1->Element, L3, P3);
            P1 = P1->Next;
        }
        else
        {
            Insert(P2->Element, L3, P3);
            P2 = P2->Next;
        }
        P3 = P3->Next;
    }
    if (!P1)
    {
        while (P2)
        {
            Insert(P2->Element, L3, P3);
            P2 = P2->Next;
            P3 = P3->Next;
        }
    }
    if (!P2)
    {
        while (P1)
        {
            Insert(P1->Element, L3, P3);
            P1 = P1->Next;
            P3 = P3->Next;
        }
    }

    return L3;
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
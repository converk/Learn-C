#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *Queue;
typedef struct Node *Position;

int IsEmpty(Queue Q);
Queue CreatQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(int x, Queue Q);
void Dequeue(Queue Q);
void PrtQueue(Queue Q);

struct Node
{
    int Element;
    Queue Next;
};

int main(void)
{
    Queue Q;
    int flag;

    //创建一个栈
    Q = CreatQueue();

    //判断是否为空
    flag = IsEmpty(Q);
    printf("%d\n", flag);

    //插入几个元素
    for (int i = 0; i <= 6; i++)
        Enqueue(i, Q);
    PrtQueue(Q);

    //删除第一个元素
    Dequeue(Q);
    PrtQueue(Q);
}

int IsEmpty(Queue Q)
{
    return Q->Next == NULL;
}

Queue CreatQueue(void)
{
    Queue Q;
    Q = malloc(sizeof(struct Node));
    Q->Next = NULL;
    return Q;
}

void DisposeQueue(Queue Q)
{
    Position h1 = Q;
    Position h2 = h1->Next;
    if (!IsEmpty(Q))
    {
        while (h2)
        {
            h1 = h2;
            h2 = h2->Next;
            free(h1);
        }
    }
    free(Q);
}

void Enqueue(int x, Queue Q)
{
    Position temp;
    temp=malloc(sizeof(struct Node));
    temp->Element = x;
    temp->Next = Q->Next;
    Q->Next = temp;
}

void Dequeue(Queue Q)
{
    Position tail = Q;
    if (!IsEmpty(Q))
    {
        while (tail->Next->Next)
            tail = tail->Next;
        tail->Next = NULL;
    }
}

void PrtQueue(Queue Q)
{
    Position P = Q->Next;
    while (P)
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}
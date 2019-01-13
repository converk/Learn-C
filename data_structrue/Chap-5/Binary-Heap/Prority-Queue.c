#include "Prority-Queue.h"
#include <stdio.h>
#include <stdlib.h>

ProrityQueue InitHeap(int MaxSize)
{
    if (MaxSize < MinSize) {
        printf("The size is Too small");
        return NULL;
    }
    ProrityQueue H = malloc(sizeof(struct HeapStruct));
    if (!H) {
        perror("the is no space for H");
        return NULL;
    }
    H->Elemnets = malloc(sizeof(int) * (MaxSize + 1));
    if (!H->Elemnets) {
        perror("the is no space for H->elements");
        return NULL;
    }
    H->MaxSize = MaxSize;
    H->NowSize = 0;
    H->Elemnets[0] = -999; //放一个足够小的值
    return H;
}

int IsEmpty(ProrityQueue H)
{
    return H->NowSize == 0;
}
int IsFull(ProrityQueue H)
{
    return H->NowSize == H->MaxSize;
}

void Insert(ProrityQueue H, int InsertElement)
{
    int index = H->NowSize + 1;

    if (IsFull(H))
        return;

    for (; H->Elemnets[index / 2] > InsertElement; index = index / 2)
        H->Elemnets[index] = H->Elemnets[index / 2];
    H->Elemnets[index] = InsertElement;
    H->NowSize++;
}

int DeleteMin(ProrityQueue H)
{
    if (IsEmpty(H))
        return -1;
    int Minkey = H->Elemnets[0];
    int lastkey = H->Elemnets[H->NowSize]; //先获得最后一个元素,是删除之后要插入的
    H->NowSize--; //删除最后一个元素

    int child; //用来标记下一个下滤的儿子是哪一个
    int i; //用来标记当前节点
    for (i = 1; 2 * i <= H->NowSize; i = child) {
        child = 2 * i; //默认是第一个孩子

        if (child != H->NowSize && H->Elemnets[child] > H->Elemnets[child + 1])
            child++; //如果右儿子小于左儿子,那么把下一个下滤的节点从左儿子改到右儿子

        if (H->Elemnets[child] < lastkey) //拿下一个孩子的值和最后一个元素进行比较
            H->Elemnets[i] = H->Elemnets[child];
        else
            break; //如果最后一个元素的值小与两个儿子的值,那么就可以直接插入
    }
    H->Elemnets[i] = lastkey;
    return Minkey;
}

void DecreaseKey(int index, int change, ProrityQueue H)
{
    int temp = H->Elemnets[index] - change;
    for (; H->Elemnets[index / 2] > H->Elemnets[index]; index = index / 2)
        H->Elemnets[index] = H->Elemnets[index / 2];
    H->Elemnets[index] = temp;
}

void IncreaseKey(int index, int change, ProrityQueue H)
{
    int temp = H->Elemnets[index] + change;

    int child, i;
    for (i = index; 2 * i <= H->NowSize; i = child) {
        child = 2 * i;
        if (child != H->NowSize && H->Elemnets[child] > H->Elemnets[child + 1])
            child++; //如果右儿子小于左儿子,那么把下一个下滤的节点从左儿子改到右儿子

        if (H->Elemnets[child] < temp) //拿下一个孩子的值和最后一个元素进行比较
            H->Elemnets[i] = H->Elemnets[child];
        else
            break; //如果最后一个元素的值小与两个儿子的值,那么就可以直接插入
    }
    H->Elemnets[i] = temp;
}

ProrityQueue BuildHeap(int* array, int N)
{
    ProrityQueue H = InitHeap(2 * N); //初始化一个堆用来储存新建的堆
    H->NowSize = N;

    int child; //儿子的索引
    int temp;

    for (int i = N / 2; i > 0; i--) {
        for (int j = i; 2 * j < N; j = child) {
            child = 2 * j;
            if (child != N && array[child] > array[child + 1])
                child++;
            if (array[j] > array[child]) { //交换父亲与儿子的值
                temp = array[j];
                array[j] = array[child];
                array[child] = temp;
            } else
                break;
        }
    }
    H->Elemnets = array;
    return H;
}

void PtrHeap(ProrityQueue H)
{
    for (int i = 1; i <= H->NowSize; i++)
        printf("%d ", H->Elemnets[i]);
    printf("\n");
}
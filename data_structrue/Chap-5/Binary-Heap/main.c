#include "Prority-Queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    ProrityQueue H;

    //初始化一个堆
    H = InitHeap(30);

    //为堆添加元素
    for (int i = 20; i > 0; i--)
        Insert(H, i);
    fputs("Insert: ", stdout);
    PtrHeap(H);

    //删除一个最小元素
    for (int i = 0; i < 5; i++)
        DeleteMin(H);
    fputs("DeleteMin: ", stdout);
    PtrHeap(H);

    //增大一个元素的值
    IncreaseKey(7, 20, H);
    fputs("IncereaseKey: ", stdout);
    PtrHeap(H);

    //新建一个堆
    int array[20];
    array[0] = -999; //一个足够小的数
    for (int i = 19; i > 0; i--)
        array[20 - i] = i;
    printf("Array: ");
    for (int i = 1; i < 20; i++)
        printf("%d ", array[i]);

    printf("\n");
    fputs("ArrayHeap", stdout);
    PtrHeap(BuildHeap(array, 19));
    return 0;
}

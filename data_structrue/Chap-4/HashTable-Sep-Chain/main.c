#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable-Sep-Chain.h"

int main(int argc, char const *argv[])
{
    HashTable H;


    //初始化哈希表
    H=InitHashtable(10);

    //插入元素
    for(int i=0;i<15;i++)
        Insert(i*i,H);
    fputs("begin:",stdout);
    PtrHashtable(H);
    printf("\n");

    //删除元素
    for(int i=6;i<9;i++)
        Delete(i*i,H);
    fputs("Delete:", stdout);
    PtrHashtable(H);
    printf("\n");

    //插入一个重复元素
    Insert(10 *10, H);
    fputs("Insert10:", stdout);
    PtrHashtable(H);
    printf("\n");

    //删除一个不存在的元素

    Delete(6 * 6, H);
    fputs("Delete6:", stdout);
    PtrHashtable(H);
    printf("\n");

    //摧毁哈希表
    DestroyHashTable(H);

    return 0;
}

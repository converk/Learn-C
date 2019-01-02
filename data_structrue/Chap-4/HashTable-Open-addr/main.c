#include "HashTable-Open-addr.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    HashTable H;
    //初始化
    H=InitHashTable(90);

    //插入
    // srand((unsigned)time(NULL));
    for(int i=523;i<562;i++)
        Insert(i,H);
    fputs("Insert:", stdout);
    PtrHashTable(H);
    printf("\n");

    //查找
    Position pos=Find(548,H);
    fputs("Find28:", stdout);
    printf("%d\n",pos);

    //删除一个
    Delete(528,H);
    fputs("Delete528:", stdout);
    PtrHashTable(H);
    printf("\n");

    //摧毁
    DestroyHashTable(H);
    fputs("Destroy:", stdout);
    PtrHashTable(H);
    printf("\n");

    return 0;
}

#include "HashTable-Open-addr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static Index Hash(int Key, int TableSize){   //哈希函数,返回关键字索引
    return Key % TableSize;
}
static int ConflictResolution(int i){
    return i*i;
}

HashTable InitHashTable(int TableSize){
    HashTable H;
    if(TableSize<SIZE){
        puts("the size is too small");
        return NULL;
    }
    H=malloc(sizeof(struct HashTbl));
    H->TableSize=TableSize;
    H->TheCells=malloc(sizeof(struct HashEntry)*TableSize);

    for(int i=0;i<H->TableSize;i++)
        H->TheCells[i].Info=Empty;    //初始化每个元素都为空
    return H;
} //初始化哈希表

void DestroyHashTable(HashTable H){
    if(H){
        free(H->TheCells);  //直接释放数组,然后再释放整个哈希表
        free(H);
    }
}

Position Find(int x, HashTable H){
    Index Currentindex=Hash(x,H->TableSize);

    //这里就要考虑到继续向前寻找的条件:
    //当前位置的Element不等于x或者当前位置的状态不为空,如果为空的话,肯定之后找不到了
    //终止的条件就是达到上面两个条件的任何一个
    //对于两个条件的判断顺序,如果是空的就不用管,因为空的里面不会有Element,如果不是空的,就可能有元素,
    //这里不需要考虑当前位置的节点已经被删除,因为这样也会返回这个位置,对于插入来说是无所谓的
    for (int i = 0; H->TheCells[Currentindex].Info != Empty && H->TheCells[Currentindex].Element!=x;i++){
        Currentindex+=ConflictResolution(i);  //加上解决冲突的平方项
        if(Currentindex>=H->TableSize)
            Currentindex-=H->TableSize;
    }
    return Currentindex;
}

HashTable Insert(int x, HashTable H){
    Position pos=Find(x,H);
    if(H->TheCells[pos].Info!=Legitimate){  //如果是已经删除或者为空的话都可以进行插入
        H->TheCells[pos].Info = Legitimate;
        H->TheCells[pos].Element=x;
    }
    return H;
}

HashTable Delete(int x, HashTable H){
    Position pos = Find(x, H);
    if(H->TheCells[pos].Info==Legitimate)
        H->TheCells[pos].Info=Deleted;
    return H;
}

void PtrHashTable(HashTable H){
    if(H)
        for (Index index = 0;index<H->TableSize;index++)
            if(H->TheCells[index].Info==Legitimate)
                printf("(%d):%d  ",index,H->TheCells[index].Element);
}

//这里只需要关注这个算法怎么实现,至于在什么条件下调用这个函数就是主函数里面的逻辑
HashTable ReHash(HashTable H){
    int OldTableSize=H->TableSize;   //之前的尺寸
    Cell *OldCell=H->TheCells;  //之前的哈希表里面的数据 

    H=InitHashTable(2*OldTableSize);  //让指针指向新初始化的哈希表,但是原来哈希表里面的空间还存在
    for(int i=0;i<OldTableSize;i++){
        if(OldCell[i].Info==Legitimate)
            Insert(OldCell[i].Element,H);
    }
    return H;
}
#include <stdio.h>

#define SetSizes 10

typedef int DisSet[SetSizes + 1]; //不相交集的类型,也是一个森林
typedef int SetType; //每个class的名字类型
typedef int ElementType; //不相交集里面每个元素类型

void InitSet(DisSet S); //初始化一个不相交集
void SetUnion_1(DisSet S, SetType Root1, SetType Root2); //合并两个类的操作(较差)
void SetUnion_2(DisSet S, SetType Root1, SetType Root2); //合并两个类的操作(按照高度改进)
void SetUnion_3(DisSet S, SetType Root1, SetType Root2); //合并两个类的操作(按照大小改进)
SetType Find_1(DisSet S, ElementType X); //查找某一个元素所在的类
SetType Find_2(DisSet S, ElementType X); //查找某一个元素所在的类(路径压缩)

void InitSet(DisSet S)
{
    for (int i = SetSizes; i > 0; i--)
        S[i] = 0; //初始化每个类的高度
}

void SetUnion_1(DisSet S, SetType Root1, SetType Root2)
{
    S[Root1] = Root2;
}

void SetUnion_2(DisSet S, SetType Root1, SetType Root2)
{ //按照高度进行合并,小的高度向大的高度合并,使得最终生成的树,的高度不会超过logN
    if (S[Root1] < S[Root2])
        S[Root2] = Root1;
    else {
        if (S[Root1] == S[Root2])
            S[Root2]--;
        S[Root1] = Root2;
    }
}

void SetUnion_3(DisSet S, SetType Root1, SetType Root2)
{ //按照类节点儿子的个数来合并,小的合并大的,儿子的个数用负数来表示
    if (S[Root1] < S[Root2]) { //1的儿子数比2多,
        S[Root2] = Root1;
        S[Root1] += (S[Root2] - 1);
    } else { //2的儿子数比1多
        S[Root1] = Root2;
        S[Root2] += (S[Root1] - 1);
    }
}

SetType Find_1(DisSet S, ElementType X)
{
    if (S[X] <= 0) //说明是根节点,负的表示高度
        return X;
    else
        return Find_1(S, S[X]); //继续向上查找,然后递归返回
}

SetType Find_2(DisSet S, ElementType X)
//路径压缩,这个算法与按高度求并并不完全兼容,因为没有更新高度,
//但是与按大小求并是兼容的,因为路径压缩并不会改变一个类里面元素的大小个数
{
    if (S[X] <= 0) //说明是根节点,负的表示高度
        return X;
    else
        return S[X] = Find_1(S, S[X]); //继续向上查找,然后递归返回,并且标记相应的元素属于哪一类
}
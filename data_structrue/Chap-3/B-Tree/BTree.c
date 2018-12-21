#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include"BTree.h"

#define USELESS -1   //没有用的参数

static BTree MallocNewNode(){   //一个新节点
    BTree T;
    T=malloc(sizeof(struct BTreeNode));
    if(!T)
        exit(EXIT_FAILURE);  //获取空间失败,退出程序
    for(int i=0;i<M+1;i++){
        T->key[i] = USELESS;
        T->Childerns[i]=NULL;
    }
    T->keynum=0;
    return T;
}

BTree InitBtree(){
    BTree T=MallocNewNode();
    return T;
}

//查找要插入的节点的兄弟节点还没有满的情况,返回没有满的兄弟节点的Position指针
//如果全都满了,返回NULL,i是要插入的元素x要插入在Parennt的第几个儿子上(儿子的索引)
static Position FindBrotherNotFull(Position Parent,int i){  
    Position BrotherNotFull=NULL;
    int limit=M;   //限制个数
 
    if(i==0){  //当要插入在第一个儿子节点上的时候
        if(Parent->Childerns[1]->keynum<limit)
            BrotherNotFull=Parent->Childerns[1];
    }
    else if (Parent->Childerns[i - 1]->keynum < limit)  //当它的它一个节点没有满的时候
        BrotherNotFull = Parent->Childerns[i-1];
    else if (Parent->keynum > i + 1 && Parent->Childerns[i + 1]->keynum < limit) //当他的后一个节点没有满的时候
        BrotherNotFull = Parent->Childerns[i + 1];
    return BrotherNotFull;
}

//插入一个元素:key=0,parent是树叶的父节点,X是要插入的相应树叶,Insertkey就是要插入的元素,i是X再parent里面的索引,j是要插入元素在x里面的索引
//插入一个节点:key=0,parent是要被插入的节点,x是插入的节点,i是x在parernt里面要插入的位置,j与InsertKey都没用
static Position InsertElementOrNode(int key,Position Parent,Position X,keytype Insertkey,int i,int j){
    if(!key){
        int k=X->keynum-1;
        while(k>=j){
            X->key[k+1]=X->key[k];
            k--;
        }
        X->key[j]=Insertkey;
        X->keynum++;
        Parent->key[i]=X->key[0];
    }else{
        int k=Parent->keynum-1;
        while(k>=j){
            Parent->Childerns[k + 1] = Parent->Childerns[k];
            Parent->key[k + 1] = Parent->key[k];
            k--;
        }
        Parent->keynum++;
        Parent->key[i]=X->key[0];
        Parent->Childerns[i]=X;
    }
    return X;
}

//参数的意义与上述在一个节点里插入一个元素或者儿子类似
static Position RemoveElementOrNode(int key, Position Parent, Position X, int i, int j){
    int k;
    if(!key){  //删除一个元素
        k=j+1;
        while(k<X->keynum){
            X->key[k-1]=X->key[k];
            k++;
        }
        X->key[X->keynum]=USELESS;
        Parent->key[i]=X->key[0];
        X->keynum--;
    }else{      //删除一个节点
        k=i+1;
        while(k<Parent->keynum){
            Parent->key[k-1]=Parent->key[k];
            Parent->Childerns[k-1]=Parent->Childerns[k];
            k++;
        }
        Parent->key[Parent->keynum]=USELESS;
        Parent->Childerns[Parent->keynum]=NULL;
        Parent->keynum--;
    }
    return Parent;
}

//这个函数是如果元素要插入在src上,并且src满了,而且其他节点没有满,那就把src上的一些元素移动到dst上
static Position MoveElementOrNode(Position src, Position dst, Position Parent, int i)
{
    int SrcFrontDst=1;   //用来标识目的节点和源节点的前后关系
    if(src->key[0]>dst->key[0])
        SrcFrontDst=0;

    Position MoveNode;
    keytype MoveElement;
    //如果源节点在前面
    if(SrcFrontDst){
        if(src->Childerns[0]!=NULL){//判断要移动的是一个元素还是一个节点,这里是一个节点
            MoveNode=src->Childerns[src->keynum-1];
            RemoveElementOrNode(1,src,MoveNode,src->keynum-1,USELESS);  //在源节点上删除相应节点
            InsertElementOrNode(1,dst,MoveNode,USELESS,0,USELESS);   //在兄弟节点上添加节点
        }else{   //移动一个元素的情况
            MoveElement=src->key[src->keynum-1];
            RemoveElementOrNode(1, Parent, src, i, src->keynum - 1);   //在源节点上删除相应元素
            InsertElementOrNode(1, Parent, dst, MoveElement, i + 1, 0); //在兄弟节点上添加元素
        }
        Parent->key[i+1]=dst->key[0];
    }else{
        if (src->Childerns[0] != NULL)
        { //判断要移动的是一个元素还是一个节点,这里是一个节点
            MoveNode = src->Childerns[0];
            RemoveElementOrNode(1, src, MoveNode, 0, USELESS); //在源节点上删除相应节点
            InsertElementOrNode(1, dst, MoveNode, USELESS, dst->keynum, USELESS);  //在兄弟节点上添加节点
        }
        else
        { //移动一个元素的情况
            MoveElement = src->key[0];
            RemoveElementOrNode(0, Parent, src, i, 0);    //在源节点上删除相应元素
            InsertElementOrNode(0, Parent, dst, MoveElement, i - 1, dst->keynum); //在兄弟节点上添加元素
        }
        Parent->key[i] = dst->key[0];   //更新父节点信息
    }
    return Parent;  //最后返回父节点
}


//分裂节点 
//parent是要分裂节点的父亲,X是要分裂的节点, i是x在Parern里面的索引
static Position SplitNode(Position Parent, Position X, int i){
    Position NewNode=MallocNewNode();  //先创造出一个新节点来接收分裂出的节点
    int SplitNum=X->keynum/2;   //分裂的位置
    int limit=X->keynum;   //划分两个节点的时候需要在哪个地方停止
    int k=0;  //对新节点进行索引赋值

    while(SplitNum<limit){
        NewNode->Childerns[k] = X->Childerns[SplitNum];
        NewNode->key[k] = X->key[SplitNum];
        NewNode->keynum++;
        X->keynum--;
        X->key[SplitNum] = USELESS;
        X->Childerns[SplitNum] = NULL;
        SplitNum++;
        k++;
    }
    if(Parent!=NULL){   //若果父亲存在,即X不是根节点,那就直接在父亲上面插入新节点
        InsertElementOrNode(1,Parent,NewNode,USELESS,i+1,USELESS);
    }else{   //如果X是根节点,那么在创建一个节点,将新节点和原来的节点,返回新的根
        Parent = MallocNewNode();
        InsertElementOrNode(1, Parent, X, USELESS, 0, USELESS);
        InsertElementOrNode(1, Parent, NewNode, USELESS, 1, USELESS);

        return Parent;
    }
    return X;
}

//i是x在parent里面的位置
static BTree RescursiveInsert(BTree T, keytype x,int i,Position parent){
    int j=0;
    while(j<T->keynum&&x>=T->key[j]){
        if(x==T->key[j])
            return T;   //滤出重复元素
        j++;
    }
    if(j!=0&&T->Childerns[0]!=NULL)
        j--;  //这是对于在内部节点进行比较的情况,对于树叶,直接在j处插入即可

    //插入操作
    if(T->Childerns[0]==NULL)  //对于节点是树叶
        T=InsertElementOrNode(0,parent,T,x,i,j);
    else{
        RescursiveInsert(T->Childerns[j],x,j,T);
    }

    //进行调整
    if(T->keynum>M){  //插入后需要调整
        Position Slibing;
        if(!parent)//如果T是根节点,那么直接分裂节点
            T=SplitNode(parent,T,i);
        else{
            Slibing=FindBrotherNotFull(parent,i);  //寻找兄弟是不是有没有慢的
            if(Slibing!=NULL){
                MoveElementOrNode(T,Slibing,parent,i);  //将一个元素移动到相邻接点
            }else{
                T=SplitNode(parent,T,i);
            }
        }
    }
    if(parent!=NULL)
        parent->key[i]=T->key[0];
    return T;
}

BTree Insert(keytype key, BTree T)
{
    return RescursiveInsert(T, key, 0, NULL);
}

static void RecursiveTravel(BTree T, int Level)
{
    int i;
    if (T != NULL)
    {
        printf("  ");
        printf("[Level:%d]-->", Level);
        printf("(");

        /* 树叶的Key从0开始，内部节点从1开始 */
        if (T->Childerns[0] == NULL)
            i = 0;
        else
            i = 1;

        while (i < T->keynum) /*  T->Key[i] != Unavailable*/
            printf("%d:", T->key[i++]);
        printf(")");

        Level++;

        i = 0;
        while (i <= T->keynum)
        {
            RecursiveTravel(T->Childerns[i], Level);
            i++;
        }
    }
}

/* 遍历 */
void PtrTree(BTree T)
{
    RecursiveTravel(T, 0);
    printf("\n");
}

int main(){
    BTree T=InitBtree();
    int i = 100;
    while (i > 0)
        T = Insert(i-- ,T);
    PtrTree(T);
    return 0;
}
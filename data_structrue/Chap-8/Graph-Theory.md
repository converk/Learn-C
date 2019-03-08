# 图论算法

1. 给出一些算法解决普通的图论问题
2. 选择合适的数据结构来减少算法的运行时间
3. 深度优先搜索与广度优先搜索

## 定义

G=(V,E),G代表一个图,V是顶点的集合,E是边的集合,每一条边又是两个顶点的集合`e=(v,w)`,  
`一条路径`就是多个连在一起顶点的集合,如果一个顶点有到它自身的路径,那么这条路径一般也叫作**环**,我们要讨论的图一般是无环的,  
**简单路径**: 路径上的所有顶点都是互异的,除了第一个顶点和最后一个顶点可能相同  
**有向图中的圈**: 满足`w1=wN`,即第一个顶点和最后一个顶点相同,并且路径的长度至少为1的简单路径,如果一个有向图中没有圈那么就称这个图为`无圈图(DAG)`,  
**连通**: 在**无向图**中,每个节点到每个其他节点间都存在一条路径,
**强连通的**: 具有连通性质的**有向图**称为强连通的
**弱联通的**: 如果一个有向图去掉方向变为无向图后是连通的,那么这个有向图称为弱连通的
**基础图**: 如果一个有向图不是强连通的,那么称为基础图
**完全图**: 任意两个顶点间都有一条路径

## 表示

可以使用一个二维数组来表示各个顶点之间的的关系(是否直接连接),对于有向图而言,边(a,b),说明从顶点a到顶点b有一条路径,那么直接就令A[a][b]为1,如果是无向图,在令A[b][a]为1,所以无向图的空间使用大约是有向图的两倍,但是如果顶点之间相互连接的比较少,但是二维数组的空间又是确定的,这样就会造成大量的空间浪费,所以采用了一种新的办法: 邻接表  
这个表来记录一个顶点与其它顶点之间直接相连的情况,其实也就是多个链表,每一个链表的头结点是这个顶点的关键字,指针指向下一个与它**直接相连**的顶点,在这种情况下,无向图的空间使用依旧是有向图的两倍  
但是在实际情况中,图的顶点的关键字并不是数字而是字符串,为了存储和访问的方便,邻接表里面存储的都是使用数字来表示的图的顶点,如果直接使用名字来存储的话,如果名字过长,那么所使用的空间也会很大  
所以,必须有一中方式储存一个名字到对应数字的映射,容易想到的就是一个散列表,  
当读入一个图的时候,每进来一条边,检查它的两个顶点是否已经在散列表里面,如果不在的话,给这个顶点指定一个数字编号(这个编号是在对图的操作中要用到的),并将这个顶点的名字和其对应的编号存储在散列表里面,如果顶点在散列表中,那么就直接略过,  
但是当我们对图进行操作完成的时候,返回的不能是数字编号,而是对应的名字,因此还需要存储数字和对应字符串的关系(注意:这里与上面散列的作用不同,散列的优点在于查找和插入都很快,适合用于寻找是否已插入,这里的目的是为了给编号回复相应的名字,也就是说需要遍历,这里使用散列就不太合适,当然也可以),可以维护一个字符串数组,对应索引对应相应的顶点名称

## 拓扑排序(对有向图而言)

首先,对于有向图里面的一个路径(u,v),在拓扑排序里面节点u一定要排在v的前面

### 基本的想法

先根据图的所有边算出所有节点的入度(指向该节点的箭头),放入一个Indegree的数组中(图的每一个顶点由数字编号表示),先遍历Indegree数组,找出入度为0的节点,将该节点从图中删除,并且将这个节点放入一个队列中,当这个队列不为空的时候就出队,保证了进入队列的节点出队的时候顺序还是一样的,达到排序的目的,并且遍历该节点的邻接表,将所有与这个节点相连的节点的入度减一,并且判断这些节点的度减一之后是否为0,如果为0就入队.出队的时候使用一个topnum[size]来接受出队元素,并标记其是第几个出队的  
如果最终topnum不等于图中节点的个数,那么就说明图中有环(有环的时候,环里面所有元素的入度均不为0)

### 伪代码实现

```.c
void TopSort(Graph G){
    Queue Q; //队列
    Q=CreateQueue(size);
    MakeEmpty(Q)

    Node V;  //图的节点
    Node M;  //用来表示邻接表中的节点
    ArrayList W; //邻接表

    int count=0;  //出队顺序,也是最终排序结果

    for G to V
        if(Indegree[V]==0)
            Enqueue(V,Q);  //入队

    while(!Empty(Q)){  //当Q不为空的时候
        V=Dequeue(Q);  //出队

        topnum[V]=++count;

        for W[V] to M
            if(--Indegree[M]==0)
                Enqueue[M,Q]
    }

    if(count!=size)   //如果最终已经排序的个数小于图的节点数,那么就说明有圈
        fetalerror("The Graph has a cycle")
}
```

## 最短路径算法

只考虑单个节点到图的其他节点的路径的最小值,对于图的最短路径分析,有四种情况

1. 无权图--各个边没有权重
2. 赋权图--边有权重
3. 负边图--边值的权重有负数的情况
4. 无圈图--没有圈的图

### 无权图

对于无权图,最短路径就是一个顶点到另一个顶点的最少边数,也可以看作把所有边权值都看成1  
最短路径就是计算从图的一个顶点到其他顶点的最短路径,对一个图的广度优先搜索
执行过程中要维护一个表

v | Known | dv | pv
---------|----------|---------|-------
 v1 | 0 | inf | 0
 v2 | 0 | inf | 0
 v3 | 0 | 0 | 0
 v4 | 0 | inf | 0
 v5 | 0 | inf | 0
 v6 | 0 | inf | 0
 v7 | 0 | inf | 0
 v8 | 0 | inf | 0

 v代表图的顶点,Known代表这个顶点对于我们选定的顶点来说是否已经可知,dv代表从选定的顶点到这个顶点所需要的距离,pv代表到这个顶点的上一个位置是哪里  
 首先先将一个距离变量置零,先遍历上述表,如果某个顶点的know为0,并且dv等于当前距离变量的值,说明这个顶点可以到达,将这个顶点的known置为true,然后遍历这个顶点的邻接表,邻接表里面的顶点也一定可以访问,所以当遇到领接表里面的顶点的dv为inf的时候,将其dv置为当前距离变量+1,并且将pv置为这个顶点(被遍历邻接表 的顶点,而不是当前领接表里面的顶点),之后将距离变量+1,继续遍历上面那个表,直到当距离变量大于等于图里面元素的个数的时候停止,因为不存在一个顶点到另一个顶点有一条路径,但是这个路径的长比图的个数都多  
 上面那个算法有个缺点,就是即使所有节点都已经Known了,但是程序还是会运行到距离变量等于图里元素个数才会停止.  
 上面的算法主要是因为不知道是否能连接到的元素的dv都已经不再是inf,所以要有个算法俩判断,当没有inf的时候,停止

```.c
void Unweighted(Table T){
    Queue Q;
    Q=CreatQueue(Numvertex);
    MakeEmpty(Q);
    vertex V,W;  //V用来代表上面那个表里面的各个顶点,W用来代表领接表里面的顶点

    Enqueue(v3, Q);
    while(!IsEmpty(Q)){
        V=Dequeue(Q);
        T[V].Known=True;
        for W in adjacent V
            if(T[W].dv==inf){
                T[W].dv=T[V].dv+1;
                T[W].pv=V;
                Enqueue(W,Q);
            }
    }
}
```

### 有权图

dijkstra算法:  是对图的一种广度优先搜索

```.c
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define VertexNum 7
#define NotFindVertex (-1)

typedef int begin_Vertex; //用来表示table里的初始顶点
typedef int Vertex; //用来表示上一个顶点
typedef int Dist_len; //用来声明路经长

struct TableEntry {
    begin_Vertex head;
    bool Known;
    Dist_len Dist;
    Vertex Path;
};

typedef struct TableEntry Table[VertexNum + 1]; //用来储存各个顶点状态的数组
typedef int Graph[VertexNum + 1][VertexNum + 1]; //图结构

void InitTable(int start, Table T)
{
    for (int i = 1; i < VertexNum + 1; i++) {
        T[i].head = i; //顶点的序号
        T[i].Known = false; //开始时全部都不是已知的
        T[i].Dist = 9999; // 先设立一个比较大的数
        T[i].Path = 0; //初始的上一个节点
    }
    T[start].Dist = 0; //原点的距离为0
}

Vertex FindMin(begin_Vertex B, Graph G, Table T)
{
    Vertex Vertex_index; //遍历的索引
    Vertex result; //用来储存最终结果的索引
    int Min = 9999; //用来比较

    for (Vertex_index = 1; Vertex_index < VertexNum + 1; Vertex_index++) {
        if (T[Vertex_index].Known == false && T[Vertex_index].Dist < Min) {
            result = Vertex_index;
            Min = T[Vertex_index].Dist;
        }
    }
    if (Min == 9999)
        result = -1;
    printf("%d  ", result);
    return result;
}

void Dijkstra(begin_Vertex B, Graph G, Table T)
{
    Vertex V = B; //顶点
    //Vertex W;
    for (;;) {
        V = FindMin(V, G, T); //在当前顶点的邻接表里面找到一个距离最小的,返回最小的索引
        if (V == NotFindVertex)
            break;
        T[V].Known = true; //这个已经是最小的了,可以直接置为true
        for (Vertex Vertex_index = 1; Vertex_index < VertexNum + 1; Vertex_index++) {
            if (!T[Vertex_index].Known) {
                if (T[V].Dist + G[V][Vertex_index] < T[Vertex_index].Dist) {
                    T[Vertex_index].Dist = T[V].Dist + G[V][Vertex_index];
                    T[Vertex_index].Path = V; //设定来到这个店前经过的最后一个点路径
                }
            }
        }
    }
}

int main()
{
    Table T;
    begin_Vertex start = 1;

    InitTable(start, T);
    Graph G
        = {
              { 0 },
              { 0, 9999, 2, 9999, 1, 9999, 9999, 9999 },
              { 0, 9999, 9999, 9999, 3, 10, 9999, 9999 },
              { 0, 4, 9999, 9999, 9999, 9999, 5, 9999 },
              { 0, 9999, 9999, 2, 9999, 2, 8, 4 },
              { 0, 9999, 9999, 9999, 9999, 9999, 9999, 6 },
              { 0, 9999, 9999, 9999, 9999, 9999, 9999, 9999 },
              { 0, 9999, 9999, 9999, 9999, 9999, 1, 9999 }
          };
    Dijkstra(1, G, T);
    printf("v   known   dv   pv   \n");
    for (Vertex v = 1; v < VertexNum + 1; v++) {
        printf("v%d      ", v);
        printf("%d   ", T[v].Known);
        printf("%d   ", T[v].Dist);
        printf("%d   \n", T[v].Path);
    }
    return 0;
}
```

## 最小生成树算法

在无向图中找到一棵最小生产树,这棵树的所有路径之和的代价最小,并且能连接到所有顶点(这里假设原始的图是联通的),最终生成树的边的条数比顶点个数少1  
对于一个已经完成的生成树,如果再向书中增加一条边e,那么就一定会形成一个圈,如果再去除一条边,那么又会形成一个新的生成树,如果去除的边的权值比e要大,那么新生成的树比以前的树的总代价要低  
建立生成树的过程是在所有顶点之间添加边的过程,如果建立生成树的过程中所添加的边在所有避免成圈的边里面的代价最小,那么最终得到的生成树的值一定不可以再改进,即代价最小
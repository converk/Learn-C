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
#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;   //头节点
typedef PtrToNode Position;

#define LEN 10

List MakeEmpty();                 //创建空表
int IsEmpty(List L);                    //判断表是否为空
int IsLast(Position P, List L);         //判断是不是最后一个元素
Position Find(int x, List L);           //找到一个元素的位置
void Delete(int x, List L);             //删除一个元素
Position FindPrevious(int x, List L);   //找到一个元素前面那个元素
void Insert(int x, List L, Position P); //插入一个元素
void DeleteList(List L);                //删除链表
Position Header(List L);                //返回头结点位置
Position First(List L);                 //返回第一个元素
void PtrList(List L);                   //打印链表

#endif
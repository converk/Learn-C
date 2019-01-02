//哈希表分离链接法

struct ListNode;
typedef struct ListNode *Position;  //声明一个链表
struct HashTle;
typedef struct HashTle *HashTable;  //哈希表声明

typedef int Index;

struct ListNode{
    int Element;
    Position Next;
};

//如果采用这种方法,那么哈希表里面存储的就是一个个链表的表头
typedef Position List;

struct HashTle{
    int TableSize;  //哈希表的大小
    List *ListHead;  //存储表头的数组
};

#define MinSize 8 

HashTable InitHashtable(int Tablesize);
void DestroyHashTable(HashTable H);
HashTable Insert(int x,HashTable H);
HashTable Delete(int x, HashTable H);
Position Find(int x, HashTable H);
void PtrHashtable(HashTable H);

typedef int Index; //索引是数字
typedef Index Position; //位置类型

#define SIZE 17

//定义哈希表
struct HashTbl;
typedef struct HashTbl* HashTable;
enum KindOfEntery {
    Legitimate,
    Empty,
    Deleted,
}; //定义当前索引下的元素的状态,有效,删除,为空

//定义元素类型
struct HashEntry;
typedef struct HashEntry Cell; //哈希表的一个元素的类型

struct HashTbl {
    int TableSize;
    Cell* TheCells; //哈希表里面存储的元素
};

struct HashEntry {
    int Element;
    enum KindOfEntery Info; //当前元素是否有效的状态信息
};

HashTable InitHashTable(int TableSiz); //初始化哈希表
void DestroyHashTable(HashTable H); //摧毁哈希表
Position Find(int x, HashTable H); //返回找到元素的位置,没找到返回最后位置,用于之后的插入
HashTable Insert(int x, HashTable H); //插入元素
HashTable Delete(int x, HashTable H);
HashTable ReHash(HashTable H);   //再散列
void PtrHashTable(HashTable H); //打印整个表
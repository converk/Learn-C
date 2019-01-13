struct HeapStruct;
typedef struct HeapStruct* ProrityQueue;

#define MinSize 10

ProrityQueue InitHeap(int MaxSize);
void DestoryHeap(ProrityQueue H);
void Insert(ProrityQueue H, int InsertElement); //因为传入的已经是一个指针,所以返回是空
int DeleteMin(ProrityQueue H);
void DecreaseKey(int index, int change, ProrityQueue H); //减小一个位置关键字的值,change是改变量
void IncreaseKey(int index, int change, ProrityQueue H); //增加一个位置关键字的值
ProrityQueue BuildHeap(int* array, int N); //在给一个完全无序的数组,组成一个堆,N为当前数组的元素个数
void PtrHeap(ProrityQueue H); //打印一个堆
int IsEmpty(ProrityQueue H);
int IsFull(ProrityQueue H);

struct HeapStruct {
    int NowSize;
    int MaxSize;
    int* Elemnets;
};

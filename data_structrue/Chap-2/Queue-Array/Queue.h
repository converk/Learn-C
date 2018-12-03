struct QueueArray;
typedef struct QueueArray* Queue;

int IsEmpty(Queue Q);              //判断是否为空
int IsFull(Queue Q);               //判断是否满了
Queue CreatQueue(int MaxElements); //创建一个空队列
void Diospose(Queue Q);            //清除一个队列
void MakeEmpty(Queue Q);           //清空一个队列
void EnQueue(int x, Queue Q);      //添加元素
void DeQueue(Queue Q);             //删除元素
void PrtQueue(Queue Q);            //打印队列

#define MinSize 5;
struct Node;
typedef struct Node* Queue;
typedef struct Node* Position;

int IsEmpty(Queue Q);
Queue CreatQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(int x,Queue Q);
void Dequeue(Queue Q);
void PrtQueue(Queue Q);
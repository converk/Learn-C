struct LinearTable;
typedef struct LinearTable *List;

List MakeEmpty();                  //空表
int FindKth(int k, List L);        //根据坐标找到相应的值
int Find(int x, List L);           //找到相应的值
void Insert(int x, int k, List L); //插入
void Delete(int k, List L);        //删除相应坐标的数
int Length(List L);                //返回表的长度
void PtrList(List L);              //打印表

#define LEN 10
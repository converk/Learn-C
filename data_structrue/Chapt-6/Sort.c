#include <stdio.h>
#include <stdlib.h>

#define LeftChild(i) (2 * (i) + 1) //堆排序的儿子的计算方法
#define Cutoff (3) //在快排中使用插入排序的最小界

void swap(int* x, int* y); //交换两个数

void InsertSort(int A[], int N); //插入排序

void ShellSort(int A[], int N); //希尔排序

void HeapSort(int A[], int N); //堆排序
void PcrDown(int A[], int i, int N); //下滤,用来创建堆和交换最后一个和第一个的时候进行下滤

void MergeSort(int A[], int N); //归并排序,主体算法的驱动程序
void Msort(int A[], int TmpArray[], int left, int rigth); //排序中递归调用的主体函数
void Merge(int A[], int TmpArray[], int left, int cerent, int rigth); //用来合并两个排序好的数组

void QuickSort(int A[], int N); //快速排序
int Median3(int A[], int left, int rigth); //找出枢纽元的三数中值
void QSort(int A[], int left, int rigth); //快排的主体算法

int main(int argc, char const* argv[])
{

    return 0;
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSort(int A[], int N)
{
    int temp;
    int j;
    for (int i = 0; i < N; i++) {
        temp = A[i];
        for (j = i; j > 0 && A[j - 1] > temp; j--) {
            A[j] = A[j - 1];
        }
        A[j] = temp;
    }
}

void ShellSort(int A[], int N)
{
    int IncreaseMent, i, j;
    int temp;

    for (IncreaseMent = N / 2; IncreaseMent > 0; IncreaseMent /= 2) {
        for (i = IncreaseMent; i < N; i++) { //对每隔InCreaseMent个进行插入排序
            temp = A[i];
            for (j = i; j >= IncreaseMent; j -= IncreaseMent) { //这里的思想其实和堆差不多
                if (temp < A[j - IncreaseMent])
                    A[j] = A[j - IncreaseMent];
                else
                    break;
            }
            A[j] = temp;
        }
    }
}

void PcrDown(int A[], int i, int N) //i是下滤第几个元素,N是堆一共几个元素
{
    int temp, child;
    for (temp = A[i]; LeftChild(i) < N; i = child) {
        child = LeftChild(i);
        if (child != N - 1 && A[child] < A[child + 1])
            child++;
        if (temp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = temp;
}

void HeapSort(int A[], int N)
{
    int temp;
    for (int i = N / 2; i >= 0; i--)
        PcrDown(A, i, N); //创建堆
    for (int i = N - 1; i > 0; i--) {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        PcrDown(A, 0, i);
    }
}

void MergeSort(int A[], int N)
{
    int* TmpArray = malloc(N * sizeof(int));
    if (!TmpArray) {
        Msort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    }
}

void Msort(int A[], int TmpArray[], int left, int rigth)
{
    int cerent;

    if (left < rigth) {
        cerent = (left + rigth) / 2;
        Msort(A, TmpArray, left, cerent);
        Msort(A, TmpArray, cerent + 1, rigth);
        Merge(A, TmpArray, left, cerent + 1, rigth);
    }
}

void Merge(int A[], int TmpArray[], int left, int cerent, int rigth)
{
    int A_left = left;
    int A_rigth = cerent;
    int B_left = cerent + 1;
    int B_rigth = rigth;
    int C_begin = left;
    int C_end = rigth;

    int C_index = left; //c中的当前索引
    while (A_left <= A_rigth && B_left <= B_rigth) {
        if (A[A_left] > A[B_left])
            TmpArray[C_index++] = A[B_left++];
        else
            TmpArray[C_index++] = A[A_left++];
    }

    while (A_left <= A_rigth) //清除剩余的
        TmpArray[C_index++] = A[A_left++];

    while (B_left <= B_rigth)
        TmpArray[C_index++] = A[B_left++];

    for (int i = left; i <= rigth; i++) //将tmp中的元素在拷贝到A中,这个过程会减慢算法速度
        A[i] = TmpArray[i];
}

void QuickSort(int A[], int N)
{
    QSort(A, 0, N - 1);
}

int Median3(int A[], int left, int rigth)
{
    int mid = (left + rigth) / 2;
    if (A[left] > A[mid])
        swap(A + left, A + mid);
    if (A[left] > A[rigth])
        swap(A + left, A + rigth);
    if (A[mid] > A[rigth])
        swap(A + mid, A + rigth);

    swap(&A[mid], &A[rigth - 1]); //将枢纽元交换到后面
    return A[rigth - 1];
}

void QSort(int A[], int left, int rigth)
{
    int temp;
    int i = left + 1, j = rigth - 2;

    if (rigth - left >= Cutoff) { //快速排序
        temp = Median3(A, left, rigth); //返回索引

        for (;;) {
            while (A[i++] < temp) {
            }
            while (A[j--] > temp) {
            }
            if (i < j)
                swap(&A[i], &A[j]);
            else
                break;
        }
        swap(&A[rigth - 1], &A[i]); //把枢纽元交换回来

        QSort(A, left, i - 1);
        QSort(A, i + 1, rigth);
    } else
        InsertSort(A, rigth - left + 1); //使用插入排序
}
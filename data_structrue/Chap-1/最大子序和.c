//最大子序列和的第一,二,四种算法
#include<stdio.h>
#include<time.h>

clock_t start, stop; //计算运行时间
#define SIZE 8
#define MAXK 100000  //重复运行的次数
double duration;

int max_subsequence_sum_1(const int[], int);
int max_subsequence_sum_2(const int[], int);
int max_subsequence_sum_4(const int[], int);

int main(void){
    const int A[SIZE]={-1,-3,4,-6,7,-4,-8,5};
    int j;
    int answer;
    start = clock();
    for (j=0; j<MAXK; j++)
        answer=max_subsequence_sum_4(A, SIZE);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("f4 time : %f\n", duration);
    printf("the f4_max is : %d\n", answer);
    start = clock();
    for (j = 0; j < MAXK; j++)
        answer = max_subsequence_sum_1(A, SIZE);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("f1 time : %f\n", duration);
    printf("the f1_max is : %d\n", answer);
    start = clock();
    for (j = 0; j < MAXK; j++)
        answer = max_subsequence_sum_2(A, SIZE);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("f2 time : %f\n", duration);
    printf("the f2_max is : %d\n", answer);
    return 0;
}

int max_subsequence_sum_4(const int A[], int N){
    int maxsum,thissum,j;
    thissum=maxsum=0;
    for (j=0; j<N; j++){
        thissum+=A[j];
        if (thissum>maxsum)
            maxsum=thissum;
        else if(thissum<0)
            thissum=0;
    }
    return maxsum;
}

int max_subsequence_sum_1(const int A[], int N){
    int thissum,maxsum=0;
    int i,j,k;
    for (i=0; i<N; i++){
        for (j=i; j<N; j++){
            thissum=0;
            for (k=i; k<j; k++)
                thissum+=A[k];
            if (thissum > maxsum)
                maxsum = thissum;
        }
    }
    return maxsum;
}
int max_subsequence_sum_2(const int A[], int N)
{
    int thissum, maxsum = 0;
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        thissum = 0;
        for (j = i; j < N; j++)
        {
            thissum+=A[j];
            if (thissum > maxsum)
                maxsum = thissum;
        }
    }
    return maxsum;
}

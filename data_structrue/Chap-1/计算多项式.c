//测试计算多项式两种方法的快慢

#include<stdio.h>
#include<math.h>
#include<time.h>

clock_t start, stop;  //计算运行时间
double duration; //实际时间

#define MAX 10  //多项式的个数
#define MAXK 100000  //重复运行的次数

double f1(int n, double a[], double x);  //一般算法
double f2(int n, double a[], double x); //秦九韶

// typedef double (*P)(int, double *, double);

void fun(double (*show)(int, double *, double))
{
    int i, j;
    double a[MAX];
    for (i = 0; i < MAX; i++)
        a[i] = (double)i; //强制类型转换,初始化数组
    start = clock();
    for (j = 0; j < MAXK; j++)
        show(MAX - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("f1 time : %f\n", duration);
}

int main(){

    fun(f1);
    fun(f2);
    return 0;
}

double f1(int n, double a[], double x){
    int i;
    double p=0.0;
    for (i=0; i<=n; i++){
        p+=a[i]*pow(x,i);
    }
    return p;
}

double f2(int n, double a[], double x){
    int i;
    double p=a[n];
    for (i=n; i>0; i--){
        p=a[i-1]+x*p;
    }
    return p;
}
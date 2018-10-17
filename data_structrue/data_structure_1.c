//测试计算多项式两种方法的快慢

// #include<stdio.h>
// #include<math.h>
// #include<time.h>

// clock_t start, stop;  //计算运行时间
// double duration; //实际时间

// #define MAX 10  //多项式的个数
// #define MAXK 100000  //重复运行的次数

// double f1(int n, double a[], double x);  //一般算法
// double f2(int n, double a[], double x); //秦九韶

// // typedef double (*P)(int, double *, double);

// void fun(double (*show)(int, double *, double))
// {
//     int i, j;
//     double a[MAX];
//     for (i = 0; i < MAX; i++)
//         a[i] = (double)i; //强制类型转换,初始化数组
//     start = clock();
//     for (j = 0; j < MAXK; j++)
//         show(MAX - 1, a, 1.1);
//     stop = clock();
//     duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
//     printf("f1 time : %f\n", duration);
// }

// int main(){

//     fun(f1);
//     fun(f2);
//     return 0;
// }

// double f1(int n, double a[], double x){
//     int i;
//     double p=0.0;
//     for (i=0; i<=n; i++){
//         p+=a[i]*pow(x,i);
//     }
//     return p;
// }

// double f2(int n, double a[], double x){
//     int i;
//     double p=a[n];
//     for (i=n; i>0; i--){
//         p=a[i-1]+x*p;
//     }
//     return p;
// }



//最大子序列和的第一,二,四种算法
// #include<stdio.h>
// #include<time.h>


// clock_t start, stop; //计算运行时间
// #define SIZE 8
// #define MAXK 100000  //重复运行的次数
// double duration;

// int max_subsequence_sum_1(const int[], int);
// int max_subsequence_sum_2(const int[], int);
// int max_subsequence_sum_4(const int[], int);

// int main(void){
//     const int A[SIZE]={-1,-3,4,-6,7,-4,-8,5};
//     int j;
//     int answer;
//     start = clock();
//     for (j=0; j<MAXK; j++)
//         answer=max_subsequence_sum_4(A, SIZE);
//     stop = clock();
//     duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
//     printf("f4 time : %f\n", duration);
//     printf("the f4_max is : %d\n", answer);
//     start = clock();
//     for (j = 0; j < MAXK; j++)
//         answer = max_subsequence_sum_1(A, SIZE);
//     stop = clock();
//     duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
//     printf("f1 time : %f\n", duration);
//     printf("the f1_max is : %d\n", answer);
//     start = clock();
//     for (j = 0; j < MAXK; j++)
//         answer = max_subsequence_sum_2(A, SIZE);
//     stop = clock();
//     duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
//     printf("f2 time : %f\n", duration);
//     printf("the f2_max is : %d\n", answer);
//     return 0;
// }

// int max_subsequence_sum_4(const int A[], int N){
//     int maxsum,thissum,j;
//     thissum=maxsum=0;
//     for (j=0; j<N; j++){
//         thissum+=A[j];
//         if (thissum>maxsum)
//             maxsum=thissum;
//         else if(thissum<0)
//             thissum=0;
//     }
//     return maxsum;
// }

// int max_subsequence_sum_1(const int A[], int N){
//     int thissum,maxsum=0;
//     int i,j,k;
//     for (i=0; i<N; i++){
//         for (j=i; j<N; j++){
//             thissum=0;
//             for (k=i; k<j; k++)
//                 thissum+=A[k];
//             if (thissum > maxsum)
//                 maxsum = thissum;
//         }
//     }
//     return maxsum;
// }
// int max_subsequence_sum_2(const int A[], int N)
// {
//     int thissum, maxsum = 0;
//     int i, j, k;
//     for (i = 0; i < N; i++)
//     {
//         thissum = 0;
//         for (j = i; j < N; j++)
//         {
//             thissum+=A[j];
//             if (thissum > maxsum)
//                 maxsum = thissum;
//         }
//     }
//     return maxsum;
// }


//欧几里得算法,求两个数的最大公因数

// #include<stdio.h>
// unsigned int gcd(unsigned int, unsigned int);

// int main(void){

//     int M, N;
//     int answer;
//     printf("please input two int: ");
//     scanf("%d, %d", &M, &N);
//     answer=gcd(M,N);
//     printf("answer: %d\n",answer);
//     return 0;
// }

// unsigned int gcd(unsigned int M, unsigned int N){
//     unsigned temp;
    
//     while(N>0){
//         /* code */
//         temp=M%N;
//         M=N;
//         N=temp;
//     }
//     return M;
    
// }


//快速计算幂
// #include<stdio.h>

// long int Poow(long int , unsigned int);

// int main(void){
//     long int X;
//     unsigned int N;
//     long int answer;
//     printf("please input two int: ");
//     scanf("%ld, %d", &X, &N);
//     answer=Poow(X,N);
//     printf("answer: %ld", answer);
//     return 0;
// }

// long int Poow(long int X, unsigned int N){
//     if(N==0){
//         return 1;
//     }
//     if(N==1){
//         return X;
//     }
//     if (!(N%2)){
//         return Poow(X*X,N/2);
//     }
//     if(N%2){
//         return Poow(X*X,N/2)*X;
//     }
// }



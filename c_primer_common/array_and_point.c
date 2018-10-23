// #include <stdio.h>

// int main(void)
// {
//     const int years[] = {30, 31, 30, 31, 30, 31};
//     int index;
//     for (index = 0; index < (sizeof(years) / sizeof(years[0])); index++)
//         printf("%d:%d\n", index, years[index]);
//     return 0;
// }

//数组越界的后果
// #include <stdio.h>
// #define SIZE 4

// int main(int argc, char const *argv[])
// {

//     int a[SIZE];
//     int value1 = 44;
//     int value2 = 88;
//     int i;

//     printf("value1: %d, value2: %d\n", value1, value2);
//     for (i = -1; i <=4; i++)
//         a[i] = 2 * i + 1;
//     for (i = -1; i < 8; i++)
//         printf("%2d  :  %d\n", i, a[i]);
//     printf("value1: %d, value2: %d\n", value1, value2);
//     return 0;
// }

// #include<stdio.h>
// #define YEARS 5
// #define MONTHS 12

// int main(void){
//     const int RAIN[YEARS][MONTHS] = {
//         {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
//         {1, 2, 3, 4, 5, 4, 7, 8, 1, 10, 1, 12},
//         {1, 2, 9, 4, 5, 6, 7, 2, 9, 10, 11, 1},
//         {10, 2, 3, 14, 5, 6, 7, 8, 9, 10, 11, 18},
//         {11, 21, 31, 4, 5, 6, 7, 8, 0, 10, 11, 12}
//     };

//     int year,month,i;
//     double total,each_year,each_month;
//     printf("YEAR  RAINFALL\n");

//     for (year=0,total=0.0;year<YEARS;year++){
//         for (month=0, each_year=0.0; month<MONTHS; month++){
//             each_year+=RAIN[year][month];
//         }
//         printf("%5d %12.1f\n", 2000+year, each_year);
//         total+=each_year;
//     }
//     printf("\nthe yearly average is %.1f\n", total/YEARS);

//     for (i=1; i<=MONTHS; i++)
//         printf("%-6d", i);
//     printf("\n");
//     for (month = 0; month < MONTHS; month++)
//     {
//         for (year = 0, each_month = 0.0; year < YEARS; year++)
//         {
//             each_month += RAIN[year][month];
//         }
//         printf("%-6.1f",each_month);
//     }
//     printf("\n");
//     return 0;
// }

// #include<stdio.h>
// #define SIZE 4

// int main(void){
//     int a[SIZE];
//     int *p;
//     p=&a[0];
//     printf("%p  %p\n", p, &a[0]);
//     p=a;
//     printf("%p  %p\n", p, &a[0]);
//     return 0;
// }

// #include<stdio.h>
// #define SIZE 4
// int main(void){
//     short dates[SIZE];
//     short * pti;
//     short index;
//     double bills[SIZE];
//     double * ptf;
//     pti=dates;
//     ptf=bills;
//     printf("%23s %10s\n", "short", "double");
//     for (index=0; index<SIZE; index++){
//         printf("pointers + %d: %10p %10p\n", index, pti+index, ptf+index);  //地址+1是对应的数据类型存储数据位置+1
//     }
//     return 0;
// }

// #include <stdio.h>
// #define SIZE 10
// int sum(int ar[], int n);

// int main(void)
// {
//     int marbles[SIZE] = {[1] = 7, [2] = 8};
//     int answer;
//     int i;
//     for (i=0; i<SIZE; i++){
//         printf("%d ",marbles[i]);
//     }
//     printf("\n");
//     answer = sum(marbles, SIZE);
//     printf("marbles: %zd\n", sizeof(marbles));
//     printf("total: %d\n", answer);
//     return 0;
// }

// int sum(int *ar, int n)
// {
//     int i;
//     int total = 0;

//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", ar[i]);
//         total += ar[i];
//     }
//     printf("\n");
//     printf("ar: %zd\n", sizeof(ar));  //这里打印出指针的大小,不同电脑不一样,ar是一个指针而不是一个数组
//     return total;
// }


// #include<stdio.h>
// #define SIZE 10

// long sump(int *, int *);
// int main(void){
//     int marbles[SIZE]={20,10,5,39,4,5,19,25,31,20};
//     long int answer;

//     answer=sump(marbles,marbles+SIZE);
//     printf("the answer is : %ld", answer);
//     return 0;
// }

// long sump(int * start, int * end){
//     long total=0;

//     while(start<end){
//         total+=*start;
//         start++;
//     }
//     return total;
// }



//指针与++运算的各种结合

// #include<stdio.h>

// int data[2]={100,200};
// int moredata[2]={300,400};

// int main(int argc, char const *argv[])
// {
//     int *p1,*p2,*p3;
//     p1=p2=data;
//     p3=moredata;
//     printf("*p1=%d, *p2=%d, *p3=%d\n",*p1, *p2, *p3);
//     printf("*p1++=%d, *++p2=%d, (*p3)++=%d\n", *p1++, *++p2, (*p3)++);
//     printf("*p1=%d, *p2=%d, *p3=%d\n", *p1, *p2, *p3);
//     return 0;
// }


//指针的各种操作
// #include<stdio.h>

// int main(void){
//     int urn[5]= {100,200,300,400,500};
//     int *p1,*p2,*p3;

//     p1=urn;
//     p2=&urn[2];

//     printf("size of p1: %zd\n", sizeof(p1));

//     printf("pointer value,  dereferenced pointer, pointer address\n");
//     printf("p1=%p, *p1=%d, &p1=%p\n", p1, *p1, &p1);

//     p3=p1+4;
//     printf("\nadding an int to a pointer:\n");
//     printf("p1+4= %p, *(p1+4)= %d\n", p1+4, *(p1+4));

//     p1++;
//     printf("\nvalues after p1++\n");
//     printf("p1=%p, *p1=%d, &p1=%p\n", p1, *p1, &p1);

//     p2--;
//     printf("\nvalues after p2--\n");
//     printf("p2=%p, *p2=%d, &p2=%p\n", p2, *p2, &p2);

//     //恢复到原来的值
//     p1--;
//     p2++;
//     printf("\npointers reset to orginal values:\n");
//     printf("p1=%p, p2=%p",p1, p2);

//     printf("\n p2 - p1\n");
//     printf("p1=%p, p2=%p, p2 - p1= %ld\n", p1, p2, p2-p1);

//     printf("p2>p1: %d", p2>p1);
//     return 0;
// }


//保护数组中的元素不变,使用const
// #include<stdio.h>
// #define SIZE 5

// int show_array(const double *, int);
// int add_array(double *, int, double);

// int main(void){
//     double array[SIZE]={20.0,17.66,8.2,15.3,22.22};
//     show_array(array,SIZE);
//     add_array(array, SIZE, 5.0);
//     show_array(array, SIZE);
//     return 0;
// }

// int show_array(const double *array, int N){
//     int i;
//     for (i=0; i<N;i++)
//         printf("%8.3f", array[i]);
//     putchar('\n');
//     return 0;
// }

// int add_array(double *array, int N, double add){
//     int i;
//     for (i = 0; i < N; i++)
//         array[i]+=add;
//     return 0;
// }


//指针与多维数组

// #include<stdio.h>

// int main(void){
//     int zippo[4][2]={{1,2},{3,4},{5,6},{6,7}};

//     printf("  zippo =%p,   zippo+1 = %p\n",zippo, zippo+1);
//     printf("  zippo[0]= %p, zippo[1]+1= %p\n", zippo[0],zippo[0]+1);
//     printf("  *zippo= %p, *zippo+1= %p\n", *zippo,*zippo+1 );
//     printf(" *zippo[0]=%d\n", *zippo[0]);
//     printf("  **zippo=%d\n", **zippo);
//     return 0;

// }

// #include<stdio.h>

// int main(void){
//     int zippo[4][2]={{1,2},{3,4},{5,6},{7,8}};

//     int (*pz)[2];
//     pz=zippo;

//     printf("  pz=%p,    pz+1= %p\n", pz,pz+1);
//     printf("pz[0]= %p, pz[0]+1=%p\n", pz[0],pz[0]+1);
//     printf("*pz= %p, *pz+1=%p\n", *pz, *pz + 1);
//     printf("   pz[2][1]= %d", pz[2][1]);
//     printf("   *(*(pz+2)+1)= %d", *(*(pz + 2) + 1));

//     return 0;
// }


//函数与多维数组,如何在形参里面表示二维数组

// #include<stdio.h>

// #define ROWS 3
// #define COLS 4

// //三种声明方法
// void sum_rows(int ar[][COLS], int rows);
// void sum_cols(int [][COLS], int);
// //int sum(int (*ar)[COLS], int rows);

// int main(void){

//     int junk[ROWS][COLS]={
//         {2,4,6,8},
//         {3,5,6,7},
//         {12,10,8,6}
//     };
//     sum_rows(junk,ROWS);
//     sum_cols(junk, ROWS);
//     //sum(junk,ROWS);
//     return 0;
// }

// void sum_rows(int ar[][COLS], int rows){
//     int i,j;
//     int total;
//     for (i=0; i<rows; i++){
//         total=0;
//         for (j=0; j<COLS; j++){
//             total+=ar[i][j];
//         }
//         printf("row: %d, sim_row: %d\n", i, total);
//     }
// }

// void sum_cols(int ar[][COLS], int rows){
//     int i, j;
//     int total;
//     for (i = 0; i < COLS; i++)
//     {
//         total = 0;
//         for (j = 0; j < rows; j++)
//         {
//             total += ar[j][i];
//         }
//         printf("col: %d, sim_col: %d\n", i, total);
//     }
// }


//变长数组(VLA)
// #include<stdio.h>
// #define ROWS 3
// #define COLS 4
// int sum(int , int , int [*][*]);

// int main(void){
//     int i,j;
//     int ra=3;
//     int cs=10;
//     int junk[ROWS][COLS]={
//         {2,3,4,5},
//         {3,5,8,9},
//         {5,9,7,5}
//     };
//     int var[ra][cs];
//     for (i=0; i<ra; i++){
//         for (j=0; j<cs; j++){
//             var[i][j]=i*j+j;
//         }
//     }
//     printf("sum of junk: %d\n", sum(ROWS,COLS,junk));
//      printf("sum of var: %d\n",sum(ra,cs,var));
//     return 0;
// }

// int sum(int rows, int cols, int ar[rows][cols]){
//     int i,j;
//     int total=0;
//     for (i=0; i<rows; i++){
//         for (j=0; j<cols; j++){
//             total+=ar[i][j];
//         }
//     }
//     return total;
// }
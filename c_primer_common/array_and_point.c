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

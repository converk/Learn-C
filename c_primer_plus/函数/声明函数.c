/*声明时函数的形参类型和数量的说明*/
#include<stdio.h>

int max(int,int);

int main(){
    printf("the max of %d and %d is %d\n", 3, 5, max(3,5));
    printf("the max of %d and %d is %d\n", 3, 5, max(3.0,5.0));
    return 0;
}

int max(int a,int b){
    return (a>b)?a:b;
}
#include<stdio.h>
#define SIZE 4

int main(void){
    int a[SIZE];
    int *p;
    p=&a[0];
    printf("%p  %p\n", p, &a[0]);
    p=a;
    printf("%p  %p\n", p, &a[0]);
    return 0;
}
//字符串常量,多次调用的时候相当于指向字符串存储位置的指针
#include<stdio.h>
int main(void){
    printf("%s,  %p,  %c\n", "we", "qewqw", *"weqr"); //结果:we,  0x5617848e6704,  w
    return 0;
}
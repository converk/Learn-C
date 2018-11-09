//字符串数组和初始化
#include<stdio.h>
int main(void){
    const char ml[40]="limit yourself to one line's worth.";
    const char m2[] = "limit yourself to one line's worth.";
    printf("%lu\n", sizeof(m2)/sizeof(char));
}
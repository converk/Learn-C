//scanf()的使用
#include<stdio.h>
int main(void){
    char name1[11],name2[11];
    int count;

    puts("enter two names");
    count=scanf("%11s %10s",name1,name2);  //注意读入的字符长度要比数组少一,不然没地方放终止符
    printf("I read %d names %s and %s\n",count,name1,name2);
    return 0;
}
//指向结构的指针
#include<stdio.h>
#define LEN 20

struct name{
    char first[LEN];
    char last[LEN];
};

struct guy{
    struct name handle;  //嵌套结构,这个handle变量,在这里相当于声明
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(int argc, char const *argv[])
{
    struct guy fellow[2]={
        {
            {"hu","bowen"},
            "salmon",
            "personality",
            68112
        },
        {
            {"xu","song"},
            "tripe",
            "editor",
            432400
        }
    };  //声明一个结构数组
    struct guy *him;
    printf("address #1:%p, address #2: %p\n",&fellow[0],&fellow[1]);
    him=&fellow[0];
    printf("him #1:%p, him+1 #2: %p\n",him,him+1 );
    printf("him->income is $%.2f: (*him).income if $%.2f\n", him->income, (*him).income);
    //(*him).income和him->income一样
    return 0;
}
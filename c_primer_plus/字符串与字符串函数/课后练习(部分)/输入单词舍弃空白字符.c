//向数组输入一个单词,舍弃之前所有的空白字符,并且单词内不包含空白字符,把下面的输入换成s_gets()
#include<stdio.h>
#include<ctype.h>
#define SIZE 5

int main(int argc, char const *argv[])
{
    char str;
    char words[SIZE];
    str=getchar();
    while(isblank(str))
        str = getchar();
    words[0]=str;
    fgets(words+1,SIZE-1,stdin);
    fputs(words,stdout);
    return 0;
}
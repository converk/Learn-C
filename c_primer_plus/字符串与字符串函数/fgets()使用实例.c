//fgets()使用实例, 舍弃输入缓冲区,把回车换成结束符
#include<stdio.h>
#define STLEN 10
int main(void){
    char words[STLEN];
    int i;
    puts("enter strings (empty to quit)");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        i=0;
        while (words[i] != '\n' && words[i] != '\0'){
            i++;
        }
        if (words[i] == '\n')
        {
            words[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')  //除去缓冲区剩余的
            {
                continue;
            }
        }
        puts(words);
    }
    puts("bye!!!");
    return 0;
}
//strlen()函数
#include<stdio.h>
#include<string.h>
void fit(char *,int);

int main(void){
    char words[]="things should be as simple as possible,"" but not simpler";
    puts(words);
    fit(words,38);
    puts(words);
    puts(" let's look at some more of the string");
    puts(words+39);  //会继续打印出之后的字符串
    return 0;
}

void fit(char *words, int n){
    if (strlen(words)>n)
        words[n]='\0';  //超过字长,加终止符
}

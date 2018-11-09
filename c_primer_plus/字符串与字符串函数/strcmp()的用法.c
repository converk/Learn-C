//strcmp()的用法,相同就返回0,否则返回非零值,两个参数都为指针
#include<stdio.h>
#include<string.h>
#define SIZE 40
#define ANSWER "grant"

char *s_gets(char *, int);

int main(void){
    char try[SIZE];
    puts("who is buried in grant's tomb");
    //while(*(s_gets(try,SIZE))!=*ANSWER)  //两个都是指针,都要解引用,但解引用只得到第一个字符,不会得到全部的字符串
    while (strcmp(s_gets(try, SIZE), ANSWER) != 0)
        puts("please input again");
    puts("right!!!!");
    return 0;
}

char *s_gets(char *words, int size){
    char *rev_lev;
    int i;
    rev_lev=fgets(words, size,stdin);
    printf("rev_lev==words:%d\n", rev_lev == words);
    if(rev_lev){
        i=0;
        while (rev_lev[i]!='\0'&&rev_lev[i]!='\n')
            i++;
        if (rev_lev[i] == '\n')
            rev_lev[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return rev_lev;
}
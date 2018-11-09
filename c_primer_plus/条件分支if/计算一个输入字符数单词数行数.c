/*计算一个输入字符数单词数行数*/
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define STOP '|'  //定义输入停止标志

int main(void){
    int n_chars=0;  //字符数
    int n_lines=0;  //整行
    int p_n_lines=0;  //办行
    int n_words=0;

    bool inword=false;  //判断是否在一个单词里

    char c;  //当前读入字符
    char pre_c='\n';  //上一个读入字符;

    printf("please input a str(| to quit): \n");
    
    while((c=getchar()) != STOP){
        /* code */
        n_chars++;
        if (c == '\n'){
            n_lines++;
        }
        if (isspace(c) && !inword){
            inword=true;
            n_words++;
        }
        if (isspace(c) && inword){
            inword=false;
        }
        pre_c=c;
    }
    if (pre_c != '\n'){
        p_n_lines = 1;
    }
    printf("lines:%d, chars: %d, words: %d, p_lines:%d\n",n_lines,n_chars,n_words,p_n_lines);
    return 0;
    
}
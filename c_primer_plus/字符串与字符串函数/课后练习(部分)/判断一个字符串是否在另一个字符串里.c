

//判断一个字符串是否在另一个字符串里面

#include<stdio.h>
#include<string.h>
int OneInTwo(char *,char *);

int count = 0;

int main(void){
    char words_1[]="sdfh";
    char words_2[]="dfh";
    int find;
    find=OneInTwo(words_1,words_2);
    printf("%d\n",find);

    return 0;
}

int OneInTwo(char *words_1, char *words_2){
    char *word_2_begin=words_2;
    char *new_word_1;

    while(*words_1!=*words_2){
        words_1++;
        count++;
    }
    new_word_1=words_1+1;
    count++;
    while (*words_1 == *words_2 && *words_2 != '\0')
    {
        words_1++;
        words_2++;
    }
    if (*words_1=='\0'&&*words_2!='\0')
        return 0;
    if(*words_2=='\0')
        return count-1;
    return OneInTwo(new_word_1, word_2_begin);
}
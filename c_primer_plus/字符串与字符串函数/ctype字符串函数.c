//ctype.h字符串函数和字符串
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 81

void to_uppor(char *);
int punct_count(const char *);

int main(void){
    char input[SIZE];
    char *find;  //用来查找'\n'的位置
    puts("please enter a line");
    fgets(input,SIZE,stdin);
    find=strchr(input,'\n');
    if(find)
        *find='\0';
    to_uppor(input);
    puts(input);
    printf("punt: %d\n", punct_count(input));
    return 0;
}

void to_uppor(char *words){
    while(*words){
        *words=toupper(*words);
        words++;
    }
}

int punct_count(const char *words){
    int count=0;
    while(*words){
        if(ispunct(*words))
            count++;
        words++;
    }
    return count;
}

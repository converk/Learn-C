//删除输入字符串里的空格
#include<stdio.h>
#include<string.h>

#define MAX 81

char *s_gets(char *words, int size);
void DeleteSpace(char *);

int main(int argc, char const *argv[])
{
    char words[MAX];
    fputs("please enter a strings: ",stdout);
    while(*s_gets(words,MAX)){
        DeleteSpace(words);
        puts(words);
        fputs("please enter a strings: ", stdout);
    }
    return 0;
}

char *s_gets(char *words, int size){
    char *rev_lev;
    int i;
    rev_lev=fgets(words, size, stdin);
    //printf("rev_lev==words:%d\n", rev_lev == words);
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

void DeleteSpace(char *words){
    char *FindSpace;
    char *SpaceNext;
    char *temp;
    FindSpace=strchr(words,' ');
    while(FindSpace){
        temp=FindSpace;
        SpaceNext=FindSpace+1;
        while(*SpaceNext!='\0'){
            *FindSpace=*SpaceNext;
            FindSpace=SpaceNext;
            SpaceNext++;
        }
        *(SpaceNext-1)='\0';
        FindSpace=strchr(temp,' ');
    }
}
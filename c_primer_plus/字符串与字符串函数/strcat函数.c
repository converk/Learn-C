
//strcat函数

#include<stdio.h>
#include<string.h>
#define SIZE 25
char * s_gets(char *, int);

int main(void){
    char flower[SIZE];
    char addon[]="s smell like old shoes";
    puts("what's flower you like");
    while(s_gets(flower,SIZE)){
        strcat(flower,addon);   //flower会变,但addon不会变
        puts(flower);
        puts(addon);
    }
    puts("Bye!!!");
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
//结构数组

#include<stdio.h>
#include<string.h>
char *s_gets(char *, int);

#define MAXBOOKS 2
#define MAXTITL 40
#define MAXAUTHOR 40

struct book{
    char title[MAXTITL];
    char author[MAXAUTHOR];
    float value;
};

int main(void){
    struct book library[MAXBOOKS];
    int count=0;
    int index;

    puts("please input the book title");
    puts("input ENTER to quit");
    while(count<MAXBOOKS&&s_gets(library[count].title,MAXTITL)&&library[count].title[0]!='\0'){
        puts("please enter the author");
        s_gets(library[count].author, MAXAUTHOR);
        puts("Now enter the value");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
                //不加这个会把回车读到下一个字符里面,导致程序直接结束
            continue;
        if(count<MAXBOOKS)
            puts("please input the book title");
    }

    if(count>0){
        puts("there is the massage of books");
        for(index=0;index<count;index++)
            printf("%s by %s :  %.2f\n",
            library[index].title,library[index].author,library[index].value);
    }
    else
        printf("there is not books");
    return 0;
}

char *s_gets(char *words, int size){
    char *rev_lev;
    char *find;
    int i;
    rev_lev=fgets(words, size, stdin);
    //printf("rev_lev==words:%d\n", rev_lev == words);
    if(rev_lev){
        find=strchr(rev_lev,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return rev_lev;
}
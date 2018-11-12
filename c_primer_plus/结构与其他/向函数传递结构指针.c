//传递结构指针,无返回ty
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NLEN 30

struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
    /* data */
};

char *s_gets(char *, int);
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect*);

int main(){
    struct namect *person;

    person=malloc(sizeof(struct namect));  //必须要先初始化指针

    getinfo(person);
    makeinfo(person);
    showinfo(person);

    free(person);
    return 0;
}
void getinfo(struct namect *person){
    puts("please input your first name");
    s_gets(person->fname,NLEN);
    puts("please input your last name");
    s_gets(person->lname,NLEN);
}

void makeinfo(struct namect *person){
    person->letters=strlen(person->fname)+strlen(person->lname);
}

void showinfo(const struct namect *person){
    printf("%s %s your names contain %d latters\n", person->fname,person->lname,person->letters);
}

char *s_gets(char *words, int size)
{
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
// 结构指针字符串和malloc(这下可以用指针来存储字符串, 不过要先malloc)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NLEN 30

struct namect
{
    char *fname;
    char *lname;
    int letters;
    /* data */
};

char *s_gets(char *, int);
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect*);
void clean_up(struct namect *);

int main(){
    struct namect person;  //声明的时候已经给了存储空间

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    clean_up(&person);

    return 0;
}
void getinfo(struct namect *person){
    char temp[NLEN];

    puts("please input your first name");
    s_gets(temp,NLEN);
    person->fname = (char *)malloc(strlen(temp)+1);  //注意这里的malloc方式
    strcpy(person->fname,temp);

    puts("please input your last name");
    s_gets(temp, NLEN);
    person->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(person->lname, temp);
}

void makeinfo(struct namect *person){
    person->letters=strlen(person->fname)+strlen(person->lname);
}

void showinfo(const struct namect *person){
    printf("%s %s your names contain %d latters\n", person->fname,person->lname,person->letters);
}

void clean_up(struct namect *person){
    free(person->lname);
    free(person->fname);
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
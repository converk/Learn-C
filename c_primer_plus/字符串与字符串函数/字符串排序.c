//字符串排序:选择排序
#include<stdio.h>
#include<string.h>

#define SIZE 80
#define LIM 20

void sortstr(char *string[], int num);
char *s_gets(char *, int);

int main(void){
    int count=0;
    int k;
    char input[LIM][SIZE];   //待排序数组
    char *p[LIM];

    printf("pleast input %d strs ,and I will sort them\n",LIM);
    while(count<LIM && s_gets(input[count],SIZE) && input[count][0]!='\0'){
        p[count]=input[count];  //设置指向字符串的指针
        count++;
    }
    sortstr(p,count);
    for (k=0;k<count;k++){
        puts(p[k]);  //如果这里用input而不是p的话,结果是不会变的
                    //排序改变了指针,但是并没有改变字符串本来的顺序
    }

    return 0;
}

char *s_gets(char *words, int size){
    char *rev_lev;
    int i;
    rev_lev=fgets(words, size,stdin);
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

void sortstr(char *string[], int num){
    int i,j;
    char *temp;
    for(i=0;i<num-1;i++)
        for(j=i+1; j<num;j++){
            if(strcmp(string[i],string[j])>0){
                temp=string[i];
                string[i]=string[j];
                string[j]=temp;
            }
        }
}
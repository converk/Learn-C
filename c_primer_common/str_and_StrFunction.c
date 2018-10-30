//字符串常量,多次调用的时候相当于指向字符串存储位置的指针
// #include<stdio.h>
// int main(void){
//     printf("%s,  %p,  %c\n", "we", "qewqw", *"weqr"); //结果:we,  0x5617848e6704,  w
//     return 0;
// }

//字符串数组和初始化
// #include<stdio.h>
// int main(void){
//     const char ml[40]="limit yourself to one line's worth.";
//     const char m2[] = "limit yourself to one line's worth.";
//     printf("%lu\n", sizeof(m2)/sizeof(char));
// }


//fgets()使用实例, 舍弃输入缓冲区,把回车换成结束符
// #include<stdio.h>
// #define STLEN 10
// int main(void){
//     char words[STLEN];
//     int i;
//     puts("enter strings (empty to quit)");
//     while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
//     {
//         i=0;
//         while (words[i] != '\n' && words[i] != '\0'){
//             i++;
//         }
//         if (words[i] == '\n')
//         {
//             words[i] = '\0';
//         }
//         else
//         {
//             while (getchar() != '\n')  //除去缓冲区剩余的
//             {
//                 continue;
//             }
//         }
//         puts(words);
//     }
//     puts("bye!!!");
//     return 0;
// }

//scanf()的使用
// #include<stdio.h>
// int main(void){
//     char name1[11],name2[11];
//     int count;

//     puts("enter two names");
//     count=scanf("%11s %10s",name1,name2);  //注意读入的字符长度要比数组少一,不然没地方放终止符
//     printf("I read %d names %s and %s\n",count,name1,name2);
//     return 0;
// }

//strlen()函数
// #include<stdio.h>
// #include<string.h>
// void fit(char *,int);

// int main(void){
//     char words[]="things should be as simple as possible,"" but not simpler";
//     puts(words);
//     fit(words,38);
//     puts(words);
//     puts(" let's look at some more of the string");
//     puts(words+39);  //会继续打印出之后的字符串
//     return 0;
// }

// void fit(char *words, int n){
//     if (strlen(words)>n)
//         words[n]='\0';  //超过字长,加终止符
// }

//strcat函数

// #include<stdio.h>
// #include<string.h>
// #define SIZE 25
// char * s_gets(char *, int);

// int main(void){
//     char flower[SIZE];
//     char addon[]="s smell like old shoes";
//     puts("what's flower you like");
//     while(s_gets(flower,SIZE)){
//         strcat(flower,addon);   //flower会变,但addon不会变
//         puts(flower);
//         puts(addon);
//     }
//     puts("Bye!!!");
//     return 0;
// }

// char *s_gets(char *words, int size){
//     char *rev_lev;
//     int i;
//     rev_lev=fgets(words, size,stdin);
//     printf("rev_lev==words:%d\n", rev_lev == words);
//     if(rev_lev){
//         i=0;
//         while (rev_lev[i]!='\0'&&rev_lev[i]!='\n')
//             i++;
//         if (rev_lev[i] == '\n')
//             rev_lev[i]='\0';
//         else
//             while(getchar()!='\n')
//                 continue;
//     }
//     return rev_lev;
// }


//strcmp()的用法,相同就返回0,否则返回非零值,两个参数都为指针
// #include<stdio.h>
// #include<string.h>
// #define SIZE 40
// #define ANSWER "grant"

// char *s_gets(char *, int);

// int main(void){
//     char try[SIZE];
//     puts("who is buried in grant's tomb");
//     //while(*(s_gets(try,SIZE))!=*ANSWER)  //两个都是指针,都要解引用,但解引用只得到第一个字符,不会得到全部的字符串
//     while (strcmp(s_gets(try, SIZE), ANSWER) != 0)
//         puts("please input again");
//     puts("right!!!!");
//     return 0;
// }

// char *s_gets(char *words, int size){
//     char *rev_lev;
//     int i;
//     rev_lev=fgets(words, size,stdin);
//     printf("rev_lev==words:%d\n", rev_lev == words);
//     if(rev_lev){
//         i=0;
//         while (rev_lev[i]!='\0'&&rev_lev[i]!='\n')
//             i++;
//         if (rev_lev[i] == '\n')
//             rev_lev[i]='\0';
//         else
//             while(getchar()!='\n')
//                 continue;
//     }
//     return rev_lev;
// }


//字符串排序:选择排序
// #include<stdio.h>
// #include<string.h>

// #define SIZE 80
// #define LIM 20

// void sortstr(char *string[], int num);
// char *s_gets(char *, int);

// int main(void){
//     int count=0;
//     int k;
//     char input[LIM][SIZE];   //待排序数组
//     char *p[LIM];

//     printf("pleast input %d strs ,and I will sort them\n",LIM);
//     while(count<LIM && s_gets(input[count],SIZE) && input[count][0]!='\0'){
//         p[count]=input[count];  //设置指向字符串的指针
//         count++;
//     }
//     sortstr(p,count);
//     for (k=0;k<count;k++){
//         puts(p[k]);  //如果这里用input而不是p的话,结果是不会变的
//                     //排序改变了指针,但是并没有改变字符串本来的顺序
//     }

//     return 0;
// }

// char *s_gets(char *words, int size){
//     char *rev_lev;
//     int i;
//     rev_lev=fgets(words, size,stdin);
//     //printf("rev_lev==words:%d\n", rev_lev == words);
//     if(rev_lev){
//         i=0;
//         while (rev_lev[i]!='\0'&&rev_lev[i]!='\n')
//             i++;
//         if (rev_lev[i] == '\n')
//             rev_lev[i]='\0';
//         else
//             while(getchar()!='\n')
//                 continue;
//     }
//     return rev_lev;
// }

// void sortstr(char *string[], int num){
//     int i,j;
//     char *temp;
//     for(i=0;i<num-1;i++)
//         for(j=i+1; j<num;j++){
//             if(strcmp(string[i],string[j])>0){
//                 temp=string[i];
//                 string[i]=string[j];
//                 string[j]=temp;
//             }
//         }
// }


//ctype.h字符串函数和字符串
// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>

// #define SIZE 81

// void to_uppor(char *);
// int punct_count(const char *);

// int main(void){
//     char input[SIZE];
//     char *find;  //用来查找'\n'的位置
//     puts("please enter a line");
//     fgets(input,SIZE,stdin);
//     find=strchr(input,'\n');
//     if(find)
//         *find='\0';
//     to_uppor(input);
//     puts(input);
//     printf("punt: %d\n", punct_count(input));
//     return 0;
// }

// void to_uppor(char *words){
//     while(*words){
//         *words=toupper(*words);
//         words++;
//     }
// }

// int punct_count(const char *words){
//     int count=0;
//     while(*words){
//         if(ispunct(*words))
//             count++;
//         words++;
//     }
//     return count;
// }

#include<stdio.h>

#define WORDS "dasdasd"
int main(void){
    char words[]=WORDS;
    printf("%s\n",words);
    return 0;
}
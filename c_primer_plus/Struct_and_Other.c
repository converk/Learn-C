//结构数组

// #include<stdio.h>
// #include<string.h>
// char *s_gets(char *, int);

// #define MAXBOOKS 2
// #define MAXTITL 40
// #define MAXAUTHOR 40

// struct book{
//     char title[MAXTITL];
//     char author[MAXAUTHOR];
//     float value;
// };

// int main(void){
//     struct book library[MAXBOOKS];
//     int count=0;
//     int index;

//     puts("please input the book title");
//     puts("input ENTER to quit");
//     while(count<MAXBOOKS&&s_gets(library[count].title,MAXTITL)&&library[count].title[0]!='\0'){
//         puts("please enter the author");
//         s_gets(library[count].author, MAXAUTHOR);
//         puts("Now enter the value");
//         scanf("%f", &library[count++].value);
//         while (getchar() != '\n')  
                //不加这个会把回车读到下一个字符里面,导致程序直接结束
//             continue;
//         if(count<MAXBOOKS)
//             puts("please input the book title");
//     }

//     if(count>0){
//         puts("there is the massage of books");
//         for(index=0;index<count;index++)
//             printf("%s by %s :  %.2f\n",
//             library[index].title,library[index].author,library[index].value);
//     }
//     else
//         printf("there is not books");
//     return 0;
// }

// char *s_gets(char *words, int size){
//     char *rev_lev;
//     char *find;
//     int i;
//     rev_lev=fgets(words, size, stdin);
//     //printf("rev_lev==words:%d\n", rev_lev == words);
//     if(rev_lev){
//         find=strchr(rev_lev,'\n');
//         if(find)
//             *find='\0';
//         else
//             while(getchar()!='\n')
//                 continue;
//     }
//     return rev_lev;
// }

//指向结构的指针
// #include<stdio.h>
// #define LEN 20

// struct name{
//     char first[LEN];
//     char last[LEN];
// };

// struct guy{
//     struct name handle;  //嵌套结构,这个handle变量,在这里相当于声明
//     char favfood[LEN];
//     char job[LEN];
//     float income;
// };

// int main(int argc, char const *argv[])
// {
//     struct guy fellow[2]={
//         {
//             {"hu","bowen"},
//             "salmon",
//             "personality",
//             68112
//         },
//         {
//             {"xu","song"},
//             "tripe",
//             "editor",
//             432400
//         }
//     };  //声明一个结构数组
//     struct guy *him;
//     printf("address #1:%p, address #2: %p\n",&fellow[0],&fellow[1]);
//     him=&fellow[0];
//     printf("him #1:%p, him+1 #2: %p\n",him,him+1 );
//     printf("him->income is $%.2f: (*him).income if $%.2f\n", him->income, (*him).income);
//     //(*him).income和him->income一样
//     return 0;
// }

//向函数传递结构的信息

//传递结构的地址
// #include<stdio.h>
// #define FUNDLEN 50

// struct fund{
//     char bank[FUNDLEN];
//     double bankfound;
//     char save[FUNDLEN];
//     double savefound;
// };

// double sum(struct fund *);

// int main(void){
//     struct fund stan={
//         "BankBank",
//         4023.27,
//         "BankSave",
//         8543.94
//     };
//     printf("%.2f       %.2f\n", stan.bankfound, stan.savefound);
//     printf("the sum of bank: %.2f\n",sum(&stan));
//     printf("%.2f       %.2f\n", stan.bankfound, stan.savefound);
// }

// double sum(struct fund *money){
//     money->bankfound=1.0;
//     money->savefound=2.0;
//     return (money->bankfound + money->savefound);
// }


//传递结构指针,无返回
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// #define NLEN 30

// struct namect
// {
//     char fname[NLEN];
//     char lname[NLEN];
//     int letters;
//     /* data */
// };

// char *s_gets(char *, int);
// void getinfo(struct namect *);
// void makeinfo(struct namect *);
// void showinfo(const struct namect*);

// int main(){
//     struct namect *person;

//     person=malloc(sizeof(struct namect));  //必须要先初始化指针

//     getinfo(person);
//     makeinfo(person);
//     showinfo(person);

//     free(person);
//     return 0;
// }
// void getinfo(struct namect *person){
//     puts("please input your first name");
//     s_gets(person->fname,NLEN);
//     puts("please input your last name");
//     s_gets(person->lname,NLEN);
// }

// void makeinfo(struct namect *person){
//     person->letters=strlen(person->fname)+strlen(person->lname);
// }

// void showinfo(const struct namect *person){
//     printf("%s %s your names contain %d latters\n", person->fname,person->lname,person->letters);
// }

// char *s_gets(char *words, int size)
// {
//     char *rev_lev;
//     char *find;
//     int i;
//     rev_lev=fgets(words, size, stdin);
//     //printf("rev_lev==words:%d\n", rev_lev == words);
//     if(rev_lev){
//         find=strchr(rev_lev,'\n');
//         if(find)
//             *find='\0';
//         else
//             while(getchar()!='\n')
//                 continue;
//     }
//     return rev_lev;
// }

//结构,指针,字符串和malloc(这下可以用指针来存储字符串,不过要先malloc)
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// #define NLEN 30

// struct namect
// {
//     char *fname;
//     char *lname;
//     int letters;
//     /* data */
// };

// char *s_gets(char *, int);
// void getinfo(struct namect *);
// void makeinfo(struct namect *);
// void showinfo(const struct namect*);
// void clean_up(struct namect *);

// int main(){
//     struct namect person;  //声明的时候已经给了存储空间

//     getinfo(&person);
//     makeinfo(&person);
//     showinfo(&person);
//     clean_up(&person);

//     return 0;
// }
// void getinfo(struct namect *person){
//     char temp[NLEN];
    
//     puts("please input your first name");
//     s_gets(temp,NLEN);
//     person->fname = (char *)malloc(strlen(temp)+1);  //注意这里的malloc方式
//     strcpy(person->fname,temp);

//     puts("please input your last name");
//     s_gets(temp, NLEN);
//     person->lname = (char *)malloc(strlen(temp) + 1);
//     strcpy(person->lname, temp);
// }

// void makeinfo(struct namect *person){
//     person->letters=strlen(person->fname)+strlen(person->lname);
// }

// void showinfo(const struct namect *person){
//     printf("%s %s your names contain %d latters\n", person->fname,person->lname,person->letters);
// }

// void clean_up(struct namect *person){
//     free(person->lname);
//     free(person->fname);
// }

// char *s_gets(char *words, int size)
// {
//     char *rev_lev;
//     char *find;
//     int i;
//     rev_lev=fgets(words, size, stdin);
//     //printf("rev_lev==words:%d\n", rev_lev == words);
//     if(rev_lev){
//         find=strchr(rev_lev,'\n');
//         if(find)
//             *find='\0';
//         else
//             while(getchar()!='\n')
//                 continue;
//     }
//     return rev_lev;
// }


//伸缩数组成员的结构,一般声明不会声明变量,而是会声明指针,然后用malloc分配空间

// #include<stdio.h>
// #include<stdlib.h>

// struct flex{
//     size_t count;
//     double average;
//     double scores[];  //伸缩数组成员
// };

// void showflex(const struct flex * pf);

// int main(int argc, char const *argv[])
// {
//     struct flex *pf1;
//     int n=5;
//     int i;
//     int totle=0;

//     //分配空间
//     pf1=malloc(sizeof(struct flex)+n*sizeof(double));  //scores的大小为n
//     pf1->count=n;
//     for (i=0;i<n;i++){
//         pf1->scores[i]=20.0-i;
//         totle+=pf1->scores[i];
//     }
//     pf1->average=totle/n;
//     showflex(pf1);
//     free(pf1);

//     return 0;
// }

// void showflex(const struct flex *pf){
//     int i;
//     fputs("Scores: ",stdout);
//     for(i=0; i<pf->count; i++)
//         printf("%.1f ",pf->scores[i]);
//     printf("\nAvange: %.1f\n", pf->average);
// }

//联合union
// #include<stdio.h>

// union hold{
//     int digit;
//     double bigft;
//     char letter;
// };

// int main(void){
//     union hold valA;
//     valA.letter='A';
//     union hold valB = {.letter='a'};
//     union hold valC = {.digit=88}; //注意要加大括号
//     union hold valD = {.bigft = 50}; //当要赋值的类型不是联合的第一个的时候,要使用初始化器
//     printf("%c \n",valB);
//     printf("%d \n",valC);
//     printf("%f \n",valD);

//     return 0;
// }


//联合的另外一种用法
// struct owner{  //车没有租出去,拥有者的名字
//     char socsecurity[12];
// };

// struct leasecompany{   //车租出去了,租借者和租用公司的名字
//     char name[40];
//     char headquarters[40];
// };


// union data{  //二选一
//     struct owner owncar;
//     struct leasecompany leasecar;
//     /* data */
// };

// struct car_data{
//     char make[15];
//     int status;  //未租借为0,租借为1
//     union data ownerinfo;    //二选一
// };



//枚举类型
// #include<stdio.h>

// enum spectrum {red,orange,blue,green,pink};
// enum spectrum color;

// int main(void){
//     for (color=red;color<pink;color++)
//         printf("%d\n", color);
//     return 0;
// }
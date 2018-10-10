
/*判断温度*/
// #include<stdio.h>

// int main(void){
//     const int FREEZING=0;
//     float temp;
//     int cold_days=0,al3l_days=0;

//     while(scanf("%f",&temp) == 1){
//         all_days++;
//         if (temp<FREEZING){
//             cold_days++;
//         }
//     }

//     if (all_days){
//         printf("%d days total: %.1f%% were below", all_days,100.0*cold_days/all_days);
//     }
//     return 0;
// }

/*使用ctype.h判断是否是字符  使用getchar*/
// #include<stdio.h>
// #include<ctype.h>

// int main(void){
//     char ch;

//     while((ch = getchar()) != '\n'){
//         if (isalnum(ch))
//             putchar(ch+1);
        
//         else
//         {
//             putchar(ch);
//         }
        
//     }
//     putchar(ch);
//     return 0;
// }

/*求素数*/
// #include<stdio.h>
// #include<stdbool.h> // 这个库允许定义bool类型的变量

// int main(void){
//     unsigned long num;
//     unsigned long div;
//     bool simple=true;
//     printf("please input a num\n");
//     printf("enter q to quit\n");

//     while(scanf("%lu", &num) == 1){
//         for (div=2; (div*div)<=num; div++){
//             if (num%div == 0){
//                 printf("%lu is divable by %lu and %lu\n", num,div,num/div);
//                 simple=false;
//             }
//         }

//         if (simple){
//             printf("%lu is simple\n", num);
//         }

//         printf("please input a num\n");
//         printf("enter q to quit\n");
//     }
//     return 0;

// }

/*计算一个输入字符数 单词数 行数*/
// #include<stdio.h>
// #include<stdbool.h>
// #include<ctype.h>
// #define STOP '|'  //定义输入停止标志

// int main(void){
//     int n_chars=0;  //字符数
//     int n_lines=0;  //整行
//     int p_n_lines=0;  //办行
//     int n_words=0;

//     bool inword=false;  //判断是否在一个单词里

//     char c;  //当前读入字符
//     char pre_c='\n';  //上一个读入字符;

//     printf("please input a str(| to quit): \n");
    
//     while((c=getchar()) != STOP){
//         /* code */
//         n_chars++;
//         if (c == '\n'){
//             n_lines++;
//         }
//         if (isspace(c) && !inword){
//             inword=true;
//             n_words++;
//         }
//         if (isspace(c) && inword){
//             inword=false;
//         }
//         pre_c=c;
//     }
//     if (pre_c != '\n'){
//         p_n_lines = 1;
//     }
//     printf("lines:%d, chars: %d, words: %d, p_lines:%d\n",n_lines,n_chars,n_words,p_n_lines);
//     return 0;
    
// }
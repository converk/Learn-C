
/*求素数*/
#include<stdio.h>
#include<stdbool.h> //这个库允许定义bool类型的变量

int main(void){
    unsigned long num;
    unsigned long div;
    bool simple=true;
    printf("please input a num\n");
    printf("enter q to quit\n");

    while(scanf("%lu", &num) == 1){
        for (div=2; (div*div)<=num; div++){
            if (num%div == 0){
                printf("%lu is divable by %lu and %lu\n", num,div,num/div);
                simple=false;
            }
        }

        if (simple){
            printf("%lu is simple\n", num);
        }

        printf("please input a num\n");
        printf("enter q to quit\n");
    }
    return 0;

}
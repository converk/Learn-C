#include<stdio.h>
int main(){
    long num;
    long sum=0;
    int status;

    printf("please input a int,");
    printf("(q to quit):");

    while(scanf("%ld", &num) == 1){
        /* code */
        sum+=num;
        printf("next:");
    }
    printf("%ld", sum);
    return 0;
}
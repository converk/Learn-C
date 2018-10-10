#include<stdio.h>
#include "hotel.h"

int menu(void){
    int code,status;

    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms 2) Hotel Olmpic\n");
    printf("3) Chertworthy Plaza 4) The Stockton\n");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);

    while((status=scanf("%d", &code))!=1||(code<1||code>5)){
        if (status!=1){
            scanf("%*s");  //跳过无效的字符输入
        }
        printf("Enter the int in 1 to 5.\n");
    }
    return code;
}

int getnights(void){
    int nights;
    printf("how many nights you need:");
    while(scanf("%d", &nights)!=1){
        scanf("%*s");
        printf("Enter the int,such as 2.\n");
    }
    return nights;
}

void showprice(double rate, int nights){
    int n;
    double total=0.0;
    for (n=0; n<nights;n++, rate*=DISCOUNT){
        total+=rate;
    }
    printf("total cost: %6.2f", total);
}
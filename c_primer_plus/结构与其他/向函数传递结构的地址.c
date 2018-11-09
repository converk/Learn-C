//传递结构的地址
#include<stdio.h>
#define FUNDLEN 50

struct fund{
    char bank[FUNDLEN];
    double bankfound;
    char save[FUNDLEN];
    double savefound;
};

double sum(struct fund *);

int main(void){
    struct fund stan={
        "BankBank",
        4023.27,
        "BankSave",
        8543.94
    };
    printf("%.2f       %.2f\n", stan.bankfound, stan.savefound);
    printf("the sum of bank: %.2f\n",sum(&stan));
    printf("%.2f       %.2f\n", stan.bankfound, stan.savefound);
}

double sum(struct fund *money){
    money->bankfound=1.0;
    money->savefound=2.0;
    return (money->bankfound + money->savefound);
}

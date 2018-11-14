//快速计算幂
#include<stdio.h>

long int Poow(long int , unsigned int);

int main(void){
    long int X;
    unsigned int N;
    long int answer;
    printf("please input two int: ");
    scanf("%ld, %d", &X, &N);
    answer=Poow(X,N);
    printf("answer: %ld", answer);
    return 0;
}

long int Poow(long int X, unsigned int N){
    if(N==0){
        return 1;
    }
    if(N==1){
        return X;
    }
    if (!(N%2)){
        return Poow(X*X,N/2);
    }
    if(N%2){
        return Poow(X*X,N/2)*X;
    }
    return 0;   //不行了把这句话删掉
}



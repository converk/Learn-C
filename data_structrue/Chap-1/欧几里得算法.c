//欧几里得算法,求两个数的最大公因数

#include<stdio.h>
unsigned int gcd(unsigned int, unsigned int);

int main(void){

    int M, N;
    int answer;
    printf("please input two int: ");
    scanf("%d, %d", &M, &N);
    answer=gcd(M,N);
    printf("answer: %d\n",answer);
    return 0;
}

unsigned int gcd(unsigned int M, unsigned int N){
    unsigned temp;

    while(N>0){
        /* code */
        temp=M%N;
        M=N;
        N=temp;
    }
    return M;

}
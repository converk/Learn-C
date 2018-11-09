#include<stdio.h>
#define SIZE 10

long sump(int *, int *);
int main(void){
    int marbles[SIZE]={20,10,5,39,4,5,19,25,31,20};
    long int answer;

    answer=sump(marbles,marbles+SIZE);
    printf("the answer is : %ld", answer);
    return 0;
}

long sump(int * start, int * end){
    long total=0;

    while(start<end){
        total+=*start;
        start++;
    }
    return total;
}
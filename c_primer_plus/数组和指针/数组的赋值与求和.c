#include <stdio.h>
#define SIZE 10
int sum(int ar[], int n);

int main(void)
{
    int marbles[SIZE] = {[1] = 7, [2] = 8};
    int answer;
    int i;
    for (i=0; i<SIZE; i++){
        printf("%d ",marbles[i]);
    }
    printf("\n");
    answer = sum(marbles, SIZE);
    printf("marbles: %zd\n", sizeof(marbles));
    printf("total: %d\n", answer);
    return 0;
}

int sum(int *ar, int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
        total += ar[i];
    }
    printf("\n");
    printf("ar: %zd\n", sizeof(ar));  //这里打印出指针的大小,不同电脑不一样,ar是一个指针而不是一个数组
    return total;
}
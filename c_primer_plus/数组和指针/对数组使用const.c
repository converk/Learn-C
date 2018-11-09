//保护数组中的元素不变,使用const
#include<stdio.h>
#define SIZE 5

int show_array(const double *, int);
int add_array(double *, int, double);

int main(void){
    double array[SIZE]={20.0,17.66,8.2,15.3,22.22};
    show_array(array,SIZE);
    add_array(array, SIZE, 5.0);
    show_array(array, SIZE);
    return 0;
}

int show_array(const double *array, int N){
    int i;
    for (i=0; i<N;i++)
        printf("%8.3f", array[i]);
    putchar('\n');
    return 0;
}

int add_array(double *array, int N, double add){
    int i;
    for (i = 0; i < N; i++)
        array[i]+=add;
    return 0;
}
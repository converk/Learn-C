/*比较大小*/
#include<stdio.h>

int imin(int, int);

int main(){
    int evil1,evil2;

    printf("please input two nums(q to quit): ");

    while (scanf("%d,%d", &evil1, &evil2) == 2){
        printf("the lesser of %d and %d is %d.\n", evil1,evil2,imin(evil1,evil2));
        printf("please input two nums(q to quit): ");
    }
    return 0;
}

int imin(int evil1, int evil2){
    int result;
    return result=(evil1>evil2)?evil2:evil1;
}
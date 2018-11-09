//指针的各种操作
#include<stdio.h>

int main(void){
    int urn[5]= {100,200,300,400,500};
    int *p1,*p2,*p3;

    p1=urn;
    p2=&urn[2];

    printf("size of p1: %zd\n", sizeof(p1));

    printf("pointer value,  dereferenced pointer, pointer address\n");
    printf("p1=%p, *p1=%d, &p1=%p\n", p1, *p1, &p1);

    p3=p1+4;
    printf("\nadding an int to a pointer:\n");
    printf("p1+4= %p, *(p1+4)= %d\n", p1+4, *(p1+4));

    p1++;
    printf("\nvalues after p1++\n");
    printf("p1=%p, *p1=%d, &p1=%p\n", p1, *p1, &p1);

    p2--;
    printf("\nvalues after p2--\n");
    printf("p2=%p, *p2=%d, &p2=%p\n", p2, *p2, &p2);

    //恢复到原来的值
    p1--;
    p2++;
    printf("\npointers reset to orginal values:\n");
    printf("p1=%p, p2=%p",p1, p2);

    printf("\n p2 - p1\n");
    printf("p1=%p, p2=%p, p2 - p1= %ld\n", p1, p2, p2-p1);

    printf("p2>p1: %d", p2>p1);
    return 0;
}
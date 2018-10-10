// #include<stdio.h>

// int main()
// {
//     char ch;

//     for (ch='a';ch<='z';ch++){
//         printf("%c: %d",ch,ch);
//     }
//     return 0;
// }


/* 在输入6之前可以一直输入*/
// #include<stdio.h>

// int main(){
//     int num;
//     for (printf("keep inputing"); num!=6; scanf("%d", &num));
//     return 0;
// }

/*芝诺悖论*/
#include<stdio.h>

int main(){
    double time,x;
    int terms,count;

    printf("please input the terms: ");
    scanf("%d", &terms);
    for (count=1, time=0, x=1.0; count<=terms; ++count,x*=2.0){
        time+=1.0/x;
        printf("time: %f, terms: %d\n", time,count);
    }
}
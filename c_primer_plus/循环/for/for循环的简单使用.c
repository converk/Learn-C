/* 在输入6之前可以一直输入*/
 #include<stdio.h>

 int main(){
     int num;
     for (printf("keep inputing"); num!=6; scanf("%d", &num));
     return 0;
 }
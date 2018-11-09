//将一个字符串用其反序代替
#include<stdio.h>
int main(){
    char words[8]="fsdfsdf";
    char *p1;
    char *p2;
    char temp;
    p1=words;
    p2=words+(sizeof(words)/sizeof(char))-2;
    puts(words);
    while(p2 > p1){
        temp=*p1;
        *p1=*p2;
        *p2=temp;
        p1++;
        p2--;
    }
    puts(words);
    return 0;
}
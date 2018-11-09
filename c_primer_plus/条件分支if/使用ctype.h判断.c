/*使用ctype.h判断是否是字符  使用getchar*/
#include<stdio.h>
#include<ctype.h>

int main(void){
    char ch;

    while((ch = getchar()) != '\n'){
        if (isalnum(ch))
            putchar(ch+1);

        else
        {
            putchar(ch);
        }

    }
    putchar(ch);
    return 0;
}
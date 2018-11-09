#include<stdio.h>
int main(int argc, char const *argv[])
{
    int i,j,m;
    char p;
    char temp;
    scanf("%d%c",&i,&p);
    scanf("%d",&m);
    //temp=getchar();
    printf("%d,%d",i,m);
    printf("test:%c",p);  //temp为\n,当所有的整形输入完毕之后,敲下回车键,会被temp读入
    return 0;
}

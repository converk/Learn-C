#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>  //linux系统函数open()
#include <unistd.h> //getopt()函数
#include <stdlib.h>
#include <stdbool.h>  //可以直接用来定义bool
#include <sys/stat.h> //utimensat函数
#include <sys/time.h>

int main(int argc, char *argv[])
{
    char optStr[] = "ab";
    int c;

    while ((c = getopt(argc, argv, optStr)) != -1)
    {
        printf("optind: %d\n", optind);
        switch (c)
        {
        case 'a':
            printf("-a\n");
            break;
        case 'b':
            printf("-b\n");
            break;
        case '?':
            printf("error\n");
            break;
        }
    }
    printf("optind: %d\n", optind);
    return 0;
}
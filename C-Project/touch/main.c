#include<stdio.h>
#include<getopt.h>
#include<sys/types.h>
#include<time.h>
#include<fcntl.h>     //linux系统函数open()
#include<unistd.h>    //getopt()函数
#include<stdlib.h>
#include<stdbool.h>   //可以直接用来定义bool
#include <sys/stat.h> //utimensat函数
#include<sys/time.h>

#define CH_ATIME 1   //更改访问时间
#define CH_MTIME 2   //更改修改时间

#define UTIME_NOW ((1l << 30) - 1l)
#define UTIME_OMIT ((1l << 30) - 2l)
#define AT_FDCWD -100

//定义创建文件时,用户,用户组,其他用户的权限都是可读可写
#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
//标志文档的读取时间和改变时间的修改情况
static int change_time;
//如果命令中有-c选项,且后面跟的文件名不存在,则不创建文档
static bool no_create;
//当需要更改时间戳的时候用到
static struct timespec newtime[2];   //一个是访问时间,一个是修改时间

bool mytouch(const char *file);

int main(int argc, char *argv[])
{
    int c;    //获取命令行参数
    bool ok=true;  //初始化三个参数
    change_time=0;
    no_create=false;
    //从命令行中得到命令的选项，即'-'开头的才叫参数。目前只支持三种选型-a, -c, -m
    while((c=getopt(argc,argv,"acm"))!=-1){     //获取命令行参数
        
        switch (c)
        {
            case 'a':
                change_time=CH_ATIME;   //访问时间
                break;
            case 'c':
                no_create=true;        //不创建
                break;
            case 'm':
                change_time=CH_MTIME;   //修改时间
                break;

            default:
                printf("Something Error!");
                break;
        }
    }
    if(change_time==0)
        change_time=CH_ATIME | CH_MTIME;
    //修改文件选项
    newtime[0].tv_nsec = UTIME_NOW;  //更改访问时间
    newtime[1].tv_nsec = UTIME_NOW;  //更改修改时间
    if(optind==argc){   //当指向的下一个索引与参数个数相等的时候,说明没有文件选项
        printf("ERROR!");
        return 0;
    }
    //针对多个文档名字调用mytouch函数
    for (; optind < argc; ++optind)   //当参数读取完毕的时候,optind正好在文件参数的位置
        ok &= mytouch(argv[optind]);  //判断是否操作成功
    exit(ok ? EXIT_SUCCESS : EXIT_FAILURE);
    return 0;
}

//mytoch的基本逻辑
//先判断no_create的值,如果为true,则不创建文件
//然后检测 change_times 的值，并根据其值做相关的处理。
bool mytouch(const char *file){
    bool ok;
    int fd=-1;   //创建或者打开文档的返回值
    //O_CREAT | O_WRONLY 代表该函数的选项是文档不存在则创建和只写打开。
    //最后一个参数指定创建的文档的权限是所有用户可读可写。
    if(!no_create)
        fd = open(file, O_CREAT | O_WRONLY, MODE_RW_UGO);
    //如果change_time!= (CH_ATIME | CH_MTIME),那么就说明检测到了(-a)或者(-m),
    //在判断具体的数字来确定改变访问时间还是修改时间
    if (change_time != (CH_ATIME | CH_MTIME)){
        if(change_time==CH_MTIME){
            newtime[0].tv_nsec = UTIME_OMIT;   //当修改修改时间的时候,保证访问时间不变
        }else{
            newtime[1].tv_nsec = UTIME_OMIT; //当修改访问时间的时候,保证修改时间不变
        }
    }
    //AT_FDCWD为当前工作目录,file为文件名,newtime是更改时间,0为默认值
    ok = (utimensat(AT_FDCWD, file, newtime, 0) == 0); 
    return ok;
}
# C语言实现ls命令

## ls

### 显示文件信息

* 文件所在的inode值，
* 权限信息，
* 用户主和所属的组，
* 最后修改日期，
* 文件名，
* 链接数等等。

## 使用的头文件

### stdio.h

`perror()`函数:  
函数原型:`void perror(char *string)`;  
用来将**上一个函数**发生错误的原因输出到标准错误(stderr)。参数string所指的字符串会先打印出，后面再加上错误原因字符串,这里的错误原因指的是上一个函数出错后所弹出的错误,会被perror()捕获并打印输出

### time.h

包含ctime()的声明:  
函数原型:`char *ctime(const time_t *timep);`,将timep转换为真是世界的时间，以字符串显示，它和asctime不同就在于传入的参数形式不一样,输出示例: `Sat Jan 12 01:25:29 2008`

### dirent.h

Linux下遍历目录的方法:打开目录->读取目录->关闭目录  
三个函数的原型声明如下:

```.c
#include <dirent.h>
DIR *opendir(const char *dirname);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
```

`opendir`用于打开目录，返回一个指向DIR结构体的指针,失败返回NULL.，参数*dirname是一个字符数组或者字符串常量；

`readdir`函数用于读取目录，只有一个参数，就是`opendir`返回的DIR结构体指针，或者叫句柄更容易理解些吧。这个函数也返回一个结构体指针`dirent *`；

#### DIR结构体定义

```.c
struct __dirstrea
{
    void *__fd;
    char *__data;
    int __entry_data;
    char *__ptr;
    int __entry_ptr;
    size_t __allocation;
    size_t __size;
    __libc_lock_define (, __lock)
};
typedef struct __dirstream DIR;
```

#### dirent的结构定义

```.c
struct dirent
{
    long d_ino;   //文件的索引节点号inode
    off_t d_off;
    unsigned short d_reclen;   //这个文件的长度，需要注意的是这里的长度并不是指文件大小
    char d_name [NAME_MAX+1];  //文件名称
}
```

通过`readdir`函数读取到的文件名存储在结构体`dirent`的`d_name`成员中  
而函数 `int stat(const char *file_name, struct stat *buf)`;的作用就是获取文件名为d_name的文件的详细信息，存储在stat结构体中(就是函数参数里面的buf这个结构体),这个结构体的声明在`<sys/stat.h>`里面

### sys/stat.h

在使用这个结构体和方法时，需要引入：`<sys/types.h>`,`<sys/stat.h>`  
`struct stat`这个结构体是用来描述一个linux系统文件系统中的文件属性的结构。

下面为该结构体的定义:

```.c
struct stat {
        mode_t     st_mode;       //文件访问权限
        ino_t      st_ino;       //索引节点号
        dev_t      st_dev;        //文件使用的设备号
        nlink_t    st_nlink;      //文件的硬连接数
        uid_t      st_uid;        //所有者用户识别号
        gid_t      st_gid;        //组识别号
        off_t      st_size;       //以字节为单位的文件容量
        time_t     st_atime;      //最后一次访问该文件的时间
        time_t     st_mtime;      //最后一次修改该文件的时间
        time_t     st_ctime;      //最后一次改变该文件状态的时间
        blksize_t st_blksize;    //包含该文件的磁盘块的大小
        blkcnt_t   st_blocks;     //该文件所占的磁盘块
      };
```

#### mode_t类型详解

`mode_t`是无符号整形(unsign int),一般用于**表示文件的权限**的时候,使用此定义,它由下面几个数按位或而来

```.c
    S_IRUSR     00400       文件所有者具可读取权限  
    S_IWUSR     00200       文件所有者具可写入权限  
    S_IXUSR     00100       文件所有者具可执行权限  
    S_IRGRP     00040       用户组具可读取权限  
    S_IWGRP     00020       用户组具可写入权限  
    S_IXGRP     00010       用户组具可执行权限  
    S_IROTH     00004       其他用户具可读取权限  
    S_IWOTH     00002       其他用户具可写入权限  
    S_IXOTH     00001       其他用户具可执行权限  
```

上面九个权限,也就是用户,用户组,其他用户对于一个文件的权限的表达,比如如果 mode_t stmode=755 那么相应的权限就可以写为`rwxr-xr-x`(这里没有包含第一个文件类型描述'd'或者'-')  
对于stat结构体中的第一个元素st_mode就是像上述755那样的一串数字,表示了三个群体对于这个文件的权限

#### 判断一个文件是何种类型的几个宏定义

```.c
S_ISLNK(st_mode)：是否是一个连接.
S_ISREG(st_mode)：是否是一个常规文件.
S_ISDIR(st_mode)：是否是一个目录
S_ISCHR(st_mode)：是否是一个字符设备.
S_ISBLK(st_mode)：是否是一个块设备
S_ISFIFO(st_mode)：是否 是一个FIFO文件.
S_ISSOCK(st_mode)：是否是一个SOCKET文件
```

输入参数就是上述stat结构体指针的第一个元素的类型--`mode_t`,如果是相应的类型,返回true,否则返回false

### unistd.h

unistd.h是unix std的意思，是POSIX标准定义的unix类系统定义符号常量的头文件，包含了许多UNIX系统服务的函数原型，例如`read`函数、`write`函数和`getpid`函数

### sys/types.h

`time_t`:linux下存储时间常见的有两种存储方式，一个是从1970年01月01日 0:00:00到现在经过了多少秒，一个是用一个结构来分别存储年月日时分秒的。`time_t` 这种类型就是用来存储从1970年到现在经过了多少秒,要想更精确一点，可以用结构struct timeval，它精确到微妙

`off_t`:off_t类型用于指示文件的偏移量，常就是long类型，其默认为一个32位的整数，在gcc编译中会被编译为long int类型，在6`4位的Linux系统中则会被编译为long long int`，这是一个64位的整数，其定义在unistd.h头文件中可以查看

## 大致想法

1. 先检索出目录下所有的文件,并存储在一个链表里面
2. 再根据命令行输入的命令不同,调用不同的函数,对链表里面的文件的信息进行不同处理,并打印输出
3. 对于不同的命令行参数(-a,-l),调用不同的函数
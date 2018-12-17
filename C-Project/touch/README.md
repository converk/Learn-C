# C语言实现touch命令

## 基础一

getopt使用来解决参数处理的函数,包含在头文档 `#include <unistd.h>` 。一般形式如下：

```.c
int getopt(int argc, char *const argv[], const char *optstring)
```

作用： 分析命令行参数。 返回值：参数字符。

1. 参数argc 和argv 是由main()传递的参数个数和内容。
2. 参数optstring 则代表欲处理的选项字符串。

此函数会返回在argv 中下一个的选项字母，此字母会对应参数optstring 中的字母。
如果找到符合的参数则返回此参数字母, 如果参数不包含在参数optstring 的选项字母则返回"?"字符,分析结束则返回-1.

## 基础二

函数`open`是 UNIX 系统的系统调用函数，区别于 C 语言库函数 `fopen` 。包含在头文档 `#include <fcntl.h>` ，一般形式如下：

```.c
int open(constchar *pathname, int flags);
int open(constchar *pathname, int flags, mode_t mode);
```

作用：打开和创建文档。返回值：成功则返回文档描述符，否则返回 -1
对于 open 函数来说，第三个参数仅当创建新文档时（即使用了 O_CREAT 时）才使用，用于指定文档的访问权限位（access permission bits）.`pathname` 是待打开/创建文档的 POSIX 路径（如/home/user/a.cpp);`flags` 用于指定文档的打开/创建模式，这个参数可由以下常量（定义于fcntl.h）通过逻辑位或逻辑构成。
> O_RDONLY 只读模式  
> O_WRONLY 只写模式  
> O_RDWR 读写模式  
参数 mode 只有在创建新文档时才会生效
  
对于 open 函数来说， file 是用户输入的文档名字。 O_CREAT | O_WRONLY 代表该函数的选项是文档不存在则创建和只写打开。最后一个参数指定创建的文档的权限是所有用户可读可写。

`fd = open(file, O_CREAT | O_WRONLY, MODE_RW_UGO);`

## 基础三

函数 `utimensat` 以纳秒级的精度改变文档的 时间戳.包含在 `#include <sys/stat.h>` ，一般形式如下：

```.c
int utimensat(int dirfd, const char *pathname,const struct timespec times[2], intflags);
```

作用： `utimensat` 是以纳秒级的精度改变文档的时间戳.`utimensat()` 通过文档的路径（ pathname ）获得文档。
这个系统调用函数都是通过一个时间数组 times 来改变时间戳的， `times[0]` 修改最后一次访问的时间(access time)， `times[1]` 修改最后修改的时间 (modify time)。该时间数组是由秒和纳秒两个部分组成，数据结构如下：

```.c
struct timespec {
time_t tv_sec; /* 秒 */  
long tv_nsec; /* 纳秒 */
};
```

特别注意：
当 `times[x].tv_sec = UTIME_OMIT`; 相应的时间戳不变， `times[x].tv_sec = UTIME_NOW`; 相应的时间戳编程当前时间

`int dirfd`一般为 `AT_FDCWD`，其定义在 include/uapi/linux/fcntl.h，是一个特殊值（-100），该值表明当 filename 为相对路径的情况下将当前进程的工作目录设置为起始路径

## 基础四

`touch file1.txt` 更新 file1.txt 的访问和修改时间

`touch -a file1.txt` 改变 file1.txt 的读取时间记录

`touch -c file1.txt` 如果 file1.txt 不存在，不创建文档

`touch -m file1.txt` 改变 file1.txt 的修改时间记录

## 基础五

`int argc, char **argv`

`argc`是命令行总的参数个数  
`argv[]`是argc个参数，其中第0个参数是程序的全名，以后的参数  
命令行后面跟的用户输入的参数
`char *argv[]`是一个字符数组,其大小是int argc,主要用于命令行参数argv[]参数，数组里每个元素代表一个参数;
#include<stdio.h>
#include<time.h>
#include<stdlib.h>   //一些常用的函数声明
#include<string.h>   //处理字符串
#include<dirent.h>   //读取目录
#include<sys/stat.h>  //读取文件,获得文件的详细信息
#include<sys/types.h>  //系统下常用的数据类型,time_t和off_t的声明
#include <unistd.h>    // C C++ 提供对 POSIX 操作系统 API 的访问功能的头文件

//保存一个目录下所有文件的信息
typedef struct dir_link{
    char d_name[256];  //文件的名字
    struct dir_link *next;  //指向下一个文件
}dirlink;

//单个文件的详细信息
typedef struct item_info{
    int inode;          //文建索引节点号
    char permission[11];//权限,一个文件类型,3*3个权限,外加一个终止符
    int user;           //用户
    int group;          //用户所在的组
    time_t mod_time;    //修改时间,time_t其实就是长整形long,记录从1970年到现在的秒数
    off_t size;         //文件大小,linux里面,off_t默认是32位的long
    char d_name[256];   //文件名
}info;

//得到目录下的每一个文件并储存在链表里
dirlink* get_dir_all_file(char *dir_path_name){
    DIR *open_dir;                                           //opendir()的返回类型
    struct dirent *read_dir;                                 //readdir()的返回类型
    dirlink *head_node = (dirlink *)malloc(sizeof(dirlink)); //返回链表的头结点
    head_node->next = NULL;                                  //初始化头结点
    strcpy(head_node->d_name, "0");                          //初始化头结点里面的字符数组
    dirlink *current_node = head_node;                       //返回链表当前所指向的节点
    dirlink *next_node = NULL;                               //下一个节点

    open_dir = opendir(dir_path_name); //打开目录
    if (!open_dir)                     //打开错误
        return NULL;
    while ((read_dir = readdir(open_dir)) != NULL)
    {
        if ((strcmp(read_dir->d_name, ".") == 0) || (strcmp(read_dir->d_name, "..") == 0))
            continue;                                //忽略指向当前目录的文件和指向上一级目录的文件
        next_node = malloc(sizeof(dirlink));         //创建一个新节点,将当前文件的信息插入到链表里
        strcpy(next_node->d_name, read_dir->d_name); //把文件名赋值给下一个节点
        next_node->next = NULL;
        current_node->next = next_node;
        current_node = current_node->next;
    }
    closedir(open_dir);
    return head_node;
}

//打印目录下每一个文件的信息
void print_file_info(dirlink *head_node){
    struct stat file_stat;          //获取文件的全部信息后得到的stat型结构指针
    dirlink *curret_node=head_node->next;  //保存当前读取到哪个文件
    info file_info;   //定义文件的信息,stat得到的值的一部分,按照结构体的内容保存到file_info里
    static char *perm[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};//各种权限的可能

    while(curret_node!=NULL){
        int i=3;
        int j=0;
        unsigned int mask=0700;  //权限的名字,用来从stat的返回值里面提取出相应的权限

        if (stat(curret_node->d_name, &file_stat) == -1)
        {
            // printf("%s", curret_node->d_name);
            perror("can't get this file's info");   //弹出stat函数如果获取info失败后的信息
            curret_node=curret_node->next;
            continue;
        }

        if (S_ISREG(file_stat.st_mode))//是一个文件
            file_info.permission[0] = '-';
        else if (S_ISDIR(file_stat.st_mode)) //是一个目录
            file_info.permission[0] = 'd';

        while (i > 0){    //用来获取权限
            file_info.permission[1 + j * 3] = perm[(file_stat.st_mode & mask) >> (i - 1) * 3][0];
            file_info.permission[2 + j * 3] = perm[(file_stat.st_mode & mask) >> (i - 1) * 3][1];
            file_info.permission[3 + j * 3] = perm[(file_stat.st_mode & mask) >> (i - 1) * 3][2];
            i--;
            j++;
            mask >>= 3;
        }

        //获取文件的其他信息
        file_info.inode = file_stat.st_ino;
        file_info.permission[10]='\0';
        file_info.user=file_stat.st_uid;
        file_info.group=file_stat.st_gid;
        file_info.mod_time=file_stat.st_mtime;
        file_info.size=file_stat.st_size;
        strcpy(file_info.d_name,curret_node->d_name);
        
        //打印信息
        printf("%u ", file_info.inode);
        printf("%s ", file_info.permission);
        if (file_info.user==1000){
            printf("%s ", "hbw");
            printf("%s ", "hbw");
        }
        else{
            printf("%s ", "root");
            printf("%s ", "root");
        }
        printf("%lu ", file_info.size);
        printf("%s ", ctime(&(file_info.mod_time)));  //ctime()函数在time.h里面
        printf("%s\n", file_info.d_name);
        printf("\n");
        curret_node = curret_node->next;
    }
}

void ls_a(dirlink *head_node)
{
    if (!head_node)
        return;
    dirlink *current_node = head_node->next;
    while (current_node != NULL){
        printf("%s  ", current_node->d_name);
        current_node=current_node->next;
    }
    printf("\n");
}

void ls_l(dirlink *head_node){
    if (!head_node)
        return;
    dirlink *current_node = head_node;
    while(current_node->next){
        if(*(current_node->next->d_name)=='.'){
            dirlink *delnode;
            delnode = current_node->next;
            current_node->next = current_node->next->next;
            free(delnode);
            continue;
        }
        current_node = current_node->next;
        if(current_node==NULL)
            break;
    }
    current_node = head_node->next;
    while (current_node != NULL)
    {
        printf("%s  ", current_node->d_name);
        current_node = current_node->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    dirlink *head=get_dir_all_file(".");
    if(argc==2){
        switch (*(argv[1]+1))
        {
            case 'a':   //ls -a
                ls_a(head);
                break;
            case 'l':   //ls -l
                ls_l(head);
                break;

            default:
                break;
        }
    }else{
        print_file_info(head);
    }
    return 0;
}





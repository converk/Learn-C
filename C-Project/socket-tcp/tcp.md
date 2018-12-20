# C语言Socket编程实现TCP

## 面向连接的套接字Socket通信工作流程

为了实现服务器与客户端的通信过程,两端都要建立套接字,二者的工作原理描述如下

1. 服务器先用 socket 函数来建立一个套接字,用这个套接字完成通信的监听,它是系统分配给该服务器进程的类似文件描述符的资源，不能与其他进程共享
2. 用 `bind` 函数来绑定一个端口号和 IP 地址, 服务器进程使用bind系统调用给套接字命名。本地套接字的名字是linux文件系统的文件名，一般放在/tmp或者/usr/tmp 目录下,因为一个计算机下有多个进程,每个进程对应着一个或者多个端口,必须指定一个端口进行监听客户机的数据
3. 服务器调用 `listen` 函数,使服务器的这个端口和 IP 处于监听状态,等待客户机的连接
4. 客户机用 `socket` 函数建立一个套接字,设定远程 IP 和端口
5. 客户机调用 `connect` 函数连接远程计算机指定的端口
6. 服务器用 `accept` 函数来接受远程计算机的连接,建立起与客户机之间的通信
7. 建立连接以后,客户机用 `write` 函数向 socket 中写入数据。也可以用 `read` 函数读取服务器发送来的数据.
8. 服务器用 `read` 函数读取客户机发送来的数据,也可以用 `write` 函数来发送数据.
9. 完成通信以后,用 `close` 函数关闭 socket 连接.

## 实现过程中的困难

### struct sockaddr_in

struct sockaddr_in这个结构体用来处理网络通信的地址
内容:

1. sin_family: 地址族,AF_INET表示IP地址族
2. sin_port: 16位TCP/UDP端口号
3. sin_addr.s_addr:32位ipv4地址

### htons

把主机字节转换为网络字节,用于初始化网络地址结构体

### socket()函数

在头文件sys/types.h和sys/socket.h里面
原型声明:`int socket(int domain, int type, int protocol);`

#### domain

PF_UNIX/PF_LOCAL/AF_UNIX/AF_LOCAL UNIX 进程通信协议
PF_INET?AF_INET Ipv4 网络协议
PF_INET6/AF_INET6 Ipv6 网络协议

#### type

SOCK_STREAM 提供双向连续且可信赖的数据流, 即TCP. 支持 OOB 机制, 在所有数据传送前必须使用connect()来建立连线状态.
2、SOCK_DGRAM 使用不连续不可信赖的数据包连接
3、SOCK_SEQPACKET 提供连续可信赖的数据包连接
4、SOCK_RAW 提供原始网络协议存取
5、SOCK_RDM 提供可信赖的数据包连接

#### protocol

protocol 用来指定socket 所使用的传输协议编号, 通常此参考不用管它, 设为0 即可.

### bind()

int bind(int sock, struct sockaddr *addr, socklen_t addrlen);  //Linux

`sock` 为 socket `文件描述符，addr` 为 sockaddr `结构体变量的指针，addrlen` 为 addr 变量的大小，可由 sizeof() 计算得出。

### send()

int send(int s, const void * msg, int len, unsigned int falgs);

send()用来将数据由指定的socket 传给对方主机: 参数 `s` 为已建立好连接的socket(客户机socket). 参数 `msg` 指向欲连线的数据内容, 参数 `len` 则为数据长度. `参数flags` 一般设0,

返回值：成功则返回实际传送出去的字符数, 失败返回-1. 错误原因存于errno

#### recv()

int recv(int s, void *buf, int len, unsigned int flags);
函数说明：recv()用来接收远端主机经指定的socket 传来的数据, 并把数据存到由参数buf 指向的内存空间, 参数len 为可接收数据的最大长度.
返回值：成功则返回实际接受的字符数
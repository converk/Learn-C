#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> //网络地址结构体声明
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int server_socket; //服务端socket
    int client_socket; //客户端socket

    struct sockaddr_in my_addr;     //服务器端网络地址结构体
    struct sockaddr_in remote_addr; //客户端端网络地址结构体

    memset(&my_addr, 0, sizeof(my_addr)); //初始化网络字节
    my_addr.sin_family = AF_INET;         //设置为IP通信,在socket.h里面
    my_addr.sin_addr.s_addr = INADDR_ANY; //设定IP地址,允许连接到本地所有ip上
    my_addr.sin_port = htons(8000);       //服务器端口号,监听8000端口

    //socket建立套接字
    if ((server_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }
    //将套接字绑定到服务器的网络地址上
    if ((bind(server_socket, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))) == -1)
    {
        perror("bind");
        return -1;
    }
    //监听数据
    listen(server_socket, 5); //监听队列长度为5

    socklen_t sin_size = sizeof(struct sockaddr_in);

    //等待连接请求
    if ((client_socket = accept(server_socket, (struct sockaddr *)&remote_addr, &sin_size)) < 0)
    {//这里socket会设置一个阻塞进程,直到有客户机链接
        perror("accept");
        return -1;
    }
    printf("client address: %s", inet_ntoa(remote_addr.sin_addr));

    int len = send(client_socket, "welcom to my server", 20, 0); //给客户机发送欢迎信息

    //接收客户机的信息
    char buf[BUFSIZ]; //用来储存接受的信息
    while ((len = recv(client_socket, buf, BUFSIZ, 0)) > 0)
    {                    //返回实际接受的字符串
        buf[len] = '\0'; //字符串终止符
        printf("%s\n", buf);
        if (send(client_socket, buf, len, 0) < 0)
        {
            perror("write");
            return -1;
        }
    }
    close(client_socket); //此选项将不允许sockfd进行写操作。不允许发送
    close(server_socket); //此选项将不允许sockfd进行读操作。不允许接受

    return 0;
}

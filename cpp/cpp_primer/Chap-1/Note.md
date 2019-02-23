# 一些基础

## 输入与输出

C++中没有定义任何输入输出语句,而是包含了一个全面的标准库来提供IO机制,标准库定义了四个IO对象

1. cin: 标准输入,istream类型的对象
2. cout: 标准输出1,ostream类型的对象
3. cerr: 标准错误
4. clog: 程序的一般性信息

```.cpp
#include <iostream>

int main()
{
    std::cout << "enter two numbers" << std::endl;
    int v1 = 0;
    int v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "the sum of" << v1 << "and" << v2 << "is" << v1 + v2 << std::endl;
    return 0;
}
```

### 向流写入数据

<<运算符接受两个运算对象,左侧的运算对象必须是一个ostream对象,右侧的运算对象是要打印的值,这个运算符将给定的值写入到运算对象中,一个标准的输出还可以写为

```.cpp
std::cout << "enter two numbers" << std::endl;
```

等价于

```.cpp  
std::cout << "enter two numbers"  
std::cout << std::endl
```

*. 第一个输出运算符给用户打印一条消息,这个消息是一个字符串字面量常量
*. 第二个运算符打印endl,这是一个操纵符,效果是结束当前该行,并将与设备关联的缓冲区里的内容刷新到设备中,保证目前为止产生的所有输出都真正写入到输出流里

### 循环输入

```.cpp
#include <iostream>

int main()
{
    int val = 0, sum = 0;
    while (std::cin >> val) { //直到遇到文本结束符(ctrl+d)或者输入错误(输入了一个字母)才会退出循环,回车不会退出
        /* code */
        sum += val;
    }
    std::cout << "Sum is:" << sum << std::endl;
    return 0;
}
```

上面的while语句实际判断的是std::cin,当,检测流的状态,如果流是有效的,那么检测成功,如果读入的不是一个有效的输入或者遇到文本结束符的时候,输入流就会变得无效,while判断就结束了
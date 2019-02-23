# 类,对象与字符串的介绍

## 注意的点

1. 当使用流提取运算符(std::cin>>)读取字符串的时候,cin读取字符直到遇到第一个空白间隔符为止(空格,回车,制表等),当我们要输入的字符串里面有空白间隔,那么就最好使用`getline(std::cin,string)`,这个函数连续读取字符(包括空格),直到遇到换行符为止,读取的这些字符将会放入`string`中,并且舍弃换行符,但是请注意,摁下回车键后会在输入流里插入一个换行符. getline()的使用必须要包括`<string>`头文件,命名区间是std
2. 绝大多数类的数据成员的声明出现在成员访问说明符`private`之后,并且在下一个成员访问说明符之前(public或者protected),在private之后声明的函数或者数据成员,只能被声明他们的类的成员函数或者类的**友元**所访问.  
3. 类的成员(数据成员和函数成员)默认的访问说明符是private,因此在类的头部之后,第一个访问说明符之前的所有成员都是私有的
4. string类的默认构造函数将string类的对象初始化为空串
5. 头文件中(.h文件)不可以带有using语句或using声明
6. 单形参的构造函数应该被声明为explicit

## 类的构造函数

构造函数一般用于初始化对象  
声明的每一个类都可以提供一个或者多个构造函数,用于这个类的对象创建时的初始化,构造函数是一种特殊的成员函数,定义时必须和类同名,并且构造函数不可以返回值,不可以指定返回类型(void也不行)  
一般情况下,构造函数声明为public,  
每个类创建对象的时候,都会自动调用构造函数,当一个类里的成员函数没有包含构造函数的时候,编译器会提供一个默认的构造函数  
在编译器提供的默认构造函数创建对象时,不会给对象的 **具有基本数据结构(整形,浮点等)** 的数据成员任何初始值,对于是其他类的对象的数据成员,这个默认构造函数会自动调用的他们的默认构造函数(其他几个的),来达到数据成员的正确初始化  
构造函数不能声明为`const`,因为修改了对象

### 为类提供默认构造函数的方法

任何不接受实参的构造函数称为默认的构造函数,类通过下面的方法之一获取默认的构造函数

1. 编译器隐式的在没有任何用户自定义的构造函数的类中创建一个默认的构造函数
2. 程序员显式的定义一个不接受实参的构造函数,这个构造函数将调用其他类对象的数据成员的默认构造函数
3. 如果程序员定义了一个具有实参的构造函数,C++将不再为这个类隐式的创建一个构造函数

## 类的复用

一般为了让其他的程序也可以使用类,可以把类单独放在一个文件中,但是这样的话,就会向用户暴露类的实现,因此可以将类的实现,与类提供的接口(类里面的函数)分开来,这样用户可以看到一个类都有什么接口,但是看不到是如何实现的,要注意在.h文件中,声明成员函数的方式

Gradebook.h文件(定义函数原型)  
函数原型用来告诉编译器函数的名字,形参类型,返回值类型,函数原型同样也定义private类型的数据成员,编译器必须知道类的数据成员,以决定为类的每个对象分配多少内存

```.h
#include <string>

class Gradebook {
private:
    std::string coursename;
    /* data */
public:
    explicit Gradebook(std::string);
    void set_coursename(std::string);
    std::string get_coursename() const;
    void displayMessage() const;
};
```

Gradebook.cpp

```.cpp
#include "Gradebook.h"
#include <iostream>
#include <string>

using namespace std;

Gradebook::Gradebook(string name)
    : coursename(name)
{
}

void Gradebook::set_coursename(string name)
{
    coursename = name;
}

string Gradebook::get_coursename() const
{
    return coursename;
}

void Gradebook::displayMessage() const
{
    cout << "welcome to the grade for " << get_coursename() << endl;
}
```

编译链接过程

```.sh
Ξ cpp-University-tutorials/Chap-3 git:(master) ▶ g++ -c test.cpp   //编译两个文件
Ξ cpp-University-tutorials/Chap-3 git:(master) ▶ g++ -c Gradebook.cpp  
Ξ cpp-University-tutorials/Chap-3 git:(master) ▶ g++ -o test.out test.o Gradebook.o  //连接两个文件
Ξ cpp-University-tutorials/Chap-3 git:(master) ▶ ./te
zsh: 没有那个文件或目录: ./te
↑127 cpp-University-tutorials/Chap-3 git:(master) ▶ ./test.out
```
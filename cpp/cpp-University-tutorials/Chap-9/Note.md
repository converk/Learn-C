# 关于类的一些东西

## 一些记不住的

1. 当将一个类的对象赋值给另外一个对象的时候,默认逐个成员赋值
2. 将修改对象的数据成员的成员函数定义为 const 将导致编译错误
3. 定 义 为 const 的 成 员 函 数 如 果 又 调 用 同 一 类 的 同 一 实 例 的 非 const 成 员 函 数 , 将 导 致 编 译 错 误 。
4. 在 const 对象上调用非 const 成员函数将导致编译错误

## 构造函数

1. 构造函数的默认参数在函数声明里说明,而不是在函数的定义里
2. 在调用时不需要提供实参的构造函数是默认构造函数,**一个类只能有一个默认构造函数**,不需要提供实参可能是构造函数所有的参数都是默认的,或者都是定义的常数

### 重载构造函数与委托构造函数

重载的构造函数允许用不同类型和(或)数量的实参初始化对象

```.cpp
Time(); // default hour, minute and second to 0
Time( int ); // initialize hour; default minute and second to 0
Time() int, int ); // initialize hour and minute; default second to 0
Time( int, int, int ); // initialize hour, minute and second
```

正如构造函数可以调用类的其他成员函数来实现功能那样, C++11现在也允许构造函数调用同一个类中的其他构造函数。这样的构造函数称为委托构造函数,它将自己的工作委托其他构造函数

```.cpp
Time: :Time ()
    :Time( 0 , 0 , 0 ) / / delegate to TimeC int, int, int )
{
} // end constructor with no arguments
Time::TimeC int hour )
    :Time( hour, 0, 0 ) // delegate to TimeC int, int, int )
{
} // end constructor with one argument
Ti me::Ti me( int hour, int minute )
    :Time( hour, minute, 0 ) // delegate to TimeC int, int, int )
{
} //end constructor with two arguments
```

### 析构函数

析构函数不接收任何参数,也不返回任何值,当对象撤销时,类的析构函数会隐式地调用。例如,**当程序的执行开实例化自动对象所在的作用域时**,自动对象就会撤销,这时会发生析构函数的隐式调用。实际上,析构函数本身并不释放对象占用的内存空间,它只是在系统收回对象的内存空间之前执行扫尾工作,这样内存可以重新用于存新的对象。

## this指针

每个对象都可以使用一个称为 this (—个 C ++保留字)的指针来访问自己的地址。this 指针作为一个隐式的参数(被编译器)传递给对象的每个非 static 成员函数。(不会传递给static函数)

## static类成员

1. 类的 private 和 protected 的 static 成员(包括数据成员和函数成员)通常通过类的 public 成员函数或者类的友元访问。即在没有任何类的对象存在时,类的 static 成员仍然存在。当没有类的对象存在时,要访问类publicstatic成员,只需简单地在此数据成员名前加类名和二元作用域分辨运算符( n )即可。
2. 不可以在static函数成员里面使用this指针
3. 静态成员函数不能声明为const的
4. 一般来说我们不可以在类的内部初始化一个静态数据成员,但是可以在类内定义一个静态函数成员
5. 静态数据成员不是由构造函数初始化的,也不可以使用构造函数来初始化

```.cpp
int Solution::static_num = 1;//注意,这里在类外面初始化静态成员的时候必须加上类型名
```
# 基本数据类型与相关运算的陷阱

这个是很早之前就一直搞不明白的点,现在一起拿起来说一下

## 基本内置数据类型

### 算术类型

| 类型   | 含义   | 最小尺寸  |
| ----- |:------:| ---:|
| bool | 布尔型 | 未定义 |
| char | 字符型 |1个字节 |
| short | 短整型 | 2个字节 |
| int | 整形 | 2个字节 |
| long int | 长整形 | 4个字节 |
| long long int | 长整形 | 4个字节 |
| float | 单精度浮点 | 4个字节(6位有效数字) |
| double | 双精度浮点 | 8个字节(10位有效数字) |
| long double | 扩展双精度浮点 | 12或16个字节 |

C++规定一个int至少和short一样大,一个long至少和一个int一样大,一个long long至少和一个long一样大

#### 带符号类型和无符号类型

除去布尔型,其他的类型可以分为**带符号的(signed)和不带符号的(unsigned)**两种

1. 类型 int ,short,long,long long默认都是带符号的,前面加unsigned可以变成无符号的,比如:unsigned long和unsigned int ,后者还可以简写为unsigned  
2. 字符串被分了三种类型 char, unsigned char和signed char,如果代码中只写char,没有说明是有符号的还是无符号的,那么具体是那种会根据编译器来决定  

signed char可以表示-127到127之间,unsigned char可以表示为0到255之间

#### 如何选择类型

1. 当明确直到不可能为负时,选择unsigned
2. 使用int进行整形运算,short太小,long一般和int一样大
3. 执行浮点运算的时候使用double,double的精度更大,但是代价和float相差无几

### 类型转换

下面几个例子展示了当把一个类型的值强制赋给另外一个类型的变量的时候会发生什么

```.cpp
bool b=42; //b为真
int i=b;  //i为1
i=3.14  //i为3
double pi=i;  //pi为3.0
unsigned char c=-1  //c为255
signed char c1=256  //c1为未定义的
```

#### 含有无符号类型的表达式

当一个算术表达式里面既有无符号数,又有有符号数,那么会把有符号数转化为无符号数,这就会很容易导致出错

```.cpp
#include <iostream>

int main()
{
    unsigned int i = 10;
    int u = -24;
    std::cout << u + u << std::endl; //-48
    std::cout << u + i << std::endl; //4294967282
    std::cout << i - 11 << std::endl; //4294967285,C++保证对unsigned数进行任何操作结果都不会是负的
    return 0;
}
```

### 字面值常量

1. 整形字面值

    后缀 | 最小匹配类型
    ---------|----------
    u或U | unsigned
    l或L | long
    ll或LL | long long

2. 浮点型字面值

    后缀 | 最小匹配类型
    ---------|----------
    f或F | float
    l或L | long double

3. 字符和字符串字面量

    前缀 | 最小匹配类型
    ---------|----------
    u8 | char
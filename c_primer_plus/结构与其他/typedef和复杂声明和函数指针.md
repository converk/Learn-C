# typedef,复杂声明,函数和指针

## typedef

利用 typedef 可以为某一类型自定义名称,这方面与#define 类似,但有几处不同:

- 与#define 不同,typedef 创建的符号命名只受限于类型,不能用于定义值
- typedef 由编译器解释,不是预处理
- 比#define 灵活

### typedef的一般使用

typedef 使用例子:

```.c
typedef unsigned char BYTE
```

随后可以使用 BYTE 来定义`unsigned char`类型的变量:

```.c
BYTE x,y[10],*z;
```

typedef 的一些功能与`#define`重合:

```.c
#define BYTE unsign char
```

这使得预处理器用`BYTE`替换 `unsign char`.  
**注意以下两种方式的区别**

```.c
typedef char * STRING;
STRING name,sign;
```

相当于:

```.c
char *name,*sign;
```

`name`和`sign`都是`char`类型的指针  
而对于:

```.c
#define STRING char *
STRING name,sign
```

相当于:

```.c
char * name,sign;
```

只有`name`才是指针, `sign`只是一个char类型的变量

### typedef用于结构

```.c
typedef struct complex{
    float real;
    float imag;
} COMPLEX
```

然后就可以使用COMPLEX来代替complex来表示复数  
使用typedef来定义结构的时候,可以忽略该结构的标签,例如:

```.c
tyoedef struct {double x;double y;} rect;
rect r1={3.0,6.0};
rect r2;
```

上面的代码被翻译成

```.c
struct {double x;double y;} r1={3.0,6.0};
struct {double x;double y;} r2;
```

可以看做声明了两个结构变量,r1和r2的成员完全相同,所以`r2=r1`是有效的操作.

使用typedef的两个好处

- 为经常出现的类型创建一个方便的类型名
- 下面写复杂声明的时候再讨论  

## 其他复杂声明

### 一般的复杂声明

在C语言里面,一些复杂声明会用到下面的符号,如下表所示:

符号|含义
---|:--:
*|表示一个指针|
[]|表示一个数组|
()|表示一个函数|

下面是一些复杂函数声明的实例:

```.c
int board[8][8]  //声明一个8*8的二维数组
int ** ptr      // 声明一个指向指针的指针
int * risks[10] // 声明一个有10个元素的数组,每个元素都是一个int型的指针
int (* risks)[10]  //声明一个指针,指向一个含有10个int型元素的数组
int * oof[3][4]  //声明一个3*4的数组,每个元素都是指向int的指针
int (* oof)[3][4]  //声明一个指针,指向一个3*4的int型数组
int (* oof[3])[4]  //声明一个有三个元素的数组,每个元素都是一个指针,每个元素都指向,一个长度为4的int型数组
```

在看上面的几项复杂生命的时候要注意以下几条规则

> 1. 数组名后面的[]和函数名后面的()有相同的优先级,他们的优先级都比*高
> 2. ()和[]都是从左往右结合

根据上面的规则,还可以声明下面更复杂的:

```.c
char * function(int);  //声明一个返回类型为char *的函数
char (* function)(int);  //声明一个指向函数的指针,函数的返回类型为char
char (* function[3])(int)  //声明一个有三个元素的数组,每个元素指向一个返回类型为char的函数
```

### 与typedef结合的声明

```.c
typedef int arr5[5]
typedef arr5 * ptr
typedef ptr arr10[10]

arr5 togs  //togs是里面含有5个int型值的数组
ptr p1     // p1是一个指向数组的指针,该数组里面有5个int型元素
arr10 ap   //ap是一个含有10个元素的数组,每个元素都是指向一个含有5个元素的int型数组
```

由于与typedef结合的声明有点复杂,应用的话,这里不再讨论
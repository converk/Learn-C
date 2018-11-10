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
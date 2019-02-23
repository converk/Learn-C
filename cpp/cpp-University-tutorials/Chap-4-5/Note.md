# 注意

## 基本数据类型之间的显式与隐式类型转换

```.cpp
int total=10;
int count=3;
double avenge=total/count
```

首先进行整数除法运算,所以在将计算结果赋给 average 之前,计算结果中的小数部分已经丢失了。为了
使整数值进行浮点数计算,必须生成用于计算的临时浮点数值。 C++提供了 `static_cast` 运算符完成强制类型转换这一任务。使用强制类型转换运算符 `static_ cast < double >( total )`生成一个临时的浮点数值,它是括号中操作数 total 的浮点数副本。像这样利用强制类型转换运算符进行的转换称为**显式转换(explicit conversion )** 。 **存储在 total 中的值仍是一个整数**。  
为了保证操作数是类型相同的,编译器对所选的操作数进行了一种称为升级, 也称为**隐式转换 (implicit conversion )** 的操作

## C++11的列表初始化

列表初始化使程序员能够用一种语法来初始化任意类型的一个变量  
unsigned int studentCounter = 1;
在 C ++11中,可以书写为  
unsigned int studentCounter ={ 1 };  
或者  
unsigned int studentCounter{ 1 };  
的形式。花括号对表示**列表初始化器**。对于一个基本数据类型的变量,只放置一个值在列表初始
化器中.  
对于一个对象,**列表初始化器中可以是逗号分隔的值的列表,这些值传递给对象的构造函数**。

## 流程操作符格式化数值输出

```.cpp
double amount;
double rate = 0.05;
double principal = 1000.0;

cout << "year" << setw(21) << "Amount" << endl; //setw()用来规范下一次输出
cout << setprecision(2) << fixed;

for (unsigned int year = 1; year <= 10; year++) {
    amount = principal * pow(1.0 + rate, year);

    cout << setw(4) << year << setw(21) << amount << endl;
}
```

year 和 amount 的值。打印的格式由参数化的流操纵符 `setprecision` 、 `setw` 和无参数的流操纵符 `fixed` 指定  
流操纵符 `setw (4)`规定了下一个输出值应占用的域宽是4。也就是说, emit 打印一个值,它至少占用4个
字符位置。如果输出的值小于4个字符位置的宽度,那么在默认情况下,该值的输出在域宽范围内向右
对齐;如果输出的值大于4个字符位置的宽度,那么域宽将向右侧扩展到整个值的实际宽度  
for 循环之前的输出流中应用了流操纵符
fixed 和 setprecision ,因为这些格式的设置如果不被更改则会一直起作用。  
可是,指定域宽的 setw 只对接下来要输出的值有用
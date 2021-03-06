# 顺序容器

包括vector,list,forward_list,deque,array,string

## 赋值和swap

在这里要注意赋值和初始化的操作之间的关系与不同

### 对于array的特例

标准库array类型允许赋值。赋值号左右两边的运算对象必须具有相同的类型:

```.cpp
array<int, 10> al = {0,1,2,3,4,5,6,7,8,9};
array<int, 10> a2 = { 0 } ; //所有元素值均为0
al = a2;// 替 换 al 中 的 元 素
a2 = {0} ; // 错误 : 不能将一个花括号列表賦予数组
```

array类型可以使用列表初始化,但是初始化之后就不可以使用列表进行赋值了,但还是可以使用相同类型的数组a2来对a1进行赋值(这个操作对于内置数组来说也是不可实现的)  
由于右边运算对象的大小可能与左边运算对象的大小不同,因此`array`类型不支持`assign`,也不允许用花括号包围的值列表进行赋值。

### 赋值运算

对于除了array之外的其他顺序容器,下面的赋值运算都是可以的

```.cpp
c1=c2
c={a,b,c,...}
swap(c1,c2)   //这个也适用于array
c1.swap(c2);  //这个也适用于array

c.assign(b,e);  //将c中的元素替换为迭代器b和e所表示的范围中的元素。迭代器b和e不能指向seq中的元素
c.assign(li);   //将c中的元素替换为初始化列表il中的元素
c.assign(n,t);   //将c中的元素替换为n个值为t的元素
```

### assign运算

可以类比各个容器在初始化的时候的几种操作,assign就是将初始化时的几种操作变成了赋值时的几种操作

### swap

除 array 外, swap 不对任何元素进行拷贝、删除或插入操作,因此可以保证在常数时间内完成  
事实上,对两个容器进行swap操作的时候,容器里面的元素不会进行任何的改变,指向容器的迭代器、引用和指针在swap 操作之后都不会失效。它们仍指向 swap 操作之前所指向的那些元素。但是,在 swap之后,这些元素已经属于不同的容器了。例如,假定 iter 在 swap 之前指向 svec1[3]的 string , 那么在 swap 之后它指向 svec2[3] 的元素。  
与其他容器不同, swap 两个 array 会真正交换它们的元素。因此,交换两个 array所需的时间与 array 中元素的数目成正比。

## 对容器的操作

### 添加元素

首先先说明,如果向一个 `vector` 、 `string` 或 `deque` 插入元素会使所有指向容器的迭代器、引用和指针失效。  
各种添加元素的操作(这些操作更改容器大小,array不支持)  

#### 注意

1. forward_list不支持不支持 push_back 和 emplace_back,有自己专有版本的 insert 和emplace;
2. vector 和 string 不 支 持 push—front 和 emplace_front
3. deque 保证在容器首尾进行插入和删除元素的操作都只花费常数时间。与 vector —样,在 deque 首尾之外的位置插入元素会很耗时
4. a.insert()的返回值是一个迭代器,指向插入的第一个新元素
5. 当我们使用push或者insert插入一个对象的时候,实际上插入的是这个对象的一份拷贝

### 访问元素

1. front和back返回的是引用
2. 对于一个空容器,使用frond和back是一个未定义的行为,会引发错误
3. forward_list容器类型无法使用back()函数,所有的顺序容器均可以使用front函数
4. string ,vector ,deque 和 array )也都提供下标运算符

### 删除元素

1. forward_list 不支持 pop_back;
2. vector 和 string不支持 pop_front
3. 删除 deque 中除首尾位置之外的任何元素都会使所有迭代器、引用和指针失效。指向 vector 或string 中删除点之后位置的迭代器、引用和指针都会失效
4. 成员函数erase 从容器中指定位置删除元素。我们可以删除由一个迭代器指定的单个元素,也可以删除由一对迭代器指定的范围内的所有元素。**两种形式的 erase 都返回指向删除的(最后一个)元素之后位置的迭代器**,若 p 指向尾元素 , 则返回尾后( off-the-end) 迭 代 器 。 若 P 是 尾 后迭代器,则函数行为未定义

### forward_list的特殊情况

由于forward_list不可以访问前面的元素,而,上面所说的插入基本都在当前迭代器之前插入,而删除都是删除当前迭代器,对于forward_list来说这没有办法办到,所以它有自己专门的插入与删除函数,插入都是在相应的迭代器之后操作,删除相应迭代器之后的元素  

1. 插入函数返回指向最后一个插入元素的迭代器。如果范围为空,则返回P.若p为尾后迭代器, 则 函 数行为未定义
2. 删除函数返回返 回 一个指向被删元素之后元素的迭代)器,若不存在这样的元素则返回尾后迭代器。如果p指向1st的尾元素或者是一个尾后迭代器, 则函数行为未定义

## vector增长

管理容量

```.cpp
    vector<int> a = { 1, 2, 3, 4, 5 };
    cout << a.capacity() << endl; //5
    cout << a.size() << endl; //5

    for (int i = 0; i < 24; i++)
        a.push_back(i);
    cout << a.capacity() << endl; //40
    //新加24个元素,但是capacity不一定是24,具体要看标准库的实现,
    //因为vector不是新增一个元素,就分配一个空间,可能一次分配许多空间
    cout << a.size() << endl; //29

    a.reserve(50); //这个不会改变size的大小,只会改变capacity
    //分配50个可以放元素的空间,这个50是算上之前vector里面已经存在的元素的,不是再分配50个
    //而是分配完之后,一共有50个存放的空间
    cout << a.capacity() << endl; //50
    cout << a.size() << endl; //29
```
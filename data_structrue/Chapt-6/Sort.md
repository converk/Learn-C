# 排序

## 概念

不能够在主存中进行排序,而必须要在磁盘上进行的排序叫做--**外部排序**,这里主要讨论在主存上进行的排序--**内部排序**

## 几种排序算法

### 插入排序

这个方法从数组的开始遍历到结尾,从0,到N.算法保证,当遍历到一个元素的时候,其前面的几个元素都是已经排好序的,只需要把当前元素插入到前面排好序的序列中就行了,当数组遍历完成,那么排序也完成了  
时间复杂度: O(N^2)

```.c

void InsertSort(int A[], int N)
{
    int temp;
    int j;
    for (int i = 0; i < N; i++) {
        temp = A[i];
        for (j = i; j > 0 && A[j - 1] > temp; j--) {
            A[j] = A[j - 1];
        }
        A[j] = temp;
    }
}
```

### 希尔排序(缩小增量排序)

希尔排序使用了一个增量序列`[h1,h2,h3,...,ht]`,`ht`是增量序列的最大值,当然增量序列不是固定的,只要`h1=1`,那么就可以成为一个增量序列,而且增量序列的选择对于算法的性能有很大影响,  
写一种流行的增量序列是:  ht=N/2,h(k+1)=h(k)/2,h(k)是第k个增量  
具体做法就是: 我们在使用了h(k)增量进行了一个排序之后(称为h(k)-排序),对于每一个i,都有`A[i]<=A[i+h(k)]`,当h(k)从大到小遍历完成,数组的排序完成  
希尔排序有一个性质就是: h(k)的排序性不会受到之后排序的影响,即如果一次h(k)排序之后,那么`A[i]<=A[i+h(k)]`,就一直成立,不会受到h(k-1)排序的影响  
如果使用上面的增量序列的话,最坏时间为: O(N^2)

```.c
void ShellSort(int A[], int N)
{
    int IncreaseMent, i, j;
    int temp;

    for (IncreaseMent = N / 2; IncreaseMent > 0; IncreaseMent /= 2) {
        for (i = IncreaseMent; i < N; i++) { //对每隔InCreaseMent个进行插入排序
            temp = A[i];
            for (j = i; j >= IncreaseMent; j -= IncreaseMent) { //这里的思想其实和堆差不多
                if (temp < A[j - IncreaseMent])
                    A[j] = A[j - IncreaseMent];
                else
                    break;
            }
            A[j] = temp;
        }
    }
}
```

可以通过改变增量序列来提高算法的性能,比如:Hibbard,希尔排序由于很简单,现在很多大型的数据输入也会使用

### 堆排序

首先将输入的数组构建为一个堆,然后再逐次删除最小值或者最大值(看是最小堆还是最大堆),当把堆删除完成之后,排序就完成了,为了避免使用一个新的数组,可以将删除的数据存储在堆的后面,当删除一个元素时,可以将这个值与堆的最后一个值进行交换,然后再下滤,再删除最大值,但是这里与堆有个不同的地方,这里的数组是从下标0开始的,所以左儿子就变为了2*i+1  

```.c
void PcrDown(int A[], int i, int N) //i是下滤第几个元素,N是堆一共几个元素
{
    int temp, child;
    for (temp = A[i]; LeftChild(i) < N; i = child) {
        child = LeftChild(i);
        if (child != N - 1 && A[child] < A[child + 1])
            child++;
        if (temp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = temp;
}

void HeapSort(int A[], int N)
{
    int temp;
    for (int i = N / 2; i >= 0; i--)
        PcrDown(A, i, N); //创建堆
    for (int i = N - 1; i > 0; i--) {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        PcrDown(A, 0, i);
    }
}
```

堆排序是一种很稳定的算法,复杂度为O(NlogN),即平均情景与最坏情景差不多

### 归并排序

归并排序就是将一个待排序的数组,分成几部分,分别排序后,再合并到一起,比如一个数组有八个元素,我们可以先排序前四个和后四个,再合起来,如果我们要排序前四个,那么我们可以先排序前四个的前两个和后两个,之后合并起来,这也是典型的分治算法,也是递归的一种使用,但是这种算法有一个缺点,就是每一次排序之后都把从之前分配的一个空间里面的数,拷贝到原数组,这个操作会严重放慢排序的速度,所以在主存中进行排序的时候不会使用这种算法,但是大多数外部排序都会有使用归并的思想

```.c
void MergeSort(int A[], int N)
{
    int* TmpArray = malloc(N * sizeof(int));
    if (!TmpArray) {
        Msort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    }
}

void Msort(int A[], int TmpArray[], int left, int rigth)
{
    int cerent;

    if (left < rigth) {
        cerent = (left + rigth) / 2;
        Msort(A, TmpArray, left, cerent);
        Msort(A, TmpArray, cerent + 1, rigth);
        Merge(A, TmpArray, left, cerent + 1, rigth);
    }
}

void Merge(int A[], int TmpArray[], int left, int cerent, int rigth)
{
    int A_left = left;
    int A_rigth = cerent;
    int B_left = cerent + 1;
    int B_rigth = rigth;
    int C_begin = left;
    int C_end = rigth;

    int C_index = left; //c中的当前索引
    while (A_left <= A_rigth && B_left <= B_rigth) {
        if (A[A_left] > A[B_left])
            TmpArray[C_index++] = A[B_left++];
        else
            TmpArray[C_index++] = A[A_left++];
    }

    while (A_left <= A_rigth) //清除剩余的
        TmpArray[C_index++] = A[A_left++];

    while (B_left <= B_rigth)
        TmpArray[C_index++] = A[B_left++];

    for (int i = left; i <= rigth; i++) //将tmp中的元素在拷贝到A中,这个过程会减慢算法速度
        A[i] = TmpArray[i];
}
```

这种算法的复杂度为O(NlogN),

### 快速排序

这个是在实践中已知的最快的排序算法,平均运行时间为O(NlogN),之所以很快,是因为内部高度优化的结构,算法的具体流程如下:

1. 如果数组中只有0或1个元素,那么直接返回
2. 在数组中选择任意元素v作为 _枢纽元_
3. 将数组的其余元素分为小于枢纽元和大于枢纽元的两部分,S1和S2
4. 分别再对S1和S2进行快排,然后与枢纽元的合并

如上述描述可以看到,快速排序也是一种递归的算法,它的高效主要体现在将数组分为两部分的步骤上,确切的说也就是**枢纽元**的选择,一个好的枢纽元可以大大提高算法的速度

#### 枢纽元的选择

##### 随机

随机挑选数组里面的一个元素作为枢纽元是可以接受的,因为他不可能连续多次都导致坏的情况,但是一个随机数的生成可能要消耗带昂的时间

##### 三数中值

一般取一个数组的中值是最好的分割方法,因为这个时候两边都是相同个数的元素,但是计算中值的时间是十分巨大的,因此采用一个简单的方法,如果一个数组左边第一个索引为left,右边最后一个索引为rigth,中值索引为(left+rigth)/2,选择三个索引中值为中间的为索引

#### 分割策略

在我们选出了枢纽元之后,下一步要做的就是根据枢纽元将数组分成两个部分,做法就是,先将枢纽元与最后一个元素进行交换,然后同时将两个索引i和j分别放到数组的开头与倒数第二个元素(忽略枢纽元),然后通过两个索引进行分割

1. 如果a[i] < v,a[j]>v,则i++,j++
2. 如果a[i]> v,a[j]< v 则i与j都停止,二者交换元素,然后i++,j++
3. 如果a[i],a[j]< v,i++,j不变
4. 如果a[i],a[j]> v,j++,i不变

当两个索引交错的时候,把i出索引的值与最后一个元素枢纽元进行交换,就完成了分割

#### 数组中与枢纽元相等的元素的处理

我们采用的办法是i与j都停止,然后交换元素,这样虽然会有多次不必要的交换,但是避免了二次运行时间

#### 使用情况

快排虽然有效,但是不适合用于小数组,因为递归的使用很浪费时间,对于小数组(N<15),使用插入排序这种更好

#### 实现

在实现中,我们通常将left,rigth,mid三个值进行排序,最小值放在left,因为它小于枢纽元,最大值放在rigth,枢纽元放在mid,然后交换的时候就可以直接将枢纽元与**rigth-1**进行交换,i与j的开始索引就变成了**left+1**和**rigth-2**,之后再进行上述的分割操作,然后递归调用此函数,直到不可以再分割为止

```.c
void QuickSort(int A[], int N)
{
    QSort(A, 0, N - 1);
}

int Median3(int A[], int left, int rigth)
{
    int mid = (left + rigth) / 2;
    if (A[left] > A[mid])
        swap(A + left, A + mid);
    if (A[left] > A[rigth])
        swap(A + left, A + rigth);
    if (A[mid] > A[rigth])
        swap(A + mid, A + rigth);

    swap(&A[mid], &A[rigth - 1]); //将枢纽元交换到后面
    return A[rigth - 1];
}

void QSort(int A[], int left, int rigth)
{
    int temp;
    int i = left + 1, j = rigth - 2;

    if (rigth - left >= Cutoff) { //快速排序
        temp = Median3(A, left, rigth); //返回索引

        for (;;) {
            while (A[i++] < temp) {
            }
            while (A[j--] > temp) {
            }
            if (i < j)
                swap(&A[i], &A[j]);
            else
                break;
        }
        swap(&A[rigth - 1], &A[i]); //把枢纽元交换回来

        QSort(A, left, i - 1);
        QSort(A, i + 1, rigth);
    } else
        InsertSort(A, rigth - left + 1); //使用插入排序
}
```

正常情况的复杂度是O(NlogN),但是最坏情况可以达到O(N^2),

#### 使用快排的方法解决第k个最小值问题

这个算法称为快速选择,当做算法结束的时候,第k个最小元就在位置k上,思想与快速排序几乎一样

```.c
void QSelect(int A[],int k, int left, int rigth)
{
    int temp;
    int i = left + 1, j = rigth - 2;

    if (rigth - left >= Cutoff) { //快速排序
        temp = Median3(A, left, rigth); //返回索引

        for (;;) {
            while (A[i++] < temp) {
            }
            while (A[j--] > temp) {
            }
            if (i < j)
                swap(&A[i], &A[j]);
            else
                break;
        }
        swap(&A[rigth - 1], &A[i]); //把枢纽元交换回来

        if(k<=i)
            QSelect(A,k,left,i-1);
        else
            QSelect(A,k-i-1,i+1,rigth);
    } else
        InsertSort(A, rigth - left + 1); //使用插入排序
}
```
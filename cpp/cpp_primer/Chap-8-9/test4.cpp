#include <array>
#include <forward_list>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
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
}
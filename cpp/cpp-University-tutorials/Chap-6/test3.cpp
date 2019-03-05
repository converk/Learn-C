#include <iostream>

using namespace std;

int number = 7;

int main()
{
    double number = 8.8;
    static int first = 9;
    int second = 5;
    cout << "local_number: " << number << endl;
    cout << "golab_number: " << ::number << endl;
    {
        double first = 9.9;
        float number = 1.1;
        cout << "local: " << first << endl;
        cout << "local: " << second << endl; //直接打印上一个作用域的变量,因为这个作用域没有这个变量
        //cout << "gloab: " << ::first << endl; //这么写会报错,不可以用来识别局部变量
        cout << "local_number: " << number << endl; //输出当前作用域的的number值(1.1)
        cout << "golab_number: " << ::number << endl; //输出全局的number值(7)
    }
    return 0;
}
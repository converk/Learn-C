#include <iostream>

using namespace std;

void squear_by_value(int);
void suqear_by_refer(int&);
void squear_by_point(int*);
int returnrefer();

int main()
{
    int x = 2;
    int y = 2;
    int z = 2;
    squear_by_point(&z);
    squear_by_value(x);
    suqear_by_refer(y);
    cout << "x: " << x << "y: " << y << "z: " << z << endl;

    //变量作为别名进行引用
    int m = 1;
    int& n = m;
    n++;
    cout << m << endl;
    int p = 5;

    //返回引用
    cout << returnrefer() << endl;
}

void squear_by_value(int a)
{
    a *= a;
}

void suqear_by_refer(int& a)
{
    a *= a;
}

void squear_by_point(int* a)
{
    *a *= *a;
}

int returnrefer()
{
    int m = 5;
    int& n = m;
    n++;
    return n;
}
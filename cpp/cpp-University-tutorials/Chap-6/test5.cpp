#include <iostream>

using namespace std;

template <typename T> //创建模板
T maxium(T a, T b, T c)
{
    T max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    cout << maxium(a, b, c) << endl;

    double x = 1.2;
    double y = 1.3;
    double z = 1.4;

    cout << maxium(static_cast<double>(a), y, z) << endl;
    return 0;
}
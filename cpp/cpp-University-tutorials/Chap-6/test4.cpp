#include <iostream>
using namespace std;

void square(int x)
{
    cout << "the square of int " << x * x << endl;
}

void square(double x)
{
    cout << "the square of double " << x * x << endl;
}

int main()
{
    square(4);
    square(2.5);
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void chage(int* a)
{
    a[1] = 1;
}

int main()
{
    int a[5] = { 0 };
    chage(a);
    cout << a[1] << endl;
}
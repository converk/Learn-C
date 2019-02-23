#include <cmath> //提供数学计算相关的库
#include <iomanip> //进行格式化输出
#include <iostream>
using namespace std;

int main()
{
    double amount;
    double rate = 0.05;
    double principal = 1000.0;
    cout << EOF << endl; //查看文本结束符的值

    cout << "year" << setw(21) << "Amount" << endl; //setw()用来规范下一次输出
    cout << setprecision(2) << fixed;

    for (unsigned int year = 1; year <= 10; year++) {
        amount = principal * pow(1.0 + rate, year);

        cout << setw(4) << year << setw(21) << amount << endl;
    }
}
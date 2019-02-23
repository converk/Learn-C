#include <iostream>

int main()
{
    int val = 0, sum = 0;
    while (std::cin >> val) { //直到遇到文本结束符(ctrl+d)或者输入错误(输入了一个字母)才会退出循环,回车不会退出
        /* code */
        sum += val;
    }
    std::cout << "Sum is:" << sum << std::endl;
    return 0;
}
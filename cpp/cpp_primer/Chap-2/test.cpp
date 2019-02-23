#include <iostream>

int main()
{
    unsigned int i = 10;
    int u = -24;
    std::cout << u + u << std::endl; //-48
    std::cout << u + i << std::endl; //4294967282
    std::cout << i - 11 << std::endl; //4294967285,C++保证对unsigned数进行任何操作结果都不会是负的
    std::cout << "\n"
              << std::endl;
    return 0;
}
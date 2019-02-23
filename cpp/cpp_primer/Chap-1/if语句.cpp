#include <iostream>

int main()
{
    int currentVal, val;
    if (std::cin >> currentVal) {
        int count = 1;
        while (std::cin >> val) {
            if (currentVal == val)
                count++;
            else {
                std::cout << currentVal << "occurs" << count << "times" << std::endl;
                currentVal = val;
                count = 1;
            }
        }
        std::cout << currentVal << "occurs" << count << "times" << std::endl;
    }
    return 0;
}
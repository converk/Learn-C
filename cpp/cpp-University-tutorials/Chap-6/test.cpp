#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

unsigned int roll(); //函数原型声明

int main()
{
    enum status { Continue,
        Lose = 5,
        Win }; //创建枚举类型
    cout << Continue << Lose << Win << endl;
    status gamestatus = Continue; //游戏的状态

    unsigned int point = 0; //当前点数
    unsigned int twosum; //两个点数的和

    srand(static_cast<int>(time(0))); //设立随机种子
    twosum = roll();

    switch (twosum) {
    case 7:
    case 11:
        gamestatus = Win;
        /* code */
        break;
    case 2:
    case 3:
    case 12:
        gamestatus = Lose;
        break;
    default:
        point = twosum;
        gamestatus = Continue;
        cout << "the point is: " << point << endl;
        break;
    }

    while (gamestatus == Continue) {
        twosum = roll();

        if (twosum == point)
            continue;
        else if (7 == twosum)
            gamestatus = Lose;
    }

    if (Win == gamestatus)
        cout << "player wins!!" << endl;
    if (Lose == gamestatus)
        cout << "player Lose" << endl;
}

unsigned int roll()
{
    unsigned first_number;
    unsigned second_number;

    first_number = 1 + rand() % 6;
    second_number = 1 + rand() % 6;
    cout << "the sum of" << first_number << "and" << second_number << "is" << first_number + second_number << endl;
    return first_number + second_number;
}
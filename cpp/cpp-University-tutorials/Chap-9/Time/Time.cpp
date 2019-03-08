#include "Time.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept> //报错的类型

using namespace std;

Time::Time()
    : hour(0)
    , min(0)
    , sec(0)
{
}

void Time::setTime(int h, int m, int s)
{
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        min = m;
        sec = s;
    } else
        throw invalid_argument("out of range"); //向上抛出错误
}

void Time::prtUniversal() const
{
    cout << setfill('0') << setw(2) << hour << ':' << setw(2) << min << ':' << setw(2) << sec;
}

void Time::prtStandart() const
{
    cout << setfill('0') << setw(2) << (hour < 12 ? hour : hour % 12) << ':'
         << setw(2) << min << ':' << setw(2) << sec << (hour < 12 ? "AM" : "PM");
}
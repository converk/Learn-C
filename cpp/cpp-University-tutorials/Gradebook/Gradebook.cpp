#include "Gradebook.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Gradebook::Gradebook(string name)
    : coursename(name)
{
}

void Gradebook::set_coursename(string name)
{
    if (name.size() <= 25)
        coursename = name;
    else {
        coursename = name.substr(0, 25); //截断字符串,包括第一个字符但不包括第25个字符
    }
}

string Gradebook::get_coursename() const
{
    return coursename;
}

void Gradebook::displayMessage() const
{
    cout << "welcome to the grade for " << get_coursename() << endl;
}

void Gradebook::deterclassaverage() const
{
    int total = 0;
    unsigned int count = 0;

    cout << "enter a grade or -1 to quit"; //设定一个标记值来停止录入成绩
    int grade;
    cin >> grade;

    while (grade != -1) {
        total += grade;
        count += 1;

        cout << "enter a grade or -1 to quit";
        cin >> grade;
    }

    if (count != 0) {
        double average = static_cast<double>(total) / 10; //将total的类型强制转换成double
        cout << "\ntotal of all" << count << " grade" << total << endl;
        cout << setprecision(2) << fixed;
        cout << "Class average is" << average << endl;
    } else
        cout << "don't enter any grade" << endl;
}

void Gradebook::inputGrades()
{
    double firstgrade;
    double secondgrade;
    double thirdgrade;

    cin >> firstgrade >> secondgrade >> thirdgrade;
    maxGrade = maximum(firstgrade, secondgrade, thirdgrade);
}

void Gradebook::displayGradeReport() const
{
    cout << "the max of entered: " << maxGrade << endl;
}

int Gradebook::maximum(int x, int y, int z) const
{
    int max = x;
    if (y > max)
        max = y;
    if (z > max)
        max = z;
    return max;
}
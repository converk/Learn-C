#include "Gradebook.h"
#include <iostream>
#include <string>

using namespace std; //说明命名空间

int main()
{
    string nameOfcourse; //声明一个字符串类型的变量
    Gradebook mygradebook("Cs101"); //声明一个变量

    //初始值
    cout << "Initial coursename:" << mygradebook.get_coursename() << endl;

    cout << "please enter a course name" << endl;
    getline(cin, nameOfcourse); //从键盘读取一个字符串
    mygradebook.set_coursename(nameOfcourse); //设置新值
    cout << endl; //打印一个空行

    mygradebook.displayMessage();
    mygradebook.deterclassaverage(); //打印平均成绩

    cout << "please enter three grades" << endl;
    mygradebook.inputGrades();
    mygradebook.displayGradeReport();
    return 0;
}
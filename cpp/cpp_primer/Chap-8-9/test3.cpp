#include <array>
#include <forward_list>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // list<string> authors = { "mike", "Nik", "Lin" }; //一个list容器
    // vector<const char*> articles = { "a", "an", "the" };
    // vector<int> numbers = { 1, 2, 3 };
    // forward_list<string> words(articles.begin(), articles.end());
    // cout << words.front() << endl;
    //由于使用迭代器进行初始化,而元素类型又可以进行强制转换,所以可以初始化
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> a_vec(begin(a), end(a)); //使用数组初始化vector
    list<int> a_li(a_vec.begin(), a_vec.end()); //使用vector初始化list

    auto a_begin = a_vec.begin();
    //auto a_end = a_vec.cend();
    while (a_begin != a_vec.end()) {
        if (*a_begin % 2 == 0)
            a_vec.erase(a_begin);
        else
            ++a_begin;
    }
}
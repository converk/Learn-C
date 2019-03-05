#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vi; //用来储存字符串的容器

    //一直输入,直到遇到空白停下
    string str;
    getline(cin, str);
    for (; str != ""; getline(cin, str)) {
        vi.push_back(str);
    }
    auto c = vi.cbegin();
    auto end = vi.cend();

    for (auto c = vi.cbegin(); c != end && !c->empty(); c++)
        cout << *c << endl;
}
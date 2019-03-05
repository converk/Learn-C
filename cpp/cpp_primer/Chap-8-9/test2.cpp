#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> c;
    for (int i = 0; i < 5; i++)
        c.push_back(i);
    vector<int> c_res(c.rbegin(), c.rend());
    c.insert(c.begin(), 8);
    cout << c[0] << endl;
    cout << c_res[0] << endl;
    cout << typeid(c.begin()).name() << endl;
    return 0;
}
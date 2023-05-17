#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int e_num = s.size() - 2;
    e_num *= 2;
    cout << 'h';
    for (int i = 0; i < e_num; i++)
    {
        cout << 'e';
    }
    cout << 'y';
}
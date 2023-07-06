#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    int num;
    int diff = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        diff = 0;

        // abc|def
        // abc|cba

        diff += (str[2] - str[3]) * 100 + (str[1] - str[4]) * 10 + (str[0] - str[5]);

        num = stoi(str);

        cout << num + diff << "\n";
    }

    return 0;
}
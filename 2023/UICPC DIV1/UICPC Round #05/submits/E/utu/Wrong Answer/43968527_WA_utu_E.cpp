#include <iostream>
using namespace std;

bool is_pal(int n)
{
    string s = to_string(n);

    return (s[0] == s[5] && s[1] == s[4] && s[2] == s[3]);
}

int main()
{
    int n;
    cin >> n;

    string str;
    int num;
    int diff = 0;

    for (int i = 0; i < n; i++)
    // for (int num = 100000; num <= 999999; num++)
    {
        cin >> str;
        // str = to_string(num);
        diff = 0;

        diff += (str[2] - str[3]) * 100 + (str[1] - str[4]) * 10 + (str[0] - str[5]);

        num = stoi(str);

        // cout << "diff:" << diff << '\n';

        int a = num + diff;
        int b = num - diff;

        if (a < b)
        {
            cout << a << '\n';
        }
        else if (is_pal(b))
        {
            // cout << "Printing b for number " << num << '\n';
            cout << b << '\n';
        }
        else
        {
            cout << a << '\n';
        }
    }

    return 0;
}

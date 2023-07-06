#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool ss = false;
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == 's' && str[i] == str[i + 1])
        {
            ss = true;
            break;
        }
    }

    if (ss)
        cout << "hiss";
    else
        cout << "no hiss";

    return 0;
}
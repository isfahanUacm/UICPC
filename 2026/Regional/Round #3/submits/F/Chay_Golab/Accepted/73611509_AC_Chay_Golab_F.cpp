#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = (int)s.size();
        bool same = true;

        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[0])
            {
                same = false;
                break;
            }
        }

        if (same)
            cout << 0 << '\n';
        else
            cout << 2 * n - 2 << '\n';
    }

    return 0;
}
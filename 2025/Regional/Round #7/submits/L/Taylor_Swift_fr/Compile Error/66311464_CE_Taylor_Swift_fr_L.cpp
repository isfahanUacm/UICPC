#include <bits/stdc++.h>
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define pb push_back
#define int long long
#define N (int)1e5
using namespace std;

int32_t main()
{
    string s;
    cin >> s;
    if (s.size() == 2)
    {
        if (s[0] == '0'  s[1] == '0')
        {
            cout << -1;
        }
        else
            cout << s[0] << " " << s[1];
        return 0;
    }
    if (s.size() == 4)
    {
        if (s[0] == '0'  s[2] == '0')
        {
            cout << -1;
        }
        else
            cout << s.substr(0, 2) << " " << s.substr(2, 2);
        return 0;
    }
    if (s[0] == '0')
    {
        cout << -1;
    }
    else if (s[1] == '0')
    {
        if (s[2] != '0')
            cout << s.substr(0, 2) << ' ' << s.substr(2, 1);
        else
        {
            cout << -1;
        }
    }
    else if (s[2] == '0')
    {
        cout << s.substr(0, 1) << ' ' << s.substr(1, 2);
    }
    else
    {
        cout << -1;
    }
}
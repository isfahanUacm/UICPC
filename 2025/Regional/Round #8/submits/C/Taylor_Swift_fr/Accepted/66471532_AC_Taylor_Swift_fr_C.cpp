#include <bits/stdc++.h>
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define pb push_back
#define int long long
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int32_t main()
{
    while (true)
    {
        int a;
        cin >> a;
        if (!a)
        {
            break;
        }
        int s = 0;
        for (int i = 1; i <= a; ++i)
        {
            s += ((i + (i * a)) * a) / 2;
        }
        cout << s << endl;
    }
}
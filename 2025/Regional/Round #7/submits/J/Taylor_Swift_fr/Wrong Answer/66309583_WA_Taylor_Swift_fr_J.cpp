#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e3 + 9, MOD = 1e9 + 7;
int fact[N], a[N][N], b[N], num1[N], num2[N];

int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= N; i++)
        a[N][0] = -1;
    int point = 0;
    while (n--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            point++;
            a[point][0] = 1;
        }
        if (t == 2)
        {
            int i, x;
            cin >> i >> x;
            int ls = a[i][0];
            a[i][ls] = x;
            a[i][0]++;
        }
        if (t == 3)
        {
            int i, j;
            cin >> i >> j;
            cout << a[i][j] << endl;
        }
    }
    return 0;
}
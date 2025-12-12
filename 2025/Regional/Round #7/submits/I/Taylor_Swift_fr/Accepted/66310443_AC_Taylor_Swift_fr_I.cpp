#include <bits/stdc++.h>
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define pb push_back
#define int long long
#define MOD (int)(1e9 + 7)
#define endl '\n'
using namespace std;
int n, m;
vector<vector<char>> tb;

char dfs(int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
    {
        return 'z';
    }
    else
    {
        return tb[i][j];
    }
}

int32_t main()
{
    cin >> n >> m;
    tb.resize(m);
    for (int i = 0; i < m; ++i)
    {
        string a;
        cin >> a;
        vector<char> v(n);
        for (int j = 0; j < n; ++j)
        {
            v[j] = a[j];
        }
        tb[i] = v;
    }
    int cnt = 0;
    pair<int, int> ar1[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    pair<int, int> ar2[] = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}};
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (tb[i][j] == 'u' || tb[i][j] == 'U')
            {
                for (int k = 0; k < 8; ++k)
                {
                    if (dfs(i + ar1[k].ff, j + ar1[k].ss) == 'V' || dfs(i + ar1[k].ff, j + ar1[k].ss) == 'v')
                    {
                        if (dfs(i + ar2[k].ff, j + ar2[k].ss) == 'A' || dfs(i + ar2[k].ff, j + ar2[k].ss) == 'a')
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}
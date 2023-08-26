#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;
#define nl endl
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll modOp(ll a, ll b, int op)
{
    switch (op)
    {
    case 0:
        return ((a % MOD) + (b % MOD)) % MOD;
    case 1:
        return ((a % MOD) - (b % MOD) + MOD) % MOD;
    case 2:
        return (a % MOD) * (b % MOD) % MOD;
    }
}

int n, m;
int id(int i, int j)
{
    return i * m + j;
}

void solve()
{
    vector<pii> s = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    cin >> m >> n;

    vector<pii> fin, fires;
    int iS, jS;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && g[i][j] == '.')
            {
                fin.pb({i, j});
            }
            if (g[i][j] == '@')
            {
                iS = i, jS = j;
            }
            if (g[i][j] == '*')
            {
                fires.pb({i, j});
            }
        }

    if (iS == 0 || iS == n - 1 || jS == 0 || jS == m - 1)
    {
        cout << 1 << nl;
        return;
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vi> dis(n, vi(m, INT_MAX));

    queue<pii> q;
    for (pii fi : fires)
    {
        q.push(fi);
        vis[fi.F][fi.S] = true;
        dis[fi.F][fi.S] = 0;
    }

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (u.F + s[i].F >= 0 && u.F + s[i].F < n && u.S + s[i].S >= 0 && u.S + s[i].S < m)
            {
                if (g[u.F + s[i].F][u.S + s[i].S] != '#' && dis[u.F + s[i].F][u.S + s[i].S] > dis[u.F][u.S] + 1)
                {
                    vis[u.F + s[i].F][u.S + s[i].S] = true;
                    dis[u.F + s[i].F][u.S + s[i].S] = dis[u.F][u.S] + 1;
                    q.push({u.F + s[i].F, u.S + s[i].S});
                }
            }
        }
    }

    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    vector<vi> dis1(n, vi(m, INT_MAX));

    q.push({iS, jS});
    dis1[iS][jS] = 0;
    vis1[iS][jS] = true;

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (u.F + s[i].F >= 0 && u.F + s[i].F < n && u.S + s[i].S >= 0 && u.S + s[i].S < m)
            {
                if (g[u.F + s[i].F][u.S + s[i].S] != '#' && !vis1[u.F + s[i].F][u.S + s[i].S])
                {
                    vis1[u.F + s[i].F][u.S + s[i].S] = true;
                    dis1[u.F + s[i].F][u.S + s[i].S] = dis1[u.F][u.S] + 1;
                    q.push({u.F + s[i].F, u.S + s[i].S});
                }
            }
        }
    }

    for (pii fi : fin)
    {
        if (dis[fi.F][fi.S] > dis1[fi.F][fi.S] && vis1[fi.F][fi.S])
        {
            cout << dis1[fi.F][fi.S] + 1 << nl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << nl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

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

    for (pii fi : fin)
    {
        vector<bool> vis(n * m, false);
        vector<int> dis(n * m, INT_MAX);
        queue<int> q;

        q.push(fi.F * m + fi.S);
        vis[fi.F * m + fi.S] = true;
        dis[fi.F * m + fi.S] = 0;

        vector<pii> s = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            int x = u / m;
            int y = u % m;

            for (int i = 0; i < 4; i++)
            {
                if (x + s[i].F >= 0 && x + s[i].F < n && y + s[i].S >= 0 && y + s[i].S < m)
                {
                    int idx = id(x + s[i].F, y + s[i].S);
                    if (g[x + s[i].F][y + s[i].S] != '#' && !vis[idx])
                    {
                        vis[idx] = true;
                        dis[idx] = dis[u] + 1;
                        q.push(idx);
                    }
                }
            }
        }

        bool vld = true;
        for (pii fire : fires)
        {
            if (!vis[id(fire.F, fire.S)])
                continue;

            if (dis[id(iS, jS)] > dis[id(fire.F, fire.S)])
            {
                vld = false;
                break;
            }
        }

        if (vld && vis[id(iS, jS)])
        {
            cout << dis[id(iS, jS)] << nl;
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

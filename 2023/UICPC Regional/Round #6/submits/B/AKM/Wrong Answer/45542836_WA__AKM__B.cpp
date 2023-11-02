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
#define nl "\n"
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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool vld(int i, int j)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}

void solve()
{
    cin >> n >> m;
    n++, m++;

    int xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
    cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2;

    bool grid1[n + 1][m + 1], grid2[n + 1][m + 1];

    bool vis[n + 1][m + 1];
    int dis[n + 1][m + 1];
    int path[n + 1][m + 1];

    vis[xa1][ya1] = true;
    dis[xa1][ya1] = 0;
    queue<pii> q;
    q.push({xa1, ya1});

    int xAim = xa1, yAim = ya1;

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = u.F + dx[k], y = u.S + dy[k];
            if (vld(x, y) && grid1[x][y] && !vis[x][y])
            {
                dis[x][y] = dis[u.F][u.S] + 1;
                vis[x][y] = true;
                q.push({x, y});

                if (u.F == xAim && u.S == yAim)
                {
                    xAim = x;
                    yAim = y;
                    grid1[x][y] = true;
                }
            }
        }
    }

    bool vis1[n + 1][m + 1];
    int dis1[n + 1][m + 1];

    vis1[xb1][yb1] = true;
    dis1[xb1][yb1] = 0;
    q.push({xb1, yb1});

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = u.F + dx[k], y = u.S + dy[k];
            if (vld(x, y) && grid1[x][y] &&!vis1[x][y])
            {
                dis1[x][y] = dis1[u.F][u.S] + 1;
                vis1[x][y] = true;
                q.push({x, y});
            }
        }
    }

    int d1 = dis[xa2][ya2] + dis1[xb2][yb2];
    if (!vis1[xb2][yb2])
        d1 = INT_MAX;

    bool vis2[n + 1][m + 1];
    int dis2[n + 1][m + 1];

    vis2[xb1][yb1] = true;
    dis2[xb1][yb1] = 0;
    q.push({xb1, yb1});

    xAim = xb1, yAim = yb1;

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = u.F + dx[k], y = u.S + dy[k];
            if (vld(x, y) && grid2[x][y] && !vis2[x][y])
            {
                dis2[x][y] = dis2[u.F][u.S] + 1;
                vis2[x][y] = true;
                q.push({x, y});

                if (u.F == xAim && u.S == yAim)
                {
                    xAim = x;
                    yAim = y;
                    grid2[x][y] = true;
                }
            }
        }
    }

    bool vis3[n + 1][m + 1];
    int dis3[n + 1][m + 1];

    vis3[xa1][ya1] = true;
    dis3[xa1][ya1] = 0;
    q.push({xa1, ya1});

    while (!q.empty())
    {
        pii u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = u.F + dx[k], y = u.S + dy[k];
            if (vld(x, y) && grid2[x][y] && !vis3[x][y])
            {
                dis3[x][y] = dis3[u.F][u.S] + 1;
                vis3[x][y] = true;
                q.push({x, y});
            }
        }
    }

    int d2 = dis2[xb2][yb2] + dis3[xa2][ya2];
    if (!vis3[xa2][ya2])
        d2 = INT_MAX;

    if (min(d1, d2) == INT_MAX)
        cout << "IMPOSSIBLE";
    else
        cout << min(d1, d2);
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}

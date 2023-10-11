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

void solve()
{
    int n;
    cin >> n;

    vector<pll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].F >> a[i].S;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].F >> b[i].S;
    }

    set<tuple<ll, int, int>, greater<tuple<ll, int, int>>> dis;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis.insert(make_tuple(abs(a[i].F - b[j].F) + abs(a[i].S - b[j].S), i, j));
        }
    }

    vi deg(2 * n, n);
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vi p;

    for (tuple<ll, int, int> t : dis)
    {
        deg[get<1>(t)]--;
        deg[get<2>(t) + n]--;
        vis[get<1>(t)][get<2>(t)] = true;
        vis[get<2>(t)][get<1>(t)] = true;

        int u = get<1>(t);
        int v = get<2>(t);

        if (deg[get<1>(t)] == 1)
        {
            int m = -1;
            for (int i = 0; i < n; i++)
            {
                if (!vis[u][i])
                {
                    m = i;
                    p.push_back(abs(a[i].F - b[u].F) + abs(a[i].S - b[u].S));
                    break;
                }
            }

            for (int i = 0; i < n && m != -1; i++)
            {
                vis[i][m] = true;
                vis[m][i] = true;
            }
        }
        if (deg[get<2>(t) + n] == 1)
        {
            int m = -1;
            for (int i = 0; i < n; i++)
            {
                if (!vis[v][i])
                {
                    m = i;
                    p.push_back(abs(a[i].F - b[v].F) + abs(a[i].S - b[v].S));
                    break;
                }
            }

            for (int i = 0; i < n && m != -1; i++)
            {
                vis[i][m] = true;
                vis[m][i] = true;
            }
        }
    }

    cout << *max_element(all(p));
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}

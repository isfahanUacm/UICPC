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

const int mxn = 2e5 + 10;
vector<pii> g[mxn];

pair<int, ll> dfs(int u, vector<bool> &vis)
{
    vis[u] = true;
    pair<int, ll> aim = {u, 0};
    for (pair<int, ll> v : g[u])
    {
        if (!vis[v.F])
        {
            pair<int, ll> tmp = dfs(v.first, vis);
            tmp.S += v.S;
            if (aim.S < tmp.S)
                aim = tmp;
        }
    }

    return aim;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].pb({v, c});
        g[v].pb({u, c});
        sum += c;
    }

    if (k >= 2)
    {
        cout << sum << nl;
    }
    else
    {
        vector<bool> vis(n, false);
        pair<int, ll> aim = dfs(0, vis);

        vector<bool> vis1(n, false);
        aim = dfs(aim.F, vis1);
        
        cout << aim.S << nl;
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}

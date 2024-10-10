#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
using pqg = priority_queue<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 1e12;
const ll MOD = 1e9 + 7;
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
#define lb lower_bound
#define ub upper_bound
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

const int mxn = 1e5 + 1;

void solve()
{
    ll n;
    cin >> n;

    vl dp(n + 1);
    vector<pll> g[n + 1];

    for (int i = 2; i <= n; i++)
    {
        ll p, x;
        cin >> p >> x;
        g[p].pb({x, i}), g[i].pb({x, p});
    }

    queue<ll> p;
    vector<bool> vis(n + 1, false);
    p.push(1), vis[1] = true;
    vector<ll> leaves, par(n + 1, -1);

    while (!p.empty())
    {
        ll u = p.front();
        p.pop();

        ll mn = inf;
        for (pll v : g[u])
            if (!vis[v.S] and v.S != par[u] and mn > v.F)
                mn = v.F;

        for (pll v : g[u])
        {
            if (!vis[v.S] and v.S != par[u])
            {
                dp[v.S] = dp[u] + mn + (v.F - mn) * 2;
                vis[v.S] = true;
                par[v.S] = u;
                p.push(v.S);
            }
        }

        if (sz(g[u]) == 1)
            leaves.pb(dp[u]);
    }

    ll q;
    cin >> q;

    sort(all(leaves));

    while (q--)
    {
        ll t;
        cin >> t;

        auto l = upper_bound(all(leaves), t);
        cout << upper_bound(all(leaves), t) - leaves.begin() << endl;
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#else
    fastio
#endif

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

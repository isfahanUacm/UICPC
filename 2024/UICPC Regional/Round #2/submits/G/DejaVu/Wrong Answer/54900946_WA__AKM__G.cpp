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

const ll inf = 1e18;
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

const int mxn = 3e5 + 4;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<tuple<ll, ll, ll>> g[n];

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w, c;
        cin >> u >> v >> c >> w;
        u--, v--;
        g[u].pb({v, w, c}), g[v].pb({u, w, c});
    }

    vector<ll> dis(n, inf);
    vector<bool> vis(n, false);
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    dis[0] = 0;
    vis[0] = true;
    // W, C, index
    pq.push({0, 0, 0});
    while (!pq.empty())
    {
        tuple<ll, ll, ll> u = pq.top();
        pq.pop();

        if (get<1>(u) >= k and vis[get<2>(u)])
            continue;

        vis[get<2>(u)] = true;
        for (tuple<ll, ll, ll> v : g[get<2>(u)])
            if (!vis[get<0>(v)] and dis[get<0>(v)] > max(dis[get<2>(u)], get<1>(v)) and get<1>(u) + get<2>(v) < k)
            {
                dis[get<0>(v)] = max(dis[get<2>(u)], get<1>(v));
                pq.push({dis[get<0>(v)], get<1>(u) + get<2>(v), get<0>(v)});
            }
    }

    cout << ((dis[n - 1] == inf) ? -1 : dis[n - 1]) << endl;
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

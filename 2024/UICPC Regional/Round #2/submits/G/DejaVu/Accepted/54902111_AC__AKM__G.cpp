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

const int mxn = 1e5 + 1;
ll n, m, k;
vector<tuple<ll, ll, ll>> g[mxn];

bool dijsktra(ll W)
{
    constexpr int64_t INF = 1e18;
    vector<int64_t> dist(n, INF);
    auto dijkstra = [&](int s) -> void
    {
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
        dist[s] = 0;
        pq.emplace(dist[s], s);
        while (!pq.empty())
        {
            auto [dist_v, v] = pq.top();
            pq.pop();

            if (dist_v != dist[v])
            {
                continue;
            }
            for (auto [u, w, c] : g[v])
            {
                if (dist[v] + c < dist[u] and w <= W)
                {
                    dist[u] = dist[v] + c;
                    pq.emplace(dist[u], u);
                }
            }
        }
    };

    dijkstra(0);
    return (dist[n - 1] < k);
}

void solve()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w, c;
        cin >> u >> v >> c >> w;
        u--, v--;
        g[u].pb({v, w, c}), g[v].pb({u, w, c});
    }

    ll l = 1, r = 1e9, ans = 1e9;
    while (l <= r)
    {
        ll mid = (l + r) / 2;

        if (dijsktra(mid))
            r = mid - 1, ans = min(ans, mid);
        else
            l = mid + 1;
    }

    cout << ((ans == 1e9) ? -1 : ans) << endl;

    for (int i = 0; i <= n; i++)
        g[i].clear();
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

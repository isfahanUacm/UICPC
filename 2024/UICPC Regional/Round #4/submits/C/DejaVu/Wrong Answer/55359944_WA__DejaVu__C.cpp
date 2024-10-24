#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using str = string;

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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T>
bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
    return 0;
}

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

const int N = 2e5 + 1;
vl g[N];
ll n, m, q;

vl dij(int s)
{
    constexpr int INF = 1e9;
    vl dist(n, INF);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : g[v])
        {
            if (dist[v] + 1 < dist[u])
            {
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    return dist;
}

void solve()
{
    cin >> n >> m >> q;

    vl s(q);
    for (int i = 0; i < q; i++)
        cin >> s[i], s[i]--;

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v), g[v].pb(u);
    }

    vl source = dij(0);
    vl dest = dij(n - 1);

    ll a = source[n - 1];
    ll b = 1;

    ll ps = 0;
    for (int i = 0; i < q; i++)
        ps += dest[s[i]];

    for (int i = 0; i < q; i++)
    {
        ll p = source[s[i]];
        ll x = ps - dest[s[i]];
        ll y = q - 1;
        ll f = p * y + x;

        if (a * y > f * b)
        {
            a = f;
            b = y;
        }
    }

    cout << a << '/' << b << endl;
}

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}
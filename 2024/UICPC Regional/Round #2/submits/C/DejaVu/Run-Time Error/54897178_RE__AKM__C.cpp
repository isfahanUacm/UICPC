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
ll x = 0;
struct DSURank
{
    ll n;
    vl rank;
    vector<pll> par;

    DSURank(ll n)
    {
        par.assign(n, {-1, 0});
        rank.assign(n, 0);
    }

    ll find(ll u)
    {
        x = max(x, par[u].S);
        return par[u].F == -1 ? u : find(par[u].F);
    }

    // with path compression
    // ll find(ll u) { return par[u] == -1 ? u : par[u] = find(par[u]); }

    void merge(ll u, ll v, ll idx)
    {
        if ((u = find(u)) == (v = find(v)))
            return;

        if (rank[u] < rank[v])
            swap(u, v);

        par[v] = {u, idx};
        rank[u] = max(rank[u], rank[v] + 1);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSURank dsu(n);

    for (int i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            dsu.merge(b, c, i);
        }
        else
        {
            x = 0;
            ll p = dsu.find(b), q = dsu.find(c);
            cout << ((p != q) ? -1 : x) << endl;
        }
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

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

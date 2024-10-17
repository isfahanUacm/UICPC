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

int lis(vector<ll> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        for (int l = 1; l <= n; l++)
        {
            if (d[l - 1] < a[i] && a[i] < d[l])
                d[l] = a[i];
        }
    }

    int ans = 0;
    for (int l = 0; l <= n; l++)
    {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

void solve()
{
    ll Tx, Ty;
    cin >> Tx >> Ty;

    ll n;
    cin >> n;

    vector<ll> powp(n + 1, 1);
    ll p = 53;
    for (int i = 1; i < n + 1; i++)
        powp[i] = powp[i - 1] * p, powp[i] %= MOD;

    unordered_map<ll, vpl> X;
    vector<pair<pl, ll>> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].F.F >> s[i].F.S >> s[i].S;
        ll y = s[i].F.S - Ty, x = s[i].F.F - Tx;

        ll gcd = __gcd(x, y);
        if (gcd < 0)
            gcd *= -1;

        str h = to_string(x / gcd) + to_string(y / gcd);
        ll val = 0;
        for (int i = 0; i < n; i++)
            val += powp[i] * h[i], val %= MOD;

        X[val].pb({x * x + y * y, s[i].S});
    }

    ll ans = 0;
    for (pair<ll, vpl> u : X)
    {
        sort(all(u.S));
        vl a;
        for (pl v : u.S)
            a.pb(v.S);

        ans += lis(a);
    }

    cout << ans << endl;
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
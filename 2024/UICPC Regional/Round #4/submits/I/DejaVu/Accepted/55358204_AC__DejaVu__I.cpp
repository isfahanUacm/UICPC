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

const int N = 1e6 + 2e5 + 1;
ll n;

#define mid ((l + r) >> 1)
#define lid (id << 1)
#define rid (lid | 1)

struct Data
{
public:
    ll data = 0;
    Data() {}
    Data(int data_) { data = data_; }
};

struct Lazy
{
public:
    ll prop = 0;
    Lazy() {}
    Lazy(int prop_) { prop = prop_; }
};

struct LazySegTree
{
    vector<Data> seg;
    vector<Lazy> lazy;

    LazySegTree(ll n_)
    {
        n = n_;
        seg.assign(4 * n, Data());
        lazy.assign(4 * n, Lazy());
    }

    Data merge(Data l, Data r)
    {
        return Data(l.data + r.data);
    }

    void relax(ll id, Lazy x, ll l)
    {
        seg[id].data += x.prop * l;
        lazy[id].prop += x.prop;
    }

    void relaxT(ll l, ll r, ll id)
    {
        relax(2 * id, lazy[id], mid - l);
        relax(2 * id + 1, lazy[id], r - mid);
        lazy[id].prop = 0;
    }

    void build(ll l = 0, ll r = n, ll id = 1)
    {
        if (l + 1 == r)
        {
            seg[id] = 0;
            return;
        }

        build(l, mid, lid);
        build(mid, r, rid);

        seg[id] = merge(seg[lid], seg[rid]);
    }

    Data get(ll s, ll t, ll l = 0, ll r = n, ll id = 1)
    {
        if (l >= s && r <= t)
            return seg[id];

        relaxT(l, r, id);

        if (t <= mid)
            return get(s, t, l, mid, lid);

        if (s >= mid)
            return get(s, t, mid, r, rid);

        return merge(get(s, t, l, mid, lid), get(s, t, mid, r, rid));
    }

    void upd(ll s, ll t, ll x, ll l = 0, ll r = n, ll id = 1)
    {
        if (l >= s and r <= t)
        {
            relax(id, Lazy(x), r - l);
            return;
        }

        relaxT(l, r, id);

        if (t <= mid)
            upd(s, t, x, l, mid, lid);
        else if (s >= mid)
            upd(s, t, x, mid, r, rid);
        else
            upd(s, t, x, l, mid, lid), upd(s, t, x, mid, r, rid);

        seg[id] = merge(seg[lid], seg[rid]);
    }
};

void solve()
{
    n = N;
    LazySegTree lst(n), lrt(n);

    int m;
    cin >> m;
    vl s(m);
    set<ll> pq;
    map<ll, ll> x;
    for (int i = 0; i < m; i++)
        cin >> s[i], pq.insert(s[i]), x[i] = s[i];

    vl dp(n, -1);
    dp[n - 1] = n;

    for (int i = n - 2; i >= 0; i--)
    {
        if (pq.find(i + 1) != pq.end())
            dp[i] = dp[i + 1];
        else
            dp[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
        lst.upd(i, i + 1, dp[i]);

    dp.clear();
    dp.assign(n, -1);
    dp[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (pq.find(i - 1) != pq.end())
            dp[i] = dp[i - 1];
        else
            dp[i] = i - 1;
    }

    for (int i = 0; i < n; i++)
        lrt.upd(i, i + 1, dp[i]);

    int q;
    cin >> q;
    while (q--)
    {
        int u;
        cin >> u;
        u--;

        ll pos = x[u];
        ll next = lst.get(pos, pos + 1).data;
        ll before = lrt.get(pos, pos + 1).data;

        lst.upd(before, pos, pos - next);
        ll tmp = lst.get(next, next + 1).data;
        lst.upd(pos, next, tmp - next);

        tmp = lst.get(next, next + 1).data;
        lrt.upd(next + 1, tmp + 1, pos - next);
        lrt.upd(pos + 1, next + 1, pos - before);

        x[u] = next;

        cout << x[u] << endl;
    }
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
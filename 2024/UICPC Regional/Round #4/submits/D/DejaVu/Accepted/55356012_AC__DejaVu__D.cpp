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

void solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    vl s;
    for (int i = 0; i < a; i++)
        s.pb(4);
    for (int i = 0; i < b; i++)
        s.pb(6);
    for (int i = 0; i < c; i++)
        s.pb(8);
    for (int i = 0; i < d; i++)
        s.pb(12);
    for (int i = 0; i < e; i++)
        s.pb(20);

    map<ll, ld> cnt;
    for (int i = 1; i <= s[0]; i++)
        cnt[i] = 1;

    for (int i = 1; i < sz(s); i++)
    {
        map<ll, ld> ncnt;
        for (pair<ll, ld> u : cnt)
            for (int j = 1; j <= s[i]; j++)
                ncnt[u.F + j] += u.S;

        for(pair<ll, ld> u : ncnt)
            ncnt[u.F] /= 5.0;

        cnt = ncnt;
    }

    vector<pair<ld, ll>> ans;
    for (pair<ll, ld> u : cnt)
        ans.pb({u.S, u.F});

    sort(all(ans));
    reverse(all(ans));

    for (pl u : ans)
        cout << u.S << ' ';

    cout << endl;
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
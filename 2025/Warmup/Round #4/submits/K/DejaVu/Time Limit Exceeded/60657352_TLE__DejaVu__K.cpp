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

template <class T> using pqg = priority_queue<T>;
template <class T> using pql = priority_queue<T, vector<T>, greater<T>>;

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

template <typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

const int N = 2e5 + 1;

void solve() {
    ll n, d;
    cin >> n >> d;

    map<ll, ll> cnt;
    vl p(n, 0);

    for (int i = 0; i < d; i++) {
        ll u, v;
        cin >> u >> v;
        p[u] += 1;
        p[v] += 1;
    }

    for (ll u : p) {
        cnt[u] += 1;
    }

    if (n - sz(cnt) > 0) {
        cnt[0] = n - sz(cnt);
    }

    while (sz(cnt) > 1) {
        pl u = *cnt.begin();
        if (u.S >= 2) {
            cnt[u.F] -= 2;
            if (u.S == 2) {
                cnt.erase(cnt.begin());
            }
            cnt[u.F + 1] += 2;
        }
        else if (u.S == 1) {
            cnt.erase(cnt.begin());
            pl v = *cnt.begin();
            cnt[v.F + 1] += 1;
        }
    }

    cout << (*cnt.begin()).F << endl;
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
    //cin >> t;

    while (t--)
        solve();

    return 0;
}

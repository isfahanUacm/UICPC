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
    ll w;
    cin >> w;

    ll n;
    cin >> n;

    vector<pair<pl, ll>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].F.S >> s[i].F.F;
        s[i].S = i + 1;
    }

    set<pl, greater<pl>> p;

    sort(all(s));
    int idx = 0;
    ll ans = 0;
    ll res = 0;
    vl r;

    while (ans < w) {
        for (; idx < n and s[idx].F.F <= ans; idx++) {
            p.insert({s[idx].F.S, s[idx].S});
        }

        if (p.empty()) {
            break;
        }

        ans += (*p.begin()).F;
        r.pb((*p.begin()).S);
        p.erase(p.begin());

        res++;
    }

    if (ans >= w) {
        cout << res << endl;
        for (ll u : r) {
            cout << u << ' ';
        }
        cout << endl;
    } 
    else {
        cout << -1 << endl;
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
    //cin >> t;

    while (t--)
        solve();

    return 0;
}

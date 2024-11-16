#include <bits/stdc++.h>
#include <cinttypes>
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

template <typename T>
bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T>
bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

const int N = 2e5 + 1;

void solve()
{
    ll n;
    cin >> n;
    ll x = 0, y = 0;
    vl s(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    ll l = 0, r = 1000 + 1, ans = 1000 + 1;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        vl o = s;
        for (int i = 0; i < n; i++)
            o[i] += m;

        vl a = p;
        bool last;
        if (a[n - 1] > o[n - 1])
            last = false;
        else
            a[n - 1] = 0, last = true;

        for (int i = n - 2; i > 0; i--)
        {
            if(a[i] == o[i]) {
                if(last)
                    a[i] = 0;
            }
            else if(a[i] > o[i])
                last = false;
            else {
                a[i] = 0;
                last = true;
            }
        }

        ll u = *max_element(all(a));
        if(o[0] >= u) {
            r = m - 1;
            ans = min(m, ans);
        }
        else {
            l = m + 1;
        }
    }

    cout << ans << endl;
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
    // cin >> t;

    while (t--)
        solve();

    return 0;
}

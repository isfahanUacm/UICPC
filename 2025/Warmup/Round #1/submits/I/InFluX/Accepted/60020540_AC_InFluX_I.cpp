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
    ll n;
    cin >> n;
    vl p(n);
    for(int i = 0; i < n; i++) 
        cin >> p[i];

    vector<vl> dp(n, vl(2, 0));
    dp[0][0] = p[0];
    dp[0][1] = p[0] * 2;

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + p[i];
        dp[i][1] = dp[i - 1][0] + p[i] * 2;
    }

    ll ans = max(dp[n - 1][0], dp[n - 1][1]); 
    str res;
    ll idx = n - 1;
    while (idx >= 0) {
        if (ans == dp[idx][0]) {
            res.pb('O');
            ans -= p[idx];
        }
        else {
            res.pb('M');
            ans -= p[idx] * 2;
        }
        idx--;
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    reverse(all(res));
    cout << res << endl;
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

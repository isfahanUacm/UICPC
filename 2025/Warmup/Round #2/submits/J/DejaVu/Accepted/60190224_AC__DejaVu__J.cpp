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

const int N = 100 + 1;

void solve() {
    ll n;
    cin >> n;

    vector<vl> dp(n + 1, vl(n + 1));
    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 4; i <= n; i++) {
        if (i % 2) {
            ll k = i / 2;
            for (int j = 1; j < k; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
        }
        else {
            ll k = i / 2;
            for (int j = 1; j < k - 1; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            dp[i][k - 1] = 2 * dp[i - 1][k - 2];
            dp[i][k - 1] %= MOD;
        }
    }

    ll ans = 0;
    if (n % 2) {
        for (ll u : dp[n]) {
            ans += u;
            ans %= MOD;
        }

        ans *= n;
        ans %= MOD;
    }
    else {
        ll k = n / 2;
        for (int i = 0; i < k - 1; i++) {
            ans += dp[n][i];
            ans %= MOD;
        }
        ans *= n;
        ans %= MOD;

        ans += dp[n][k - 1] * n / 2;
        ans %= MOD;
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

    while (t--)
        solve();

    return 0;
}

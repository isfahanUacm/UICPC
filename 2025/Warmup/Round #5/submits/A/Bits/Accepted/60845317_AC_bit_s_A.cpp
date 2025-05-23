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

    vector<vector<ld>> dp(n + 1, vector<ld>(n + 1));
    dp[1][0] = -1;
    dp[1][1] = 1;

    for (int i = 2; i < n + 1; i++) {
        dp[i][0] = -i;
        dp[i][i] = i;
        for(int j = 1; j < i; j++) {
            dp[i][j] = 1.0 * j / i * dp[i - 1][j] + 1.0 * (i - j) / i * dp[i - 1][j - 1];
        }
    
    }

    for (int i = 0; i < n + 1; i++)
        cout << fixed << showpoint << setprecision(6) << dp[n][i]  << " \n"[i == n]; 
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

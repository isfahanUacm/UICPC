#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef DEBUG
#include "/home/mmd/debug.h"
#else
#define debug(x...)
#define arrdebug(x, s)
#define delay()
#define LINE
#define TIME
#endif


const int MOD = 1000000007;
//const int MOD = 998244353;
const char nl = '\n';
const int N = 140 + 9;
int g[N][N];
ll dp[N][N];
vector<float> v;

ld calc(int a1, int b1, int a2, int b2) {
    ld ans = dp[a2][b2];
    if (a1 > 0) ans -= dp[a1-1][b2];
    if (b1 > 0) ans -= dp[a2][b1-1];
    if (a1 > 0 && b1 > 0) ans += dp[a1-1][b1-1];

    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    int a, b; cin >> a >> b;
    F0R(i, n) F0R(j, m) cin >> g[i][j];

    F0R(i, n) {
        F0R(j, m) {
            dp[i][j] = g[i][j];
            if (j != 0) dp[i][j] += dp[i][j-1];
        }
    }
    F0R(j, m) {
        F0R(i, n) {
            if (i != 0) dp[i][j] += dp[i-1][j];
        }
    }

    F0R(i, n) {
        F0R(j, m) {
            if ((i+1) * (j+1) < a) continue;
            if ((i+1) * (j+1) > b) break;
            F0R(x, n) {
                if (x+i >= n) break;
                F0R(y, m) {
                    if (y+j >= m) break;
                    ld sum = calc(x, y, i+x, j+y);
                    sum /= (i+1) * (j+1);
                    v.pb(sum);
                }
            }
        }
    }


    int s = sz(v);
    ld ans;
    if (s % 2) {
        nth_element(v.begin(), v.begin() + s/2, v.end());
        ans = v[s/2];
    }
    else {
        nth_element(v.begin(), v.begin() + s/2, v.end());
        nth_element(v.begin(), v.begin() + (s/2)-1, v.end());
        ans = (v[s/2] + v[(s/2)-1]) / 2;
    }
    debug(s, v);
    cout << fixed << setprecision(4) << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

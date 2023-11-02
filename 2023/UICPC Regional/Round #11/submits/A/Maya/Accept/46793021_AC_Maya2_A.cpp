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

#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef DEBUG
#include "/home/mohammad/Code/debug.h"
#else
#define dbg(x...)
#define dbgarr(x, s)
#define LINE
#define TIME
#endif


const int MOD = 1000000007;
//const int MOD = 998244353;
const char nl = '\n';
const int N =  2e5 + 9;
vpl g[N];
pl mx[N];
bool used[N];

ll dfs(int s) {
	used[s] = true;
	for (auto e : g[s]) {
		ll v = e.F, w = e.S;
		if (!used[v]) {
			ll num = dfs(v)+w;
			cmax(mx[s].S, num);
			if (mx[s].S > mx[s].F) swap(mx[s].S, mx[s].F);
		}
	}
	return mx[s].F;
}

void solve() {
	int n, k; cin >> n >> k;
	ll ans = 0;
	for (int i = 0; i < n-1; i++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		ans += w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	if (k > 1) {
		cout << ans << nl;
		return;
	}
	dfs(0);
	ans = 0;
	for (int i = 0; i < n; i++) cmax(ans, mx[i].F+mx[i].S);
	cout << ans << nl;
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

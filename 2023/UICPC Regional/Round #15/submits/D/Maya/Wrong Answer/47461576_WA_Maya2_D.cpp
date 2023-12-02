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
const int N = 3e5 + 9;
ll val[N];
vi g[N];

ll dfs(int s) {
	dbg(s, val[s]);
	if (val[s]) {
		int f = 0, y = -1;
		ll sum = 0;
		for (int x: g[s]) {
			ll v = dfs(x);
			if (v==-1) f++, y=x;
			else sum += v;
		}
		if (f==0) return val[s];
		if (f > 1) {
			cout << "impossible\n";
			exit(0);
		}
		if (f==1) {
			for (int x: g[s]) {
				if (x==y) {
					val[x] = val[s]-sum;
					ll v = dfs(x);
					if (v==-1) {dbg(11);};
				}
			}
		}
		return val[s];
	}
	else {
		ll sum = 0;
		if (sz(g[s]) == 0) return -1;
		for (int x: g[s]) {
			dbg(s);
			ll v = dfs(x);
			dbg(s, v);
			if (v==-1) {
				return -1;
			}
			else sum += v;
		}
		dbg(sum);
		val[s] = sum;
		return val[s];
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int p; cin >> p;p--;
		g[p].pb(i);
	}
	for (int i = 0; i < n; i++) cin >> val[i];
	int x = dfs(0);
	if (x == -1) { 
		cout << "impossible\n";
		return;
	}
	else {
		for (int i = 0; i < n; i++) cout << val[i] << nl;
	}
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

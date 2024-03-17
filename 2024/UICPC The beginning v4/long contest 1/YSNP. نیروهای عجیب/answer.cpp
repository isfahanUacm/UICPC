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
#include "/home/mohammad/code/debug.h"
#else
#define dbg(x...)
#define dbgarr(x, s)
#define LINE
#define TIME
#endif


const int MOD = 1000000007;
//const int MOD = 998244353;
const char nl = '\n';
const int N = 1e5 + 9;
ll a[N], ans[N], done[N];
vi counter[N], dis[N];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	dbgarr(a, n);
	
	for (int i = 0; i < n; i++) {
		if (!done[a[i]]) {
			done[a[i]] = 1;
			vi v;
			int sq = sqrt(a[i]);
			for (int j = 1; j <= sq; j++) {
				if (a[i]%j==0) {
					v.pb(j);
					int jj = a[i]/j;
					if (jj != j) v.pb(jj);
				}
			}
			sort(all(v));
			counter[a[i]] = v;
		}
		for (int x: counter[a[i]]) {
			dis[x].pb(n-i-1);
		}
	}

	int mx = a[n-1];
	for (int i = mx; i > 0; i--) {
		ans[i] = 0;
		sort(all(dis[i]));
		int m = sz(dis[i]);
		for (int j = 0; j < m; j++) {
			ans[i] += dis[i][j]*(m-j-1);
		}
		dbg(i, dis[i], ans[i]);
		for (int j = 2; j <= mx; j++) {
			int tmp = i*j;
			if (tmp > mx) break;
			ans[i] -= ans[tmp];
		}
		dbg(ans[i]);
		dis[i].clear();
	}
	dbgarr(ans, mx+1);
	
	ll sum = 0;
	for (ll i = 1; i <= mx; i++) sum += i*ans[i];
	cout << sum << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

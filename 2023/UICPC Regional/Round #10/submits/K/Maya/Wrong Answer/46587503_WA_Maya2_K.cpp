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
vector<pd> v;

void solve() {
	ld n, m; cin >> n >> m;	
	ld l; cin >> l;
	v.pb({0, 0}); 
	if (l*l == pow(n,2)+pow(m,2));
	else if (l < n+m) {
		ld x = (n*n+m*m-l*l)/(2*(n-l));
		v.pb({x, 0});
	}
	else {
		v.pb({n, 0});
		l -= n+m;
		l /= 2;
		ld num = 1;
		while (l) {
			if (l >= n) {
				v.pb({n, num});
				v.pb({0, num});
				v.pb({0, num+1});
				if (num+1 != m) v.pb({n, num+1});
				num+=2;
				l -= n;
			}
			else {
				v.pb({n, num});
				v.pb({n-l , num});
				v.pb({n-l , num+1});
				if (num+1 != m)	v.pb({n, num+1});
				break;
			}
		}
	}
	v.pb({n, m});
	cout << sz(v) << nl;
	for (auto x : v) cout << x.F << ' ' << x.S << nl;
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

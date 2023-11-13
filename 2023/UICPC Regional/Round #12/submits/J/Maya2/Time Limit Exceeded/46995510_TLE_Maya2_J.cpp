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
const int N =  2e6 + 9;
ld n, p;

ld f(ld x) {
	ld res = x * p / (n+1);
	for (ld i = 0; i < x-1; i++) {
		res *= (n-p+2+i);
		res /= (n+2+i);
	}

	return res;
}
void solve() {
	cin >> n >> p;
	ld ans = 0;
	ll l=1, h=1e8;
	while (l <= h) {
		ll x = (l+h)/2;
		ld px = f(x-1);
		ld nx = f(x+1);
		ld xx = f(x);
		cmax(ans, xx);
		if (nx > xx) l = x+1;
		else if (px > xx) h = x-1;
		else break;
	}
	cout << fixed << setprecision(7) << ans << nl;
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

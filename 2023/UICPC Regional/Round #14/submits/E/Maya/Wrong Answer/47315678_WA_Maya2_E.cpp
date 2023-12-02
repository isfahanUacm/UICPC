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
const int N =  10;
const ld PI = 3.141592, dx = 1e-5;
ld a[N], b[N], h[N], val[N];

ld f(ld a, ld b, ld x) {
	ld res = a*exp(-x*x)+b*sqrt(x);
	return res;
}
ld ff(ld a, ld b, ld x) {
	ld res = f(a, b, x)*f(a, b, x);
	return res;
}
void solve() {
	ld v;
	int n;
	cin >> v >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i] >> h[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<int(1e6); j++) {
			ld x = j*dx;
			val[i] += PI*ff(a[i], b[i], x)*dx;
		}
	}
	int ind = 0;
	ld mindif = abs(val[0]-v);
	for (int i=1; i<n; i++) {
		ld dif = abs(val[i]-v);
		if (dif < mindif) {
			ind = i;
			mindif = dif;
		}
	}
	cout << ind << nl;
		
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

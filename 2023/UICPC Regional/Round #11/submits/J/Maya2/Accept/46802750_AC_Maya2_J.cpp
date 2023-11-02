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
const ld PI = 3.1415926535;


ld N, R, S, W, F, L1, L2;
void calc(ld D, int i) {
	ld r;
	if (i == 1) {
		r = R+L1;
	} else {
		r = R+(i-1)*W+L2;
	}
	ld rnd = 2*(PI*r + 2*S);
	int rc = D / (rnd);
	D -= rc*rnd;
		
	ld x, y, theta;
	if (D <= F+S) {
		if (i == 1) {
			r -= L1;
		} else {
			r -= L2;
		}
		x = F-D, y = -r;

	} else if (D <= F+S+PI*r) {
		ld dd = D - (F+S);
		theta = dd/r;
		if (i == 1) {
			r -= L1;
		} else {
			r -= L2;
		}
		x = -S -r*sin(theta), y = -r*cos(theta);

	} else if (D <= F+ 3*S+ PI*r) {
		ld dd = D - (F+S+PI*r);
		if (i == 1) {
			r -= L1;
		} else {
			r -= L2;
		}
		x = -S+dd, y = r;

	} else if (D <= F+ 3*S + 2*PI*r) {
		ld dd = D - (F+ 3*S+ PI*r);
		ld theta = dd/r;
		if (i == 1) {
			r -= L1;
		} else {
			r -= L2;
		}
		x = S+r*sin(theta), y = r*cos(theta);
	} else {
		ld dd = D - (F+ 3*S +2*PI*r);
		if (i == 1) {
			r -= L1;
		} else {
			r -= L2;
		}
		x = S-dd, y = -r;
	}
	cout << fixed << setprecision(4) << x << ' ' << y;
}
void solve() {
	cin >> N >> R >> S >> W >> F >> L1 >> L2;
	S /= 2;
	ld D;
	while  (cin >> D) {
		cout << D << ' ';
		for (int i=1; i<=N; i++) {
			calc(D, i);
			cout << ' ';
		}
		cout << nl;
	}
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

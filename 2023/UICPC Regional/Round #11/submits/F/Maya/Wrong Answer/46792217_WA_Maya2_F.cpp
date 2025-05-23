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

struct per {
	string e, f, l;
};

void solve() {
	string f, l, e;
	vector<per> vc;
	set<pair<string, pair<string,string>>> ireg, oreg;
	while (cin >> f >> l >> e) {
		transform(all(f), f.begin(), ::tolower);
		transform(all(l), l.begin(), ::tolower);
		transform(all(e), e.begin(), ::tolower);
		per a;
		a.f = f; a.e = e; a.l = l;
		vc.pb (a);
	}
	map<string, bool> mpf, mpl, mpe;

	int n = sz(vc) / 2;
	for (int i = 0; i < n; ++i) {
		ireg.insert({vc[i].e, {vc[i].l, vc[i].f}});
	}
	for (int i = n; i < n+n; ++i) {
		oreg.insert({vc[i].e, {vc[i].l, vc[i].f}});
		mpf[vc[i].f] = 1; mpl[vc[i].l] = 1; mpe[vc[i].e] = 1;
	}
	bool aa=0, bb=0;
	for (auto x : ireg) {
		if (!mpe[x.F] && !(mpl[x.S.F] && mpf[x.S.S])) {
			cout << "I " << x.F << ' ' << x.S.F << ' ' << x.S.S << nl;
			aa = 1;
		}
	}
	mpf.clear(); mpl.clear(); mpe.clear();
	for (int i = 0; i < n; ++i) {
		mpf[vc[i].f] = 1; mpl[vc[i].l] = 1; mpe[vc[i].e] = 1;
	}
	for (auto x : oreg) {
		if (!mpe[x.F] && !(mpl[x.S.F] && mpf[x.S.S])) {
			cout << "O " << x.F << ' ' << x.S.F << ' ' << x.S.S << nl;
			bb = 1;
		}
	}
	if (!bb and !aa) cout << "No mismatches." << nl;
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

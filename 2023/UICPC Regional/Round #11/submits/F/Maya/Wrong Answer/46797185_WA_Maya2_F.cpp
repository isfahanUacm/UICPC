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
	string f, l, e, str;
	vector<per> vc;
	map<string, string> mppf, mppl, mppe, mppf1, mppl1, mppe1;
	set<pair<string, pair<string,string>>> ireg, oreg;
	map<string, bool> mpf, mpl, mpe;
	int n1=0, n2=0;
	
	while (getline(cin, str)) {
		if (str == "") break;
		n1++;
		string ff = "", ll = "", ee = "";
		int ttt = sz(str), i = 0;
		for (i = 0; i < ttt; ++i) {
			if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n') ff += str[i];
			else break;
		}
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n') i++;
		for ( ; i < ttt; ++i) {
			if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n') ll += str[i];
			else break;
		}
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n') i++;
		for ( ; i < ttt; ++i) {
			if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n') ee += str[i];
			else break;
		}
		f = ff; e = ee; l = ll;
		transform(all(f), f.begin(), ::tolower);
		transform(all(l), l.begin(), ::tolower);
		transform(all(e), e.begin(), ::tolower);
		per a;
		a.f = f; a.e = e; a.l = l;
		mppf[a.f] = ff; mppl[a.l] = ll; mppe[a.e] = ee;
		
		ireg.insert({a.e, {a.l, a.f}});
		vc.pb (a);
	}
	while (getline(cin, str)) {
		n2++;
		string ff = "", ll = "", ee = "";
		int ttt = sz(str), i = 0;
		for (i = 0; i < ttt; ++i) {
			if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n') ff += str[i];
			else break;
		}
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n') i++;
		for ( ; i < ttt; ++i) {
			if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n') ll += str[i];
			else break;
		}
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n') i++;
		for ( ; i < ttt; ++i) {
			if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n') ee += str[i];
			else break;
		}
		f = ff; l = ll; e = ee;
		transform(all(f), f.begin(), ::tolower);
		transform(all(l), l.begin(), ::tolower);
		transform(all(e), e.begin(), ::tolower);
		per a;
		a.f = f; a.e = e; a.l = l;
		mppf1[a.f] = ff; mppl1[a.l] = ll; mppe1[a.e] = ee;
		
		oreg.insert({a.e, {a.l, a.f}});
		mpf[a.f] = 1; mpl[a.l] = 1; mpe[a.e] = 1;
		//vc.pb (a);
	}

/*
	int n = sz(vc) / 2;
	for (int i = 0; i < n; ++i) {
	}
	for (int i = n; i < n+n; ++i) {
	} */
	bool aa=0, bb=0;
	for (auto x : ireg) {
		if (!mpe[x.F] && !(mpl[x.S.F] && mpf[x.S.S])) {
			string ee, ff, ll;
			ee = mppe[x.F]; ff = mppf[x.S.S]; ll = mppl[x.S.F];
			cout << "I " << ee << ' ' << ll << ' ' << ff << nl;
			aa = 1;
		}
	}
	mpf.clear(); mpl.clear(); mpe.clear();
	for (int i = 0; i < n1; ++i) {
		mpf[vc[i].f] = 1; mpl[vc[i].l] = 1; mpe[vc[i].e] = 1;
	}
	for (auto x : oreg) {
		if (!mpe[x.F] && !(mpl[x.S.F] && mpf[x.S.S])) {
			string ee, ff, ll;
			ee = mppe1[x.F]; ff = mppf1[x.S.S]; ll = mppl1[x.S.F];
			cout << "O " << ee << ' ' << ll << ' ' << ff << nl;
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

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
const int N =  1e3 + 9;
int a[N], a2[N], a4[N];
vector<pair<char, int>> s2, s3;

void solve() {
	string s; cin >> s;
	int n = sz(s);
	s2.clear(); s3.clear();
	int nn = n;

	bool cond = true;

	for (int i = n-1; i > 0; i--) {
		if (s[i] == '2' && s[i-1] == '2') {
			i--;
			s2.pb({'4', i});
			if (i == 0) cond = false;
		}
		else if (s[i] == '2') {
			a2[i]++;
			s2.pb({'4', i});
		}
		else s2.pb({s[i], i});
	}
	if (cond && s[0] == '2') {
		s2.pb({'4', 0});
		a2[0]++;
	}
	else if (cond) s2.pb({s[0], 0});
	reverse(all(s2));
	
	cond = true;
	n = sz(s2);
	for (int i = n-1; i > 0; i--) {
		if (s2[i].F == '4' && s2[i-1].F == '4') {
			i--;
			s3.pb({'8', s2[i].S});
			if (i == 0) cond = false;
		}
		else if (s2[i].F == '4') {
			a4[s2[i].S]++;
			s3.pb({'8', s2[i].S});
		}
		else s3.pb({s[i], s2[i].S});
	}
	if (cond && s2[0].F == '4') {
		s3.pb({'8', s2[0].S});
		a4[0]++;
	}
	else if (cond) s3.pb({s[0], s2[0]. S});
	reverse(all(s3));

	n = sz(s3);
	int num = 0;
	ll a8 = 0;
	for (int i = 0; i < n; i++) 
		if (s3[i].F == '8') num++;
	if (int(log2(num)) != log2(num)) {
		a8 = pow(2, int(log2(num)) + 1) - num;
	}
	
	dbgarr(a2, nn); dbgarr(a4, nn);	
	dbg(a8);
	for (int i = 0; i < nn; i++) {
		cout << s[i];
		while (a2[i]--) cout << '2';
		while (a4[i]--) cout << '4';
	}
	while (a8--) cout << '8';
	cout << nl;

	fill(a2, a2+nn, 0);
	fill(a4, a4+nn, 0);
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

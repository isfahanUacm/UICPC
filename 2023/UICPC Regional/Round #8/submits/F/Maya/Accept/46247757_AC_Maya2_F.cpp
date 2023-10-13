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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

#define F first
#define S second
#define pb push_back
#define mp make_pair
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
vector<pair<vector<string>, vector<string>>> v;
set<string> s1, s2;
map<string, vi> m1, m2;

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		int m; cin >> m;
		vector<string> v1(m);
		for (int j = 0; j < m; j++) {
			cin >> v1[j];	
			s1.insert(v1[j]);
			m1[v1[j]].pb(i);
		}
		cin >> m; 
		vector<string> v2(m);
		for (int j = 0; j < m; j++) {
			cin >> v2[j];
			s2.insert(v2[j]);
			m2[v2[j]].pb(i);
		}
		v.pb({v1, v2});
	}
	dbg(s1, s2);
	for (string ss1 : s1) {
		for  (string ss2 : s2) {
			if (m1[ss1] == m2[ss2]) {
				cout << '(' << ss1 << ", " << ss2 << ')' << nl;
			}
		}
	}
	cout << nl;

	s1.clear(); s2.clear();
	m1.clear(); m2.clear();
	v.clear();
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

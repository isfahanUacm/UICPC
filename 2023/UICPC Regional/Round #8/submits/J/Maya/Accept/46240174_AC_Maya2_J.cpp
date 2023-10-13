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


void solve() {
	string str; cin >> str;
	int l; cin >> l;
	map<char, pi> mp;
	mp['q'] = {0, 0};
	mp['w'] = {0, 1};
	mp['e'] = {0, 2};
	mp['r'] = {0, 3};
	mp['t'] = {0, 4};
	mp['y'] = {0, 5};
	mp['u'] = {0, 6};
	mp['i'] = {0, 7};
	mp['o'] = {0, 8};
	mp['p'] = {0, 9};
	
	mp['a'] = {1, 0};
	mp['s'] = {1, 1};
	mp['d'] = {1, 2};
	mp['f'] = {1, 3};
	mp['g'] = {1, 4};
	mp['h'] = {1, 5};
	mp['j'] = {1, 6};
	mp['k'] = {1, 7};
	mp['l'] = {1, 8};

	mp['z'] = {2, 0};
	mp['x'] = {2, 1};
	mp['c'] = {2, 2};
	mp['v'] = {2, 3};
	mp['b'] = {2, 4};
	mp['n'] = {2, 5};
	mp['m'] = {2, 6};

	set<pair<int, string>> st;
	for (int i = 0; i < l; i++) {
		string tmp; cin >> tmp;
		int tul = 0;
		for (int j = 0; j < sz(str); ++j) {
			tul += abs (mp[str[j]].first-mp[tmp[j]].first) + 
				   abs (mp[str[j]].second-mp[tmp[j]].second);
		}
		st.insert({tul, tmp});
	}
	for (auto pr : st) {
		cout << pr.second << ' ' << pr.first << nl;
	}
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

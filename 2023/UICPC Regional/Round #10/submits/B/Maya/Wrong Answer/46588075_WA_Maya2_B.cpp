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
#define int ll

void solve() {
	int n, k; cin >> n >> k;
	int mx_te = 0;
	map<string, int> vc;
	for (int i = 0; i < n; ++i) {
		string str; cin >> str;
		int x; cin >> x;
		vc[str] = x;
	}
	int l; cin >> l;
	map<string, int> mp, mp2;
	map<string, vector<int>> mp3;
	for (int i = 0; i < l; ++i) {
		string str; int x;
		cin >> str >> x;
		if (mp2[str] > 0) {
			if (mp[str] < x) mp[str] = x;
			mp2[str]++;
		}
		else {
			mp[str] = x;
			mp2[str]++;
		}
		mp3[str].pb (x);
		if (mp2[str] > mx_te) mx_te = mp2[str];
	}
	for (auto pr : vc) {
		string str = pr.F;
		if (pr.S < mp[str]) k -= (mp[str]-pr.S);
	}
	if (k < 0) {
		cout << 0 << nl;
		return;
	}
	else if (k == 0) {
		ll ans = 0;
		for (auto pr : mp3) {
			string str = pr.F;
			for (auto rp : pr.S) {
				if (rp < mp[str]) ans += mp[str];
			}
		}
		cout << ans << nl;
		return;
	}
	else {
		vector<pair<int, string>> tmp;
		ll ans = 0;
		for (auto pr : mp) {
			if (vc[pr.F] > pr.S) ans += (mp2[pr.F] * vc[pr.F]);
			else tmp.pb( {(pr.S+1) * mp2[pr.F], pr.F} );
		}
		sort (tmp.begin(), tmp.end(), greater<pair<int, string>>());
		bool si = true, na = true;
		for (auto xx : tmp) {
			if (xx.F > mx_te && si) {
				ans += xx.F;
				k--;
				if (k <= 0) {
					si = false;
				}
			}
			else {
				for (auto rp : mp3[xx.S]) {
					if (mp2[xx.S] == mx_te && na) {
						na = false;
						continue;
					}
					if (rp < mp[xx.S]) ans += mp[xx.S];
				}
			}
		}
		while (k > 0) {
			k--;
			ans += mx_te;
		}
		cout << ans << nl;
	}
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

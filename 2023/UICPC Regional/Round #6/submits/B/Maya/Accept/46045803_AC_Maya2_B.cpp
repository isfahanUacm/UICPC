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
	string str2 = "";
	for (int i = 0; i < str.size(); i++) {
		bool r = false, b = false, l = false;
		if (i+2 < str.size()) {
			for (int j = i; j <= i+2; j++) {
				if (str[j] == 'R') r = true;
				else if (str[j] == 'B') b = true;
				else l = true;
			}
			if (r && b && l) {
				str2 += 'C';
				i += 2;
			}
			else {
				str2 += str[i];
			}
		}
		else str2 += str[i];
	}
	for (int i = 0; i < str2.size(); ++i) {
		if (str2[i] == 'R') str2[i] = 'S';
		else if (str2[i] == 'B') str2[i] = 'K';
		else if (str2[i] == 'L') str2[i] = 'H';
	}
	cout << str2 << nl;
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

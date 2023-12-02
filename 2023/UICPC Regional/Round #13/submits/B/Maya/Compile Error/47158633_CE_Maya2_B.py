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
vl v;

void solve() {
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll pa = -1, pd = -1;
	if (binary_search(all(v), a)) {
		pa = lower_bound(all(v), a) - v.begin();
	}
	if (binary_search(all(v), d)) {
		pd = lower_bound(all(v), d) - v.begin();
	}
	dbg(pa, pd);
	if (pa == -1 || pd == -1) {
		cout << "impossible\n";
		return;
	}
	pa++, pd++;
	if (pd == 1) pd = 0;
	if (pd == 1) pd = 0;
	if (((pa)*(pd) != b+c)) {
		cout << "impossible\n";
		return;
	}
	if (pa == 0 && pd == 0) cout << '0';
	for (int i = pd; i > 0;) {
		if (b >= i) {
			cout << '0';
			b -= i;
			pa--;
		}
		else {
			cout << '1';
			i--;	
		}
	}
	for (int i = 0; i < pa; i++) cout << '0';
	cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

	v.pb(0);
	ll num = 1, x = 2;
	while (num <= int(1e9)) {
		v.pb(num);
		num += x;
		x++;
	}

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

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


const ll MOD = 1000000000000000007;
//const int MOD = 998244353;
const char nl = '\n';
const int N =  2e5 + 9;
ll ch[55][55];

void choose() {
	for (int i=0; i<54; i++) {
		for (int j=0; j<=i; j++) {
			if (i == j || j == 0) ch[i][j] = 1;
			else ch[i][j] = ch[i-1][j-1]+ch[i-1][j];
		}
	}
}

void solve() {
	ld w;
	ll n, a, b; cin >> n >> a >> b >> w;
	ll win = (n/2) + 1;
	ll aa = win - a, bb = win - b;
	ll r = n-a-b;
	if (aa <= 0) {
		cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
		return;
	}
	if (bb <= 0 || (r+aa) < win) {
		cout << "RECOUNT!\n";
		return;
	}

	ld so = 0;
	for (int i=aa; i<=r; i++) {
		so += ch[r][i];
	}
	so *= 100;
	ld ma = pow(2ll, r);
	ld ww = (so) / (ma);
	dbg(r, aa, so, ma, w, ww);
	if (ww > w) 
		cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
	else 
		cout << "PATIENCE, EVERYONE!\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	choose();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

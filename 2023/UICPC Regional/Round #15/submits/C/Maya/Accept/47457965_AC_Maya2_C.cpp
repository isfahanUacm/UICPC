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


void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll a1, a2, b1, b2, c1, c2; cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

		ll mn = 4e18;
		cmin(mn, (max(max(a1, b1), c1))*(a2+b2+c2));
		cmin(mn, (max(max(a1, b1), c2))*(a2+b2+c1));
		cmin(mn, (max(max(a1, b2), c1))*(a2+b1+c2));
		cmin(mn, (max(max(a1, b2), c2))*(a2+b1+c1));
		cmin(mn, (max(max(a2, b1), c1))*(a1+b2+c2));
		cmin(mn, (max(max(a2, b1), c2))*(a1+b2+c1));
		cmin(mn, (max(max(a2, b2), c1))*(a1+b1+c2));
		cmin(mn, (max(max(a2, b2), c2))*(a1+b1+c1));

		cmin(mn, (max(a1+b1, c1))*(max(a2,b2)+c2));
		cmin(mn, (max(a1+b1, c2))*(max(a2,b2)+c1));
		cmin(mn, (max(a1+b2, c1))*(max(a2,b1)+c2));
		cmin(mn, (max(a1+b2, c2))*(max(a2,b1)+c1));
		cmin(mn, (max(a2+b1, c1))*(max(a1,b2)+c2));
		cmin(mn, (max(a2+b1, c2))*(max(a1,b2)+c1));
		cmin(mn, (max(a2+b2, c1))*(max(a1,b1)+c2));
		cmin(mn, (max(a2+b2, c2))*(max(a1,b1)+c1));

		cmin(mn, (max(a1+c1, b1))*(max(a2,c2)+b2));
		cmin(mn, (max(a1+c1, b2))*(max(a2,c2)+b1));
		cmin(mn, (max(a1+c2, b1))*(max(a2,c1)+b2));
		cmin(mn, (max(a1+c2, b2))*(max(a2,c1)+b1));
		cmin(mn, (max(a2+c1, b1))*(max(a1,c2)+b2));
		cmin(mn, (max(a2+c1, b2))*(max(a1,c2)+b1));
		cmin(mn, (max(a2+c2, b1))*(max(a1,c1)+b2));
		cmin(mn, (max(a2+c2, b2))*(max(a1,c1)+b1));

		cmin(mn, (max(c1+b1, a1))*(max(c2,b2)+a2));
		cmin(mn, (max(c1+b1, a2))*(max(c2,b2)+a1));
		cmin(mn, (max(c1+b2, a1))*(max(c2,b1)+a2));
		cmin(mn, (max(c1+b2, a2))*(max(c2,b1)+a1));
		cmin(mn, (max(c2+b1, a1))*(max(c1,b2)+a2));
		cmin(mn, (max(c2+b1, a2))*(max(c1,b2)+a1));
		cmin(mn, (max(c2+b2, a1))*(max(c1,b1)+a2));
		cmin(mn, (max(c2+b2, a2))*(max(c1,b1)+a1));

		cout << mn << nl;
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

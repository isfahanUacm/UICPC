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
int num[26];

void solve() {
	string s; cin >> s;
	int n = sz(s);
	for (int i = 1; i <= 10; i++) num[i] = 5;
	for (int i = 11; i <= 15; i++) num[i] = 4;
	for (int i = 16; i <= 20; i++) num[i] = 3;
	for (int i = 21; i <= 25; i++) num[i] = 2;

	int rnk = 25, stars = 0, nwin = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			stars++;
			nwin++;
			if (stars > num[rnk]) {
				stars -= num[rnk];
				rnk--;
			}
			if (rnk >= 6 && nwin >= 3) stars++;
			if (stars > num[rnk]) {
				stars -= num[rnk];
				rnk--;
			}
			if (rnk == 0) break;
		}
		else {
			nwin = 0;
			if (rnk <= 20) stars--;
			if (stars < 0) {
				rnk++;
				stars = num[rnk]-1;
			}
		}
	}
	if (rnk == 0) cout << "Legend\n";
	else cout << rnk << nl;
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

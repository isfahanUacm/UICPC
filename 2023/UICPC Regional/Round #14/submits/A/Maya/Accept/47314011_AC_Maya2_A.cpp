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
const int N = 3e5 + 9;
string a[N];
string bb[30][4];
bool mark[4][4];
int b;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n = 4, m = 4; // DON'T MAKE THEM IN MAIN
 
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool rec(string s, int z, int x, int y, int j) {
	if (sz(s) == j) return true;
	for (int i = 0; i < 8; i++) {
		int xx = x+dx[i], yy=y+dy[i];
		if (!mark[xx][yy] && check(xx, yy)) {
			mark[xx][yy] = 1;	
			if (bb[z][xx][yy] == s[j] && rec(s, z, xx, yy, j+1)) {
				mark[xx][yy] = 0;
				return true;
			}
			mark[xx][yy] = 0;
		}
	}
	return false;	
}

bool calc(string s, int b) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < 4; k++) {
			if (rec(s, b, j, k, 0)) return true;
		}
	}
	return false;
}

map<int, int> po;

void solve() {
	po[3] = 1, po[4] = 1, po[5] = 2, po[6] = 3, po[7] = 5, po[8] = 11;
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b;
	for (int i = 0; i < b; i++) 	
		for (int j = 0; j < 4; j++) 
				cin >> bb[i][j];
	
	dbg(n, b);
	for (int j = 0; j < b; j++) {
		ll p = 0, num = 0, mx = 0;
		string mxs = "";
		for (int i = 0; i < n; i++) {
			if (calc(a[i], j)) {
				if (sz(a[i]) > mx) {
					mx = sz(a[i]);
					mxs = a[i];
				}
				if (sz(a[i]) == mx && a[i] < mxs) {
					mx = sz(a[i]);
					mxs = a[i];
				}
				num++;
				p += po[sz(a[i])];
			}
		}
		cout << p << ' ' << mxs << ' ' << num << nl;
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

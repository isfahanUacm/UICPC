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
	char x1, y1;
	int x2, y2;
	cin >> x1 >> x2 >> y1 >> y2;
	if (x1 == y1 && x2 == y2) {
		cout << 0 << ' ' << x1 << ' ' << x2 << nl;
	}
	else if ((int(x1)+x2)%2 != (int(y1)+y2)%2) {
		cout << "Impossible\n";
	}
	else if (int(x1)-x2 == int(y1)-y2) {
		cout << 1 << ' ' << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << nl;
	}
	else if (int(x1)+x2 == int(y1)+y2) {
		cout << 1 << ' ' << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << nl;
	}
	else {
		cout << 2 << ' ' << x1 << ' ' << x2 << ' ';
		bool f = false;
		char z1 = 'X'; int z2 = -1;
		int num1 = abs(int(x1)-x2), num2 = abs(y2-int(y1));
		int num3 = x2+int(x1), num4 = int(y1)+y2;
		for (int i = 1; i <= 8; i++) {
			for (char c = 'A'; c <= 'H'; c++) {
				int xx = abs(int(c)-i), yy = i+int(c);
				if ((num1 == xx || num3 == yy) && (num2 == xx || num4 == yy)) {
					z1 = c, z2 = i;
					f = true;
					break;
				}
			}
			if (f) break;
		}
		cout << z1 << ' ' << z2 << ' ' << y1 << ' ' << y2 << nl;
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

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
const int N = 30 + 9;
char g1[N][N], g2[N][N];

void solve() {
		int h, w, x; cin >> w >> h >> x;
		int num1 = 0, num2 = 0;
	for (int i = 0; i < h; i++) 
		for (int j = 0; j < w; j++) {
			cin >> g1[i][j];
			if (g1[i][j] == '#') num1++;
		}
	 for (int i = 0; i < h; i++) 
		 for (int j = 0; j < w; j++) {
			 cin >> g2[i][j];
			 if (g2[i][j] == '#') num2++;
		 }
	int i = 0; 
	bool win1 = false, win2 = false;
	 while (x--) {
		 int a, b; cin >> a >> b;
		 b = h - b - 1;
		if (i % 2 == 0) {
			if (g2[b][a] == '#') {
				num2--;
				g2[b][a] = '_';
				if(num2 == 0) i++;
			}
			else i++;
	 	}
		else {
			if (g1[b][a] == '#') {
				num1--;
				g1[b][a] = '_';
				if (num1 == 0) i++;
			}
			else i++;
			if (!win2 && num2 == 0 && num1 != 0) win1 = true;
			if (!win1 && num2 != 0 && num1 == 0) win2 = true;
		}
	 }
	dbg(num1, num2);	
	if (win1) {
		 cout << "player one wins\n";
	}
	else if (win2) {
		 cout << "player two wins\n";
	}
	else if ((num1 && num2) || (num1 == 0 && num2 == 0)) {
		cout << "draw\n";
	 }
	 else if (num1 == 0) {
		 cout << "player two wins\n";
	 }
	 else {
		 cout << "player one wins\n";
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

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
const int N =  1e3 + 9;
int a[N], a2[N], a4[N];
vector<pair<char, int>> s2, s3;

void solve() {
	string s; cin >> s;
	int n = sz(s);

	stack<int> st;
	st.push(s[0] - '0');
	cout << s[0];

	for (int i = 1; i < n; i++) {
		int t = st.top();
		int tt = s[i]-'0';
		dbg(tt, t);
		if (t == tt) {
			st.pop();
			st.push(tt*2);
		}
		bool c = false;
		if (tt > t) st.pop();
		while (tt > t) {
			cout << t;
			t *= 2;
			c = true;
		}
		if (c) {
			st.push(tt);
		}
		if (tt < t) {
			st.push(tt);
		}
		while (sz(st) >= 2) {
			int x = st.top();
			st.pop();
			if (x == st.top()) {
				st.pop();
				st.push(x*2);
			}
			else {
				st.push(x);
				break;
			}
		}
		if (c) st.push(tt);
		while (sz(st) >= 2) {
			int x = st.top();
			st.pop();
			if (x == st.top()) {
				st.pop();
				st.push(x*2);
			}
			else {
				st.push(x);
				break;
			}
		}
		cout << s[i];
	}
	while (sz(st) > 1) {
		int x = st.top();
		st.pop();
		dbg(x);
		if (x == st.top()) {
			st.pop();
			st.push(x*2);
		}
		else {
			if (x > 8) {
				int y = log2(x)-3;
				for (int i = 0; i < (1<<y); i++) cout << 8;
			}
			else {
				cout << x;
				cout << endl;
				st.push(x*2);
			}
		}
	}
	cout << nl;
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

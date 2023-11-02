#pragma GCC optimize("O3")
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
const int N =  1e6 + 9;
vi a1, c1, g1, t1, a2, c2, g2, t2;
const int n = int(1e6);
string s, t;
void solve() {
	int tmp; cin >> tmp;
	cin >> s >> t;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') a1.pb(i);
		if (s[i] == 'C') c1.pb(i);
		if (s[i] == 'G') g1.pb(i);
		if (s[i] == 'T') t1.pb(i);
		if (t[i] == 'A') a2.pb(i);
		if (t[i] == 'C') c2.pb(i);
		if (t[i] == 'G') g2.pb(i);
		if (t[i] == 'T') t2.pb(i);
	}
	int x = 1000000000;
	a1.resize(n); a2.resize(n);
	c1.resize(n); c2.resize(n);
	g1.resize(n); g2.resize(n);
	t1.resize(n); t2.resize(n);
	a1.pb(x);a2.pb(x);c1.pb(x);c2.pb(x);g1.pb(x);g2.pb(x);t1.pb(x);t2.pb(x);
	int i1=0, i2=0, i3=0, i4=0, j1=0, j2=0, j3=0, j4=0;
	while (true) {
		int mx1=x,mx2=x,mx3=x,mx4=x;
		if(i1 != sz(a1) && j1 != sz(a2)) mx1=max(a1[i1],a2[j1]);
		if(i2 != sz(c1) && j2 != sz(c2)) mx2=max(c1[i2],c2[j2]);
		if(i3 != sz(g1) && j3 != sz(g2)) mx3=max(g1[i3],g2[j3]);
		if(i4 != sz(t1) && j4 != sz(t2)) mx4=max(t1[i4],t2[j4]);
		int mn = min(mx1, mx2); cmin(mn, mx3); cmin(mn, mx4); 
		if (mn == x) break;
		if (mn == mx1) {
			cout << 'A';
			int m1 = a1[i1], m2=a2[j1];
			while (a1[i1] <= m1) i1++;
			while (a2[j1] <= m2) j1++;
			while (c1[i2] <= m1) i2++;
			while (c2[j2] <= m2) j2++;
			while (g1[i3] <= m1) i3++;
			while (g2[j3] <= m2) j3++;
			while (t1[i4] <= m1) i4++;
			while (t2[j4] <= m2) j4++;
		}
		if (mn == mx2) {
			cout << 'C';
			int m1 = c1[i2], m2=c2[j2];
			while (a1[i1] <= m1) i1++;
			while (a2[j1] <= m2) j1++;
			while (c1[i2] <= m1) i2++;
			while (c2[j2] <= m2) j2++;
			while (g1[i3] <= m1) i3++;
			while (g2[j3] <= m2) j3++;
			while (t1[i4] <= m1) i4++;
			while (t2[j4] <= m2) j4++;
		}
		if (mn == mx3) {
			cout << 'G';
			int m1 = g1[i3], m2=g2[j3];
			while (a1[i1] <= m1) i1++;
			while (a2[j1] <= m2) j1++;
			while (c1[i2] <= m1) i2++;
			while (c2[j2] <= m2) j2++;
			while (g1[i3] <= m1) i3++;
			while (g2[j3] <= m2) j3++;
			while (t1[i4] <= m1) i4++;
			while (t2[j4] <= m2) j4++;
		}
		if (mn == mx4) {
			cout << 'T';
			int m1 = t1[i4], m2=t2[j4];
			while (a1[i1] <= m1) i1++;
			while (a2[j1] <= m2) j1++;
			while (c1[i2] <= m1) i2++;
			while (c2[j2] <= m2) j2++;
			while (g1[i3] <= m1) i3++;
			while (g2[j3] <= m2) j3++;
			while (t1[i4] <= m1) i4++;
			while (t2[j4] <= m2) j4++;
		}
	}
	cout << nl;
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

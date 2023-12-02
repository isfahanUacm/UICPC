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
const int N = 5e3 + 9;
vi mo[N]; 
multiset<vi> s;
map<int, int> mp1, mp2;

void inc(int i, int x) {
	while (x) {
		int num = min(x, 60-mo[i][9]);
		mo[i][9] += num;
		x -= num;
		if (mo[i][9] == 60) {
			mo[i][9] = 0;
			mo[i][8]++;
			if (mo[i][8] == 24) {
				mo[i][8] = 0;
				mo[i][7]++;
				if (mo[i][5] != 2016 && mo[i][7] == mp1[mo[i][6]]) {
					mo[i][7] = 1;
					mo[i][6]++;
					if (mo[i][6] == 13) {
						mo[i][6] = 1;
						mo[i][5]++;
					}
				}
				else if (mo[i][5] == 2016 && mo[i][7] == mp2[mo[i][6]]) {
					mo[i][7] = 1;
					mo[i][6]++;
					if (mo[i][6] == 13) {
						mo[i][6] = 1;
						mo[i][5]++;
					}
				}
			}
		}
	}
}

void solve() {
	int n, mx; cin >> n >> mx;
	s.clear();
	for (int i = 0; i < n; i++) {
		mo[i].resize(10);
		string a, s1, s2, s3, s4; cin >> a >> s1 >> s2 >> s3 >> s4;
		mo[i][0] = stoi(s1.substr(0, 4));
		mo[i][1] = stoi(s1.substr(5, 2));
		mo[i][2] = stoi(s1.substr(8, 2));
		mo[i][3] = stoi(s2.substr(0, 2));
		mo[i][4] = stoi(s2.substr(3, 2));

		mo[i][5] = stoi(s3.substr(0, 4));
		mo[i][6] = stoi(s3.substr(5, 2));
		mo[i][7] = stoi(s3.substr(8, 2));
		mo[i][8] = stoi(s4.substr(0, 2));
		mo[i][9] = stoi(s4.substr(3, 2));

// 		dbg(mo[i][0], mo[i][1], mo[i][2], mo[i][3], mo[i][4]);
	}
	sort(mo, mo+n);

	int ans = 0;	
	for (int i = 0; i < n; i++) inc(i, mx);	

	for (int i = 0; i < n; i++) {
		vi inp, out;
		for (int j = 0; j < 5; j++) inp.pb(mo[i][j]);
		for (int j = 5; j < 10; j++) out.pb(mo[i][j]);
		s.insert(out);
		while ((*s.begin()) <= inp) s.erase(s.begin());
		cmax(ans, sz(s));
	}

	cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	mp1[1]=32, mp1[2]=29, mp1[3]=32, mp1[4]=31, mp1[5]=32, mp1[6]=31;
	mp1[7]=32, mp1[8]=32, mp1[9]=31, mp1[10]=32, mp1[11]=31, mp1[12]=32;
	mp2[1]=32, mp2[2]=30, mp2[3]=32, mp2[4]=31, mp2[5]=32, mp2[6]=31;
	mp2[7]=32, mp2[8]=32, mp2[9]=31, mp2[10]=32, mp2[11]=31, mp2[12]=32;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

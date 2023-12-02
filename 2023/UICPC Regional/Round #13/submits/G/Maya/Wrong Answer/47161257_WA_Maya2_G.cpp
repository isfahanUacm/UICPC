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
#define int ll 

void solve() {
	int l, m; cin >> l >> m;	
	string name = "", str;
	int p = 0, c = 0, t = 0, r = 0;
	cin.ignore();
	vector<pair<string, int>> vc;
	for (int i = 0; i < m; ++i) {
		getline(cin, str);
		reverse(all(str));
		int j = 0, nn = sz(str);
		string tmp = "";
		while (j < nn) {
			if (str[j] == ',') { 
				reverse(all(tmp));
				r = stoi(tmp);
				break;
			}
			tmp += str[j];
			j++;
		}
		j++;
		tmp = "";
		while (j < nn) {
			if (str[j] == ',') { 
				reverse(all(tmp));
				t = stoi(tmp);
				break;
			}
			tmp += str[j];
			j++;
		}
		j++;
		tmp = "";
		while (j < nn) {
			if (str[j] == ',') { 
				reverse(all(tmp));
				c = stoi(tmp);
				break;
			}
			tmp += str[j];
			j++;
		}
		j++;
		tmp = "";
		while (j < nn) {
			if (str[j] == ',') {
				reverse(all(tmp));
				p = stoi(tmp);
				break;
			}
			tmp += str[j];
			j++;
		}
		j++;
		name = "";
		while (j < nn) {
			name += str[j];
			j++;
		}
		reverse(all(name));
		dbg(name, p, c, t, r);

		bool can = true;

		double x = l*1.0 / c*1.0;
		dbg(x);

		int meg = (ceil(x/t))-1;
		
		double kol = x + meg*r*1.0;
		dbg(kol);

		double kr = kol + r*1.0;
		if (kr > 10080) can = false;
		if (can) {
			if (vc.empty()) vc.pb({name, p});
			else if (vc.back().S == p) vc.pb({name, p});
			else if (vc.back().S > p) {
				vc.clear();
				vc.pb({name, p});
			}
		}
	}
	if(vc.empty()) cout << "no such mower" << nl;
	for (auto x : vc) {
		cout << x.F << nl;
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

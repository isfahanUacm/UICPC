/**
 * created by: poconut
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 2e9
#define nl " \n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld; typedef pair<int, int> pii; typedef long long ll; typedef unsigned long long ull; typedef long double ld;
#ifdef ONPC
#define fastio()
#define arrdebug(x, s) cerr<< #x << ": ";_print(a, s); cerr << endl;
#define debug(x) cerr << #x <<": "; _print(x); cerr << endl;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x)
#endif
void _print(const int& t) {cerr << t;} void _print(const ll& t) {cerr << t;} void _print(const char& t) {cerr << t;} void _print(const string& t) {cerr << t;} void _print(const ld& t) {cerr << t;} void _print(const double& t) {cerr << t;}
template <class T, class V> void _print(const pair<T, V>& p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(const vector<T>& v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T>& v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(const multiset<T>& v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(const map<T, V>& v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(const T& a, int s) { cerr << "[ "; for (auto i: a) { if(!s--) break;_print(i); cerr << " "; } cerr << "]"; }
/*******************************************************************************/


const int maxn=1e5+10;
int a[maxn];

int solve() {
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a, a+n, greater<int>());
    for (int i=0; i<n; i++) a[i] -= n-i-1;
    int mx = -1;
    for (int i=0; i<n; i++) mx = max(mx, a[i]);
    debug(mx);
    cout << n+mx+1 << nl;


	return 0;
}

int main() {
    fastio();

	int T = 1;
	//cin >> T;
	while (T--) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
        cout<<"__________"<<endl;
		#endif
	}
	#ifdef ONPC
    cerr<<endl<<"finished in "<<clock()*1.0/CLOCKS_PER_SEC<<" sec"<<endl;
	#endif
    return 0;
}



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

const ll N = 1e7;
int solve() {
    ld x; cin >> x;
    vector<ll> vec;
    for (ll i=0; i<N; i++) {
        string s = to_string(i);
        s += s[0];
        s[0] = '0';
        int t = stoi(s);
        if (abs((t*1.0)/i -x) <= 1e-10) {
            vec.pb(i);
        }
    }
    vector<ll> v2;
    for (ll tmp: vec) {
        int len = floor(log10(tmp)*1.0)+1;
        ll t = tmp;
        for (int i=0; i<(8/len)-1; i++) {
            t = pow(10, len)*tmp + tmp;
            v2.pb(t);
        }
    }
    set<ll> st;
    for (ll tmp:vec) st.insert(tmp);
    for (ll tmp:v2) {
        if (st.count(tmp)==0) {
            vec.pb(tmp);
            st.insert(tmp);
        }
    }

    sort(all(vec));
    if (sz(vec) > 0) {
        for (ll tmp: vec) {
            if (tmp < N*N)
            cout << tmp << nl;
        }
    } else {
        cout << "No solution" << nl;
    }

    /*
    */

	return 0;
}

int main() {
    fastio();

	int T = 1;
	cin >> T;
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



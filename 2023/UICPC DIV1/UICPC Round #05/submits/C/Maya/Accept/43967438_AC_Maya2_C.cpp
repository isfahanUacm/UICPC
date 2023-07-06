/**
 * created by: poconut(MPouya)
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
#define arrdebug(x, s) cout<< #x << ": ";_print(x, s); cout << endl;
#define debug(x) cout << #x <<": "; _print(x); cout << endl;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x)
#define arrdebug(x, s)
#endif
void _print(const int& t) {cout << t;} void _print(const ll& t) {cout << t;} void _print(const char& t) {cout << t;} void _print(const string& t) {cout << t;} void _print(const ld& t) {cout << t;} void _print(const double& t) {cout << t;}
template <class T, class V> void _print(const pair<T, V>& p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(const vector<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const multiset<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(const map<T, V>& v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const T& a, int s) { cout << "[ "; for (auto i: a) { if(!s--) break;_print(i); cout << " "; } cout << "]"; }
/*******************************************************************************/


int solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pii> v;
    for (int i=2; 1ll*i*i<=n; i++) {
        if (n%i==0) {
            int cnt = 0;
            while (n%i==0) {
                cnt++; n /= i;
            }
            v.pb(mp(i, cnt));
        }
    }
    if (n>1) v.pb(mp(n, 1));
    debug(v);
    int cnt = 0;
    for (pii p: v) cnt += p.ss;
    debug(cnt);

    int ans;
    if (sz(v)>=3) {
        ans = 3;
    } else if (sz(v)==2) {
        int t1 = v[0].ss, t2 = v[1].ss;
        if (abs(t1-t2)>=2) {
            ans = 3;
        } else if (abs(t1-t2)==1) {
            ans = 1;
        } else if (t1==t2) {
            ans = 2;
        }
    } else if (sz(v)==1) {
        if (cnt%2==0) ans = 2;
        else ans = 1;

    }
    if (ans==3) {
        cout << "tie" << nl;
    } else if (ans==1) {
        cout << (s=="Alice"?"Alice":"Bob") << nl;
    } else if (ans==2) {
        cout << (s=="Bob"?"Alice":"Bob") << nl;
    }
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
    cout<<endl<<"finished in "<<clock()*1.0/CLOCKS_PER_SEC<<" sec"<<endl;
	#endif
    return 0;
}



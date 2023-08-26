/**
 * created by: poconut(MPouya)
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define INF 2e9
#define nl "\n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld; typedef pair<int, int> pii; typedef long long ll; typedef unsigned long long ull; typedef long double ld;
#ifdef ONPC
#define fastio()
#define arrdebug(x, s) cout<< #x << ": ";_print(x, s); cout << endl;
#define debug(x) cout << #x <<": "; _print(x); cout << endl;
#define LINE cout << "__________" << endl;
#define TIME cout<<endl<<"finished in "<<clock()*1.0/CLOCKS_PER_SEC<<" sec"<<endl;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x)
#define arrdebug(x, s)
#define LINE
#define TIME
#endif
void _print(const int& t) {cout << t;} void _print(const ll& t) {cout << t;} void _print(const char& t) {cout << t;} void _print(const string& t) {cout << t;} void _print(const ld& t) {cout << t;} void _print(const double& t) {cout << t;}
template <class T> void _print(const T& a, int s) { cout << "[ "; for (auto i: a) { if(!s--) break;_print(i); cout << " "; } cout << "]"; }
template <class T, class V> void _print(const pair<T, V>& p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T, class V> void _print(const map<T, V>& v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const vector<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const set<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(const multiset<T>& v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(queue<T>& q) { cout << "[ "; T x; stack<T> tmp; for (int i=0; i<q.size(); i++) { x = q.front(); q.pop(); tmp.push(x); q.push(x); } while (!tmp.empty()) { x = tmp.top(); tmp.pop(); _print(x); cout << " "; } cout << "]"; }
template <class T> void _print(stack<T>& s) { cout << "[ "; stack<T> tmp; T x; while (!s.empty()) { x = s.top(); s.pop(); tmp.push(x); } while (!tmp.empty()) { x = tmp.top(); tmp.pop(); _print(x); cout << " "; s.push(x); } cout << "]"; }
template <class T> void _print(deque<T>& dq) { cout << "[ "; T x; stack<T> tmp; for (int i=0; i<dq.size(); i++) { x = dq.front(); _print(x); cout << " "; dq.pop_front(); dq.pb(x); } cout << "]"; }
/*******************************************************************************/

const int mxn = 1000+10;
char a[mxn][mxn];
ll dp[mxn][mxn];
vector<int> g[mxn*mxn];
bool vis[mxn*mxn];
const ll mod = (1ll<<31)-1;

void dfs(int x) {
    vis[x] = true;
    for (int u: g[x]) {
        if (!vis[u]) {
            dfs(u);
        }
    }

}
void solve() {
    int n; cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i+1<=n-1 && a[i][j] == '.' && a[i+1][j]=='.') {
                g[n*i+j].pb(n*(i+1)+j);
                g[n*(i+1)+j].pb(n*i+j);
            }
            if (j+1<=n-1 && a[i][j] == '.' && a[i][j+1]=='.') {
                g[n*i+j].pb(n*i+j+1);
                g[n*i+j+1].pb(n*i+j);
            }
        }
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==0 && j==0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 0;
            if (a[i][j]=='.') {
                dp[i][j] = 0;
                if (i-1>=0) {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
                if (j-1>=0) {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    dfs(0);
    ll ans = dp[n-1][n-1];
    /*
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cout << dp[i][j] << " \n"[j==n-1];
            */
    if (ans>0) {
        cout << ans << nl;
    } else {
        cout << (vis[n*(n-1)+n-1]?"THE GAME IS A LIE":"INCONCEIVABLE") << nl;
    }


}

int main() {
    fastio();
	int T = 1;
	//cin >> T;
	while (T--) {
        solve();
        LINE
	}
    TIME
    return 0;
}



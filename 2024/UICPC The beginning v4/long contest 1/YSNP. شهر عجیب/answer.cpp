/**
 * created by: poconut(MPouya)
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define INF 2e9
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ar array
#define lb lower_bound
#define ub upper_bound
#define tostr to_string
typedef string str; typedef long double ld; typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef vector<pii> vpii; typedef vector<pll> vpll;
#ifdef ONPC
#include "/home/pouya/cp.cpp"
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(...)
#define arrdebug(...)
#define delay()
#define LINE
#define TIME
#endif
/*******************************************************************************/

const int N = 1e5+5;
vector<int> g[N], tp;
int n, m, vis[N], cnt[N];
void dfs(int u) {
    vis[u] = 1;
    for (int v: g[u]) {
        if (!vis[v])
            dfs(v);
    }
    tp.pb(u);

}
void solve() {
    cin >> n >> m;
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].pb(v);
    }
    fill(cnt+1, cnt+n+1, 0);
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    cnt[n] = 1;
    for (int i=0; i<n; i++) {
        int u = tp[i];
        for (int x: g[u]) {
            cnt[u] = (cnt[u]+cnt[x])%MOD;
        }
    }
    cout << cnt[1] << nl;

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


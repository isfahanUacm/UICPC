#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] int tc) {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i=0; i<m; i++) {
        int u, v; cin >> u  >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    const int inf = 1e9+5;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        queue<int> q;
        vector<int> d(n, inf), par(n, -1), c(n);
        d[i] = 0;
        int color = 0;
        for (int v: g[i]) {
            c[v] = ++color;
            d[v] = 1;
            par[v] = i;
            q.push(v);
        }
        int cnt = inf;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: g[u]) {
                if (d[v] == inf) {
                    par[v] = u;
                    d[v] = d[u]+1;
                    c[v] = c[u];
                    q.push(v);
                } else if (v != par[u] && c[v] != c[u]) {
                    cnt = min(cnt, d[u]+d[v]+1);
                }
            }
        }
        if (cnt == inf) {
            ans += (i+1);
        } else {
            ans += cnt*(i+1);
        }
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}

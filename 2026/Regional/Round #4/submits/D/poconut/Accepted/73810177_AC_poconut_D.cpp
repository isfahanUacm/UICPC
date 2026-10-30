#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
#ifdef LOCAL
#include "local.hpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] uint32_t tc) {
    int n, m; cin >> n >> m;
    int a, b, c; cin >> a >> b >> c;
    a--, b--, c--;
    vector<vector<int>> g(n);
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    const int inf = 1e9+5;
    vector<int> d(n, inf);
    auto dfs = [&] (auto&& self, int u, int par=-1) -> void {
        for (int v: g[u]) if (v != par) {
            d[v] = d[u]+1;
            self(self, v, u);
        }
    };
    d[c] = 0;
    dfs(dfs, c);

    int id = 0;
    vector<int> bel(n, -1);
    auto dfs1 = [&] (auto&& self, int u, int par=-1) -> void {
        bel[u] = id;
        for (int v: g[u]) if (v != par) {
            self(self, v, u);
        }
    };
    for (int i=0; i<n; i++) {
        if (bel[i] == -1) {
            dfs1(dfs1, i);
            id++;
        }
    }

    if (bel[a] == bel[b]) {
        if (bel[a] == bel[c]) {
            if (d[a] == d[b]) {
                cout << "Tie" << nl;
            } else if (d[a] < d[b]) {
                cout << "Alice" << nl;
            } else {
                cout << "Bob" << nl;
            }
        } else {
            cout << "Alice" << nl;
        }
    } else {
        if (bel[c] == bel[a]) {
            cout << "Alice" << nl;
        } else if (bel[c] == bel[b]) {
            if (d[b] == 1) {
                cout << "Tie" << nl;
            } else {
                cout << "Alice" << nl;
            }
        } else {
            cout << "Tie" << nl;
        }
    }
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



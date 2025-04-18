#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> u(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i];
        u[i]--;
        if (u[i] != -1) {
            adj[u[i]].push_back(i);
        }
    }

    vector<int> sz(n);
    auto dfs = [&](auto &&self, int v) -> void {
        sz[v] = 1;
        for (auto u : adj[v]) {
            self(self, u);
            sz[v] += sz[u];
        }
    };

    int mx = 0, mxi = 0;
    for (int i = 0; i < n; i++) {
        if (u[i] == -1) {
            dfs(dfs, i);
            if (sz[i] > mx) {
                mx = sz[i];
                mxi = i;
            }
        }
    }

    cout << mxi + 1 << ' ' << mx << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

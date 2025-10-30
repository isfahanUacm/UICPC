#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n % 2) {
        cout << "impossible\n";
        return;
    }

    vector<int> color(n);
    int blue = 0;
    auto dfs = [&](auto&& self, int v) -> void {
        if (blue < n / 2) {
            color[v] = 1;
            blue++;
        } else {
            color[v] = 2;
        }
        for (auto u : adj[v]) {
            if (!color[u]) {
                self(self, u);
            }
        }
    };
    dfs(dfs, 0);
    if (count(color.begin(), color.end(), 2) == 0) {
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                dfs(dfs, i);
                break;
            }
        }
    }
    
    if (count(color.begin(), color.end(), 0) == 0) {
        for (int i = 0; i < n; i++) {
            cout << (color[i] == 1 ? 'b' : 'r') << '\n';
        }
        return;
    }
    cout << "impossible\n";
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

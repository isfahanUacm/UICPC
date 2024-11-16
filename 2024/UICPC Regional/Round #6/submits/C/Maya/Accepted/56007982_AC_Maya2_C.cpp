#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
    }

    // An order of vertices in DAG that every edge leads from 
    // the vertex with a smaller index to a vertex with a larger one.
    vector<bool> vis(n);
    vector<int> order;
    order.reserve(n);
    auto dfs = [&](auto &&self, int v) -> void {
        vis[v] = true;
        for (auto [u, w] : adj[v]) {
            if (!vis[u]) {
                self(self, u);
            }
        }
        order.push_back(v);
    };
    auto topological_sorting = [&]() -> void {
        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                dfs(dfs, v);
            }
        }
        reverse(order.begin(), order.end());
    };
    topological_sorting();

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        int v = order[i];
        for (auto [u, w] : adj[v]) {
            d[u] = max(d[u], d[v] + w);
        }
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
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

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    constexpr int INF = 1e9;
    vector<int> dist(n, INF), par(n, -1);
    auto bfs = [&](int s) -> void {
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : adj[v]) {
                if (dist[v] + 1 < dist[u]) {
                    q.push(u);
                    dist[u] = dist[v] + 1;
                    par[u] = v;
                }
            }
        }
    };
    bfs(c);

    if (a == b) {
        cout << "Tie\n";
    } else if (dist[a] == 0) {
        cout << "Alice\n";
    } else if (dist[b] == 0) {
        cout << "Bob\n";
    } else if (dist[a] != INF && dist[b] != INF) {
        if (dist[a] < dist[b]) {
            cout << "Alice\n";
        } else if (dist[a] > dist[b]) {
            cout << "Bob\n";
        } else {
            cout << "Tie\n";
        }
    } else if (dist[a] == INF && dist[b] == INF) {
        vector<bool> vis(n);
        auto dfs = [&](auto&& self, int v) -> void {
            vis[v] = true;
            for (auto u : adj[v]) {
                if (!vis[u]) {
                    self(self, u);
                }
            }
        };
        dfs(dfs, a);
        if (vis[b]) {
            cout << "Alice\n";
        } else {
            cout << "Tie\n";
        }
    } else if (dist[a] == INF) {
        if (dist[b] == 1) {
            cout << "Tie\n";
        } else {
            cout << "Alice\n";
        }
    } else {
        if (dist[a] == 1) {
            cout << "Tie\n";
        } else {
            cout << "Bob\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

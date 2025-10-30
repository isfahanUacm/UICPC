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

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }

    if (n % 2 || n > 1e3 + 9) {
        cout << "impossible\n";
        return;
    }

    vector<vector<int>> adj_mat(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }


    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && !adj_mat[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> color(n, -1);
    vector<vector<int>> c(2);
    int blue = 0, red = 0;
    auto is_bipartite = [&]() -> bool {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (blue < red) {
                    color[i] = 0;
                    blue++;
                } else {
                    color[i] = 1;
                    red++;
                }
                c[color[i]].push_back(i);
                q.push(i); 
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (auto u : adj[v]) {
                        if (color[u] == -1) {
                            color[u] = color[v] ^ 1;
                            if (color[i] == 0) {
                                blue++;
                            } else {
                                red++;
                            }
                            c[color[u]].push_back(u);
                            q.push(u);
                        } else if (color[u] == color[v]) {
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    };

    if (is_bipartite() && blue == red) {
        for (int i = 0; i < n; i++) {
            cout << (color[i] == 0 ? 'b' : 'r') << '\n';
        }
    } else {
        cout << "impossible\n";
    }
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

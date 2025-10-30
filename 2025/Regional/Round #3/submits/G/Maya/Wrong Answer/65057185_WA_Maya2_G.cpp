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

    if (n % 2 || n > 4e3) {
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

    vector<bool> vis(n);
    vector<int> color(n, -1);
    auto dfs = [&](auto&& self, int v) -> void {
        color[v] ^= 1;
        vis[v] = true;
        for (auto u : adj[v]) {
            if (!vis[u]) {
                self(self, u);
            }
        }
    };

    vector<pair<int, int>> nums;
    auto is_bipartite = [&]() -> bool {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            int blue = 0, red = 0;
            if (color[i] == -1) {
                color[i] = 0;
                blue++;
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
                            q.push(u);
                        } else if (color[u] == color[v]) {
                            return false;
                        }
                    }
                }
                nums.emplace_back(i, abs(blue - red));
            }
        }
        return true;
    };

    if (is_bipartite()) {
        vis.assign(n, 0);
        int n1 = nums.size(), n2 = 0;
        for (auto [i, sz] : nums) {
            n2 += sz;
        }
        if (n2 % 2) {
            cout << "impossible\n";
            return;
        }
        n2 /= 2;

        vector par(n1 + 1, vector<int>(n2 + 1, -1));
        par[0][0] = 0;
        for (int i = 1; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (par[i - 1][j] != -1) {
                    par[i][j] = 0;
                } else if (j - nums[i - 1].second >= 0 && par[i - 1][j - nums[i - 1].second] != -1) {
                    par[i][j] = 1;
                }
            }
        }
        if (par[n1][n2] == -1) {
            cout << "impossible\n";
            return;
        }

        vector<int> blues(n1);
        int sz = n2;
        for (int i = n1; i >= 1; i--) {
            if (par[i][sz] == 1) {
                sz -= nums[i - 1].second;
                blues[i - 1] = 1;
            }
        }
        queue<int> q;
        for (int i = 0; i < n1; i++) {
            int blue = 0, red = 0;
            int x = nums[i].first;
            color[x] = 0;
            blue++;
            q.push(x); 
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
                        q.push(u);
                    }
                }
            }
            if (blues[x] && blue < red) {
                dfs(dfs, x);
            } else if (blues[x] == 0 && red < blue) {
                dfs(dfs, x);
            }
        }
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

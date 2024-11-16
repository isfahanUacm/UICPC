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

    vector<string> g(n + 1);
    cin >> g[0];
    for (int i = 0; i < n + 1; i++) {
        getline(cin, g[i]);
    }

    constexpr int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
    constexpr int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
    const string move = "UDLR";
    auto check = [&](int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<vector<int>> adj(n * m);
    vector vis(n, vector<bool>(m));
    vis[0][0] = true;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            int px = x + (dx[i] == 1 ? 1 : 0), py = 2 * y + 1 + dy[i];
            px += bool(dy[i]);
            if (x == 0 && y == 4) {
                dbg(px, py);
            }
            if (check(xx, yy) && g[px][py] == ' ' && !vis[xx][yy]) {
                vis[xx][yy] = true; 
                q.emplace(xx, yy);
                adj[x * m + y].push_back(xx * m + yy);
            }
        }
    }

    int qu;
    cin >> qu;
    vector<int> qq(qu);
    for (int i = 0; i < qu; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        qq[i] = x * m + y;
    }

    n *= m;
    int timer, l;
    vector<int> tin, tout, h(n);
    vector<vector<int>> up;
    auto dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p) {
                h[u] = h[v] + 1;
                self(self, u, v);
            }
        }
        tout[v] = ++timer;
    };

    auto is_ancestor = [&](int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    auto lca = [&](int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    };

    auto preprocess = [&](int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(dfs, root, root);
    };
    preprocess(0);

    int64_t ans = 0;
    for (int i = 0; i < qu - 1; i++) {
        int ll = lca(qq[i], qq[i + 1]);
        ans += h[qq[i]] + h[qq[i + 1]] - 2 * h[ll];
    }
    cout << ans << '\n';
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

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

vector<vector<int>> adj;
int farthest(int s, int n, vector<int> &par) {
    par.assign(n, -1);
    vector<bool> vis(n);

    queue<int> q; 
    q.push(s);
    vis[s] = 1;;
    int last = s;
    while (!q.empty()) {
        int v = q.front(); 
        q.pop();

        for (int u : adj[v]) {
            if (!vis[u]) {
                par[u] = v;
                q.push(u); 
                vis[u] = 1;
            }
        }
        last = v;
    }
    return last;
}

void solve() {
    int n;
    cin >> n;

    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n, -1);
    int x = farthest(0, n, par);
    int y = farthest(x, n, par);
    dbg(x, y, par);

    int d = 0, yy = y;
    while (yy != x) {
        yy = par[yy];
        d++;
    }

    if (d < 3) {
        cout << "NO\n";
        return;
    }

    int y1 = par[y], y2 = par[y1];;

    vector<int> ans;
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int v) -> void {
        ans.push_back(v);
        vis[v] = true;
        for (auto u : adj[v]) {
            if (!vis[u]) {
                self(self, u);
            }
        }
    };
    vis[y1] = true;
    dfs(dfs, y2);
    dfs(dfs, y1);

    cout << "YES\n";
    for (auto v : ans) {
        cout << v + 1 << " \n"[v == ans.back()];
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

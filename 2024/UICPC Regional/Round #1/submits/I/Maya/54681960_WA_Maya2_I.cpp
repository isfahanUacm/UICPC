#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl endl

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<char> vis(n);
    auto dfs = [&] (auto&& self, int u) -> void {
        vis[u] = 1;
        for (int v: g[u]) {
            if (!vis[v]) {
                self(self, v);
            }
        }
    };
    dfs(dfs, 0);
    set<int> s;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (vis[i]) {
            cout << i+1 << ' ';
        } else {
            s.insert(i);
            cnt++;
        }
    }
    int prev = -1, now = *s.begin();
    while (cnt) {
        if (prev != -1) {
            for (int v: g[prev]) {
                if (!vis[v]) {
                    s.insert(v);
                }
            }
        }
        s.erase(now);
        vis[now] = 1;
        cout << now+1 << ' ';
        cnt--;
        for (int v: g[now]) {
            s.erase(v);
        }
        prev = now;
        now = *s.begin();
    }
    cout << "\n";
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

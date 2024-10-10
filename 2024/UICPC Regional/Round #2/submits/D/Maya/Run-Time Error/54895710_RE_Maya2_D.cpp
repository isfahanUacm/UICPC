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

    vector<vector<pair<int, int64_t>>> adj(n);
    for (int i = 1; i < n; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        adj[v].emplace_back(i, w);
    }
    
    vector<int64_t> dist(n), times;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        const int INF = 1e9;
        int mn_w = INF;
        for (auto [u, w] : adj[v]) {
            if (w < mn_w) {
                mn_w = w;
            }
        }
        for (auto [u, w] : adj[v]) {
            dist[u] = dist[v] + mn_w + (w - mn_w) * 2;
            q.emplace(u);
        }
        if (adj[v].size() == 0) {
            times.push_back(dist[v]);
        }
    }
    sort(times.begin(), times.end());

    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        int ans = upper_bound(times.begin(), times.end(), t) - times.begin();
        cout << ans << '\n';
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

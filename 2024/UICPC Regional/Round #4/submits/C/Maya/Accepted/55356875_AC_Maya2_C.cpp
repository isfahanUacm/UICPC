#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> w(k);
    for (int i = 0; i < k; i++) {
        cin >> w[i];
        w[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    constexpr int INF = 1e9;
    auto bfs = [&](int s) -> vector<int> {
        vector<int> dist(n, INF);
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
                }
            }
        }
        return dist;
    };

    auto d1 = bfs(0);
    auto d2 = bfs(n - 1);

    int64_t sum = 0;
    for (int i = 0; i < k; i++) {
        sum += d2[w[i]];
    }

    int64_t up = (int64_t)(k - 1) * d1[n - 1], down = k - 1;
    for (int i = 0; i < k; i++) {
        up = min(up, sum - d2[w[i]] + (int64_t)(k - 1) * d1[w[i]]);
    }

    int64_t g = gcd(up, down);
    up /= g;
    down /= g;
    cout << up << '/' << down << '\n';
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

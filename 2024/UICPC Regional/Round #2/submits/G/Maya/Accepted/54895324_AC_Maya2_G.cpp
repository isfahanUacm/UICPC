#include<bits/stdc++.h>
#ifndef LOCAL
#define LINE
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#else
#define LINE cerr << "----------" << nl;
#define fastio
#endif
using namespace std;
using ll = long long; using ld = long double;
#define nl '\n'
#define arr array
#define pb push_back

constexpr ll INF = 1e18;
#define int long long

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector adj(n, vector<arr<int, 3>>());
    for (int i=0; i<m; i++) {
        int u, v, c, w; cin >> u >> v >> c >> w;
        u--, v--;
        adj[u].pb({v, c, w});
        adj[v].pb({u, c, w});
    }

    auto dijkstra = [&](int s, ll md) -> bool {
        vector<ll> dist(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[s] = 0;
        pq.emplace(dist[s], s);
        while (!pq.empty()) {
            auto [dist_v, v] = pq.top();
            pq.pop();

            if (dist_v != dist[v]) {
                continue;
            }
            for (auto [u, c, w] : adj[v]) {
                if (w <= md && dist[v] + c < dist[u]) {
                    dist[u] = dist[v] + c;
                    pq.emplace(dist[u], u);
                }
            }
        }
        return dist[n-1] < k;
    };
    ll hi = INF, lo = -1, md;
    while (hi - lo > 1) {
        md = (hi + lo) / 2;
        bool b = dijkstra(0, md);
        if (b) {
            hi = md;
        } else {
            lo = md;
        }
    }
    if (hi == INF) {
        cout << -1 << nl;
    } else {
        cout << hi << nl;
    }
}

int32_t main() {
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}


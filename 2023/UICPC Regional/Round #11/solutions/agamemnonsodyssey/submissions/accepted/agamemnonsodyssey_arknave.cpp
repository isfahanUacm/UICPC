#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 2e5 + 5;
vector<pair<int, int64_t>> tree[MAXN];
int64_t dist[2][MAXN];

void dfs(int k, int u, int p = -1) {
    for (auto [v, w] : tree[u]) {
        if (v == p) {
            continue;
        }

        dist[k][v] = dist[k][u] + w;
        dfs(k, v, u);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    int64_t total = 0;
    for (int i = 1; i < n; ++i) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;

        --u; --v;

        total += w;

        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    if (k != 1) {
        cout << total << '\n';
        return 0;
    }

    // find the diameter of the tree
    dfs(0, 0);
    int src = max_element(dist[0], dist[0] + n) - dist[0];
    dfs(1, src);
    int64_t ans = *max_element(dist[1], dist[1] + n);

    cout << ans << '\n';

    return 0;
}

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9 + 7;

bool find(const vector<vector<int>>& graph, vector<int>& match, vector<bool>& seen, int j) {
    if (match[j] == -1) return true;

    seen[j] = true;
    int di = match[j];
    for (auto& e : graph[di]) {
        if (!seen[e] and find(graph, match, seen, e)) {
            match[e] = di;
            return true;
        }
    }

    return false;
}

int dfs_matching(const vector<vector<int>>& graph, int n, int m) {
    vector<int> match;
    vector<bool> seen;
    match.assign(m, -1);
    for (int i = 0; i < n; ++i) {
        seen.assign(m, 0);
        for (auto& j : graph[i]) {
            if (find(graph, match, seen, j)) {
                match[j] = i;
                break;
            }
        }
    }

    return m - count(begin(match), end(match), -1);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        dist[u][v] = min(dist[u][v], w);
    }

    // What a meme
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
            }
        }
    }

    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
            }
        }
    }

    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
            }
        }
    }

    vector<tuple<int, int, int>> orders;
    vector<vector<int>> match_graph(k);
    for (int i = 0; i < k; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u; --v;
        for (int j = 0; j < i; ++j) {
            auto [up, vp, tp] = orders[j];
            // j -> i
            if (tp + dist[up][vp] + dist[vp][u] <= t) {
                match_graph[j].push_back(i);
            }

            if (t + dist[u][v] + dist[v][up] <= tp) {
                match_graph[i].push_back(j);
            }
        }
        orders.emplace_back(u, v, t);
    }

    cout << (k - dfs_matching(match_graph, k, k)) << '\n';

    return 0;
}

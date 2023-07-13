#include <iostream>
#include <vector>

#define MAXN (7*7*7)

#define INF (1ll<<60)

using namespace std;

typedef long long ll;

struct edge {
    int u, v;
    ll d;
};


int main() {
    int cindex[256];
    const char *colours = "ROYGBIV";
    ll g[MAXN][MAXN];
    vector<edge> streets[7];

    for (int i = 0; i < 7; ++i) cindex[colours[i]] = i;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = (i==j?0:INF);

    for (int i = 0; i < m; ++i) {
        edge e;
        char c;
        cin >> e.u >> e.v >> e.d >> c;
        --e.u; --e.v;
        g[e.u][e.v] = g[e.v][e.u] = e.d;
        streets[cindex[c]].push_back(e);
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    // dp[v][k] == distance to go if we still need colours in bitset k
    ll dp[MAXN][1<<7];

    for (int k = 0; k < (1<<7); ++k)
        for (int v = 0; v < n; ++v)
            if (k == 0) dp[v][k] = g[v][0];
            else {
                dp[v][k] = INF;
                for (int clr = 0; clr < 7; ++clr)
                    if (k & (1<<clr))
                        for (const auto& e : streets[clr]) {
                            dp[v][k] = min(dp[v][k], g[v][e.u] + e.d + dp[e.v][k^(1<<clr)]);
                            dp[v][k] = min(dp[v][k], g[v][e.v] + e.d + dp[e.u][k^(1<<clr)]);
                        }
            }
    cout << dp[0][(1<<7)-1] << endl;

    return 0;
}

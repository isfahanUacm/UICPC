#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int INF32 = 1E9;
constexpr i64 INF64 = 1E18;
constexpr int MOD = 1e9 + 7;

#define sz(x) (int)x.size()
#define F first
#define S second

const int N = 2e5 + 1;
bool tst = true;

vector<vector<int>> g;
vector<i64> e, dist;

i64 dfs(int u, int par = -1, i64 d = 0) {
    dist[u] = min(dist[u], d);
    i64 ans = e[u] - dist[u];
    for (int v : g[u]) {
        ans = min(ans, dfs(v, u, d + 1));
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        tst = false;
        return;
    }

    g.assign(n, vector<int>());
    e.assign(n, INF32);
    dist.assign(n, INF32);

    dist[0] = 0;
    for (int i = 1; i < n; i++) {
        int p, u;
        cin >> p >> u;

        g[p - 1].push_back(i);
        e[i] = u;
    }

    vector<int> ord;
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.push({0, 0});
    int T = 0;
    bool valid = true;
    dfs(0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d - T + 1 < 0) {
            valid = false;
            break;
        }

        ord.push_back(u);
        T += 1;

        for (int v : g[u]) {
            int x = dfs(v, u);
            pq.push({x, v});
        }
    }

    if (!valid) {
        cout <<  "no" << endl;
    } else {
        cout << "yes" << endl;
        for (int u : ord) {
            if (u != 0) {
                cout << u + 1 << " ";
            }
        }
        cout << endl;
    }

    g.clear();
    e.clear();
    dist.clear();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (tst)
        solve();

    return 0;
}
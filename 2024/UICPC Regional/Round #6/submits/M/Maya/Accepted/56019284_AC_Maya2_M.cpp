#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int c;
    vector<int> par, sz, w, h;
    vector<vector<int>> children;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        c = n;
        par.resize(n);
        w.resize(n);
        h.resize(n);
        children.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int find(int a) {
        return (par[a] == a ? a : find(par[a]));
    }
    void merge(int a, int b, int ww) {
        if ((a = find(a)) == (b = find(b))) {
            return;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        for (auto u : children[a]) {
            children[b].push_back(u);
            h[u]++;
        }
        h[a]++;
        children[b].push_back(a);
        par[a] = b;
        w[a] = ww;
        sz[b] += sz[a];
        c--;
    }
    int64_t dis(int a, int b) {
        int64_t res = 0;
        if (h[a] > h[b]) {
            swap(a, b);
        }
        while (h[a] != h[b]) {
            res = max<int64_t>(res, w[b]);
            b = par[b];
        }
        while (a != b) {
            res = max<int64_t>({res, w[a], w[b]});
            a = par[a];
            b = par[b];
        }
        return res;
    }
};

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 3>> a(n * m);
    vector g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            a[i * m + j] = {g[i][j], i, j};
        }
    }
    
    constexpr int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
    constexpr int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
    const string move = "UDLR";
    auto check = [&](int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    sort(a.begin(), a.end());
    DSU dsu(n * m);
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < 4; j++) {
            int x = a[i][1], y = a[i][2];
            int xx = x + dx[j], yy = y + dy[j];
            if (check(xx, yy) && g[xx][yy] <= g[x][y]) {
                dsu.merge(x * m + y, xx * m + yy, g[x][y]);
            }
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        cout << max<int64_t>({dsu.dis(x1 * m + y1, x2 * m + y2), g[x1][y1], g[x2][y2]}) << '\n';
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

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

struct DSU {
    int c;
    vector<int> par, sz, h, mn;
    vector<vector<int>> child;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        c = n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        mn.assign(n, 0);
        h.assign(n, 0);
        child.resize(n);
    }

    int find(int a) {
        return (par[a] == a ? a : find(par[a]));
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void merge(int a, int b, int time) {
        if ((a = find(a)) == (b = find(b))) {
            return;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        par[a] = b;
        sz[b] += sz[a];
        mn[a] = time;
        for (auto u : child[a]) {
            child[b].push_back(u);
            h[u]++;
        }
        child[b].push_back(a);
        h[a]++;
        c--;
    }
    int query(int a, int b) {
        if (!same(a, b)) {
            return -1;
        }
        if (h[a] < h[b]) {
            swap(a, b);
        }
        int mx = 0;
        while (h[a] != h[b]) {
            mx = max(mx, mn[a]);
            a = par[a];
        }
        while (a != b) {
            mx = max(mx, mn[a]);
            mx = max(mx, mn[b]);
            a = par[a];
            b = par[b];
        }
        return mx;
    }
    int size(int a) {
        return sz[find(a)];
    }
    int count() {
        return c;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int op, u ,v;
        cin >> op >> u >> v;;
        u--, v--;
        if (op == 1) {
            dsu.merge(u, v, i + 1);
        }
        else {
            cout << dsu.query(u, v) << '\n';
        }
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

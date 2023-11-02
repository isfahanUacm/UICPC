/*
   Intentionally being a quite inefficient with the use of dynamic arrays
   that go out of scope a lot. If this runs fast enough, then any reasonable
   approach with the right algorithm should be fast enough.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;
typedef vector<ll> vll;

struct edge {
    int u, v;
    ll w;
    edge (int uu = 0, int vv = 0, ll ww = 0) : u(uu), v(vv), w(ww) {}
    bool operator<(const edge& rhs) const {
        return w > rhs.w;
    }
};
typedef vector<vector<edge>> vve;

void dijkstra(int s, const vve& g, vll& d) {
    priority_queue<edge> pq;
    d.assign(g.size(), -1);
    pq.push(edge(-1, s, 0));

    while (!pq.empty()) {
        edge curr = pq.top();
        pq.pop();

        if (d[curr.v] != -1) continue;
        d[curr.v] = curr.w;

        for (auto nxt : g[curr.v]) {
            nxt.w += curr.w;
            pq.push(nxt);
        }
    }
}

bool dfs(int i, vi& m, const vvi& bip, vi& seen) {
    if (seen[i]) return false;
    seen[i] = 1;

    for (auto j : bip[i])
        if (m[j+bip.size()] == -1 || dfs(m[j+bip.size()], m, bip, seen)) {
            m[j+bip.size()] = i; m[i] = j+bip.size();
            return true;
        }

    return false;
}

bool augment(const vvi& bip, vi& m) {
    vi seen(bip.size(), false);

    for (int i = 0; i < bip.size(); ++i)
        if (m[i] == -1 && dfs(i, m, bip, seen)) return true;
    return false;
}

int match(const vvi& bip) {
    int cnt = 0;
    vi m(2*bip.size(), -1);
    while (augment(bip, m)) ++cnt;

    //for (auto x : m) cout << x << ' '; cout << endl;

    return cnt;
}

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    vll cl(c);
    for (auto& x : cl) cin >> x;

    vve g(n);
    while (m--) {
        edge e;
        cin >> e.u >> e.v >> e.w;
        g[e.u].push_back(e);
    }

    vll d0;
    vvi bip(c);

    dijkstra(0, g, d0);
    for (int i = 0; i < c; ++i) {
        vll d;
        dijkstra(cl[i], g, d);
        for (int j = 0; j < c; ++j)
            if (i != j && d[cl[j]] != -1 && d0[cl[i]] + d[cl[j]] == d0[cl[j]])
                bip[i].push_back(j);
    }

    // for (int i = 0; i < bip.size(); ++i) {
    //     cout << cl[i];
    //     for (int j = 0; j < bip[i].size(); ++j) cout << ' ' << cl[bip[i][j]];
    //     cout << endl;
    // }

    cout << c-match(bip) << endl;

    return 0;
}

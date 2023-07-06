#include <iostream>
#include <vector>
#include <queue>

#define INFTY 10000000000000ll

using namespace std;

typedef long long ll;

struct edge {
    ll u, v, c;
    edge(ll uu = 0, ll vv = 1, ll cc = 0) :
        u(uu), v(vv), c(cc) {}
};

vector<edge> edges;
vector<vector<int>> g;
vector<int> path;

void addEdge(int u, int v, ll c) {
    g[u].push_back(edges.size());
    edges.push_back(edge(u, v, c));
    g[v].push_back(edges.size());
    edges.push_back(edge(v, u, 0));
}

ll augment(int s, int t) {
    path.assign(g.size(), -1);
    queue<int> q;

    q.push(s);
    path[s] = -2;

    int its = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ++its;
        for (auto i : g[cur]) {
            int nxt = edges[i].v;
            if (edges[i].c && path[nxt] == -1) {
                path[nxt] = i;
                q.push(nxt);
            }
        }
    }

    if (path[t] == -1) return 0;

    ll aug = INFTY;
    int tt = t;
    while (tt != s) {
        int i = path[tt];
        tt = edges[i].u;
        aug = min(aug, edges[i].c);
    }

    tt = t;
    while (tt != s) {
        int i = path[tt];
        tt = edges[i].u;
        edges[i].c -= aug;
        edges[i^1].c += aug;
    }

    return aug;
}

ll maxFlow(int s, int t) {
    ll flow = 0, aug;

    do {
        flow += (aug = augment(s, t));
    } while (aug);

    return flow;
}

int main() {
    int n;
    cin >> n;

    ll totVal = 0;
    g.resize(n+2);
    for (int i = 1; i <= n; ++i) {
        ll v, c;
        int m;

        cin >> v >> c >> m;
        totVal += v;
        addEdge(0, i, v);
        addEdge(i, n+1, c);
        while (m--) {
            int obs;
            cin >> obs;
            addEdge(obs, i, INFTY);
        }
    }

    cout << totVal - maxFlow(0, n+1) << endl;
    // for (int i = 1; i < edges.size(); i += 2)
    //     if (edges[i].c)
    //     cout << edges[i^1].u << ' ' << edges[i^1].v << ' ' << edges[i].c << endl;

    return 0;
}

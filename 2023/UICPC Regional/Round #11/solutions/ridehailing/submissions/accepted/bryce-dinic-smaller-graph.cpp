// Flow solution that uses Dinic's algorithm on the smaller flow graph.
// Unknown complexity, but intuitively it should probably be faster than
// Dinic's on the larger graph, though I have no such proof.


#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<iii> viii;
typedef vector<bool> vb;

const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) { amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vvi adj_matrix(n, vi(n, INF));
    for (ll i = 0; i < n; ++i) {
        adj_matrix[i][i] = 0;
    }

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj_matrix[u][v] = w;
    }

    // run Floyd-Warshall for shortest paths
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
            }
        }
    }

    Dinic graph(2*k+2);
    for (ll i = 1; i <= k; ++i) {
        graph.AddEdge(0, i, 1);
        graph.AddEdge(k+i, 2*k+1, 1);
    }
    viii trips;

    for (ll i = 0; i < k; ++i) {
        ll u, v, t;
        cin >> u >> v >> t;
        --u;
        --v;
        trips.push_back(iii(t, ii(u, v)));
    }
    sort(trips.begin(), trips.end());

    for (ll i = 0; i < k; ++i) {
        vb added(n, false);
        ll end_city = trips[i].s.s;
        ll end_time = trips[i].f + adj_matrix[trips[i].s.f][trips[i].s.s];
        bool added_special_edge = false;
        for (ll j = i+1; j < k; ++j) {
            ll start_city = trips[j].s.f;
            ll start_time = trips[j].f;
            
            if (!added_special_edge && start_city == trips[i].s.f) {
                added_special_edge = true;
                graph.AddEdge(k+i+1, k+j+1, INF);    // add special edge
            }

            if (end_time + adj_matrix[end_city][start_city] <= start_time) {    // feasible for trip[j] to follow trip[i]
                if (!added[start_city]) {   // only create edges to unique cities (makes smaller graph)
                    added[start_city] = true;

                    graph.AddEdge(i+1, k+j+1, 1);
                }
            }
        }
    }

    cout << k - graph.GetMaxFlow(0, 2*k+1) << endl;
}

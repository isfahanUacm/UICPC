// Flow solution that uses Ford-Fulkerson (Edmonds-Karp) on the larger flow graph.
// O(n^3)


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

#define FOR(v,l,u) for( size_t v = l; v < u; ++v )

typedef long long T; // also works for doubles, but use feq, etc
const T INFTY = 2000000000; // ::infinity() for doubles

typedef vector<size_t> VI;
typedef vector<VI>     VVI;
typedef vector<T>      VT;
typedef vector<VT>     VVT;

// Edmonds-Karp algorithm for max-flow
// Runs in O(VE^2). Alternate complexity: O(f(V+E)),
// where f is the value of the maximum flow
struct edmondskarp_graph {
	size_t N;
	VVI A;
	VVT C, F;  // references to F can be removed if you don't want flows
	edmondskarp_graph( size_t _N ) : N(_N), A(N), C(N,VT(N,0)), F(N,VT(N,0)) {}
	void add_capacity( size_t s, size_t t, T cap ) {
		if( cap == 0 ) return;
		if( C[s][t] == 0 && C[t][s] == 0 ) {
			A[s].push_back(t);
			A[t].push_back(s);
		}
		C[s][t] += cap;
		// If you subtract capacities, and want to remove edges with cap 0,
		// do so here, or afterward.
	}
	T Augment( const VI &P ) {
		T amt = INFTY;
		FOR(i,0,P.size()-1) amt = min(amt, C[ P[i] ][ P[i+1] ]);
		FOR(i,0,P.size()-1) {
			size_t u = P[i], v = P[i+1];
			C[u][v] -= amt;
			C[v][u] += amt;
			if( F[v][u] > amt ) {
				F[v][u] -= amt;
			}
			else {
				F[u][v] += amt - F[v][u];
				F[v][u] = 0;
			}
		}
		return amt;
	}
	bool bfs( size_t s, size_t t, VI &P ) {
		P = VI(N,N);
		VI Q(N);  size_t qh=0, qt=0;
		P[  Q[qt++] = s  ] = s;
		while( qh < qt && P[t] == N ) {
			size_t c = Q[qh++];
			FOR(i,0,A[c].size()) {
				size_t u = A[c][i];
				if( C[c][u] == 0 ) continue;
				if( P[u] != N ) continue;
				P[  Q[qt++] = u  ] = c;
			}
		}
		return P[t] != N;
	}
	T ComputeMaxFlow( size_t s, size_t t ) {
		T flow = 0;
		VI P;
		while( bfs(s,t,P) ) {
			VI path(1,t);
			size_t z = t;
			while( z != P[z] ) path.push_back( z = P[z] );
			path = VI(path.rbegin(), path.rend());
			flow += Augment(path);
		}
		return flow;
	}
};
// END

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vvi adj_matrix(n, vi(n, INFTY));
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

    edmondskarp_graph graph(2*k+2);
    for (ll i = 1; i <= k; ++i) {
        graph.add_capacity(0, i, 1);
        graph.add_capacity(k+i, 2*k+1, 1);
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
        ll end_city = trips[i].s.s;
        ll end_time = trips[i].f + adj_matrix[trips[i].s.f][trips[i].s.s];
        for (ll j = i+1; j < k; ++j) {
            ll start_city = trips[j].s.f;
            ll start_time = trips[j].f;

            if (end_time + adj_matrix[end_city][start_city] <= start_time) {    // feasible for trip[j] to follow trip[i]
                graph.add_capacity(i+1, k+j+1, 1);
            }
        }
    }

    cout << k - graph.ComputeMaxFlow(0, 2*k+1) << endl;
}

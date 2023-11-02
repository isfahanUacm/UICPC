#include <iostream>
#include <vector>
#include <cstdlib>

#define INF 100000000

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

// m here is a rough (under)estimate since edges may be added to satisfy strongly connected requirement
ll n = 100;
ll m = 9900;
ll k = 1000;

void line() {
    cout << n << " " << (n-1)*2 << " " << (n-1)*2 << endl;
    for (ll i = 0; i < n-1; ++i) {
        cout << i+1 << " " << i+2 << " " << 1 << endl;
        cout << i+2 << " " << i+1 << " " << 1 << endl;
    }
    for (ll i = 0; i < n-1; ++i) {
        cout << i+1 << " " << i+2 << " " << i << endl;
    }
    for (ll i = 0; i < n-1; ++i) {
        cout << n-i << " " <<  n-i-1 << " " << i << endl;
    }
}

void random_graph(vvi &adj_matrix, ll edges) {
    while (edges > 0) {
        ll u = rand()%n;
        ll v = rand()%n;
        if (u == v) continue;

        if (adj_matrix[u][v] != INF)
            continue;

        adj_matrix[u][v] = 1+rand()%479;
        --edges;    
    }
}

bool is_sc(vvi &adj_matrix, vvi &dist) {
    dist = adj_matrix;
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                return false;
            }
        }
    }
    return true;
}

ll make_sc(vvi &adj_matrix) {
    ll edges_added = 0;
    vvi dist;
    while (!is_sc(adj_matrix, dist)) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (i == j) continue;
                if (dist[i][j] == INF) {
                    adj_matrix[i][j] = 1+rand()%479;
                    ++edges_added;
                    goto OUTER;
                }
            }
        }
OUTER:;
    }
    return edges_added;
}

void random_trips() {
    while (k > 0) {
        ll u = rand()%n;
        ll v = rand()%n;
        ll t = rand()%480;
        if (u == v)
            continue;
        cout << u+1 << " " << v+1 << " " << t << endl;
        --k;
    }
}

void print_graph(vvi &adj_matrix) {
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (adj_matrix[i][j] != INF) {
                cout << i+1 << " " << j+1 << " " << adj_matrix[i][j] << endl;
            }
        }
    }
}

int main() {
    line();
/*    vvi adj_matrix(n, vi(n, INF));
    random_graph(adj_matrix, m);
    m += make_sc(adj_matrix);

    cout << n << " " << m << " " << k << endl;
    print_graph(adj_matrix);
    random_trips();*/
}

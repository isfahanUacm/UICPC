/* Solution to Average DAG Distance by Mees
 *
 * We use the following input format: the input is given as an adjacency matrix
 * where non-reachable is encoded as -1. Furthermore, we assume that the
 * original graph satisfies the "triangle inequality": if there is a direct
 * edge from a to b, then every other path from a to b is longer than that
 * edge. Finally, we make the assumption that the original graph only has
 * integral weights.
 *
 * Expected answer: ACCEPTED.
 *
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;

    vector<vector<long double>> adj_unsorted(n, vector<long double>(n));

    vector<int> prevct(n, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj_unsorted[i][j];
            if(adj_unsorted[i][j] > 0)
                prevct[j]++;
        }
    }

    // First we make a topological sort.

    queue<int> q;

    vector<int> sorted_nodes;

    for(int i = 0; i < n; i++) {
        if(prevct[i] == 0) {
            q.push(i);
            sorted_nodes.push_back(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nb = 0; nb < n; nb++) {
            if(adj_unsorted[cur][nb] > 0) {
                prevct[nb]--;
                if(prevct[nb] == 0) {
                    q.push(nb);
                    sorted_nodes.push_back(nb);
                }
            }
        }
    }
    

    vector<int> inverse_sort(n);

    for(int i = 0; i < n; i++) {
        inverse_sort[sorted_nodes[i]] = i;
    }

    vector<vector<long double>> adj(n, vector<long double>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = adj_unsorted[sorted_nodes[i]][sorted_nodes[j]];
        }
    }

    vector<vector<long long>> adj_orig(n, vector<long long>(n, -1));
    vector<vector<long long>> num_paths(n, vector<long long>(n, 0));

    for(int i = 0; i < n; i++)
        adj_orig[i][i] = -1;

    for(int i = 0; i + 1 < n; i++) {
        if(adj[i][i+1] > 0) {
            adj_orig[i][i+1] = round(adj[i][i+1]);
            num_paths[i][i+1] = 1;
        }
    }

    for(int len = 2; len < n; len++) {
        for(int i = 0; i + len < n; i++) {
            int j = i + len;

            // So we are now filling adj_orig[i][j] and num_paths[i][j]. So we
            // have to compute the current num_paths (if we don't add an i-j
            // edge) and the current average distance.
            long double tot_dist = 0;
            for(int k = i + 1; k < j; k++) {
                if(adj_orig[i][k] != -1 && num_paths[k][j] != 0) {
                    num_paths[i][j] += num_paths[k][j];
                    tot_dist += num_paths[k][j]*(adj_orig[i][k] + adj[k][j]);
                }
            }
            // If you would add a path of length w, then the new average weight would become
            //     (tot_dist + w)/(num_paths[i][j] + 1).
            // So the optimal w is
            //     w = adj[i][j]*(num_paths[i][j] + 1) - tot_dist

            long long w = llround(adj[i][j]*(num_paths[i][j] + 1) - tot_dist);
            if ((num_paths[i][j] == 0 && adj[i][j] > 0) ||
                (w > 0 && w < adj[i][j] - 0.5)) {
                num_paths[i][j]++;
                adj_orig[i][j] = w;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adj_orig[inverse_sort[i]][inverse_sort[j]] << " ";
        }
        cout << endl;
    }

    return 0;
}

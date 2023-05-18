#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct Toposort {
	vector<vector<int>> &edges;
	int V, s_ix; // sorted-index
	vector<int> sorted, visited;

	Toposort(vector<vector<int>> &edges)
	    : edges(edges), V(edges.size()), s_ix(V), sorted(V, -1), visited(V, false) {}

	void visit(int u) {
		visited[u] = true;
		for(int v : edges[u])
			if(!visited[v]) visit(v);
		sorted[--s_ix] = u;
	}
	void topo_sort() {
		for(int i = 0; i < V; ++i)
			if(!visited[i]) visit(i);
	}
};
int main(int argc, char **argv) {
	int n;
	cin >> n;
	array<array<long long, 100>, 100> dist, count, sum, ans;
	for(auto &x : count) x.fill(0);
	for(auto &x : sum) x.fill(0);
	for(auto &x : ans) x.fill(-1);
	vector<vector<int>> g(n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> dist[i][j];
			if(dist[i][j] > 0) g[i].push_back(j);
		}
	}

	Toposort ts(g);
	ts.topo_sort();

	for(int i = 0; i < n; ++i)
		for(int j = i-1; j >= 0; --j) {
			int u = ts.sorted[j];
			int v = ts.sorted[i];
			// Calculate stats for u->v.
			assert(count[u][v] == 0);
			for(int k = j + 1; k < i; ++k) {
				int w = ts.sorted[k];
				// Count paths of the form u->...->w->v
				if(ans[w][v] > 0) {
					count[u][v] += count[u][w];
					sum[u][v] += sum[u][w] + count[u][w] * ans[w][v];
				}
			}

			if(dist[u][v] == -1){
				assert(count[u][v] == 0);
				continue;
			}

			// (sum + d)/(count+1) = dist
			// d = dist*(count+1)-sum
			auto d = dist[u][v] * (count[u][v] + 1) - sum[u][v];


			assert(d > 0); // edges are positive
			assert(d <= dist[u][v]); // triangle inequality

			// add edge from u to v with length d.
			if(d < dist[u][v] || count[u][v] == 0) {
				ans[u][v] = d;
				++count[u][v];
				sum[u][v] += d;
			} else {
				// Due to strict triangle inequality, we don't add the edge in
				// this case.
				ans[u][v] = -1;
			}
			assert(sum[u][v] == count[u][v] * dist[u][v]);
		}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) cout << ans[i][j] << " \n"[j == n - 1];
}

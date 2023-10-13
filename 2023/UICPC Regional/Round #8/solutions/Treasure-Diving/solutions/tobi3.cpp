// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define MAX 10000
#define MAX_IDOLS (8+1)

int numNodes, numEdges, numIdols;
vector<int> adjList[MAX];
vector<int> costList[MAX];
vector<int> idols;
vector<int> dist;

int distMatrix[MAX_IDOLS][MAX_IDOLS];
int tspMatrix[MAX_IDOLS][MAX_IDOLS];
int opt[(1 << MAX_IDOLS)][MAX_IDOLS];
int pow2[MAX_IDOLS + 1];

void dijkstra(int from) {
	dist = vector<int>(numNodes, INT_MAX/2);
	
	dist[from] = 0;
	set<pair<int,int> > pq;
	pq.insert(make_pair(dist[from], from));
	while (!pq.empty()) {
		int node = pq.begin()->second;
		pq.erase(pq.begin());
		FOR(i, 0, (signed)adjList[node].size()) {
			int next = adjList[node][i];
			int cost = costList[node][i];
			if (dist[node] + cost >= dist[next]) {
				continue;
			}
			if (dist[next] < INT_MAX/2) {
				pq.erase(pq.find(make_pair(dist[next], next)));
			}
			dist[next] = dist[node] + cost;
			pq.insert(make_pair(dist[next], next));
		}
	}
}

int tsp(int usedNodes) {
	FOR(i, 0, pow2[usedNodes]) FOR(j, 0, usedNodes) opt[i][j] = INT_MAX/2;
	
	opt[1][0] = 0;
	FOR(i, 1, pow2[usedNodes]) FOR(j, 0, usedNodes) {
		if (opt[i][j] == INT_MAX) continue;
		FOR(k, 0, usedNodes) {
			if ((i >> k) & 1 || tspMatrix[j][k] == INT_MAX/2) continue;
			if (opt[i + pow2[k]][k] > opt[i][j] + tspMatrix[j][k]) {
				opt[i + pow2[k]][k] = opt[i][j] + tspMatrix[j][k];
			}
		}
	}

	int optimum = opt[pow2[usedNodes]-1][0];
	FOR(i, 1, usedNodes) {
		if (opt[pow2[usedNodes]-1][i] == INT_MAX || tspMatrix[i][0] == INT_MAX) continue;
		if (optimum > opt[pow2[usedNodes]-1][i] + tspMatrix[i][0]) {
			optimum = opt[pow2[usedNodes]-1][i] + tspMatrix[i][0];
		}
	}
	return optimum;
}

int main(int argc, char **argv) {
	int from, to, cost, air;
	scanf("%d", &from); // skip number of cases
	while (EOF != scanf("%d%d", &numNodes, &numEdges)) {
		idols.clear();
		FOR(i, 0, numNodes) {
			adjList[i].clear();
			costList[i].clear();
		}

		FOR(i, 0, numEdges) {
			scanf("%d%d%d", &from, &to, &cost);	
			adjList[from].push_back(to);
			costList[from].push_back(cost);
			adjList[to].push_back(from);
			costList[to].push_back(cost);
		}

		idols.push_back(0);
		scanf("%d", &numIdols);
		FOR(i, 0, numIdols) {
			scanf("%d", &from);
			idols.push_back(from);
		}

		FOR(i, 0, numIdols + 1) {
			dijkstra(idols[i]);
			FOR(j, 0, numIdols + 1) {
				distMatrix[i][j] = dist[idols[j]];
			}
		}

		scanf("%d", &air);
		int best = 0;
		pow2[0] = 1;
		FOR(i, 1, numIdols + 2) pow2[i] = 2 * pow2[i-1];
		FORD(i, 1, pow2[numIdols + 1]) {
			if (!(i & 1)) continue;

			int usedNodes = 0;
			int mapping[numIdols + 1];
			FOR(j, 0, numIdols + 1) {
				if (i & (1 << j)) {
					mapping[usedNodes] = j;
					usedNodes++;
				}
			}
			FOR(j, 0, usedNodes) FOR(k, 0, usedNodes) {
				tspMatrix[j][k] = distMatrix[mapping[j]][mapping[k]];
			}
			if (best < usedNodes - 1 && tsp(usedNodes) <= air) {
				best = usedNodes - 1;
			}
		}
		printf("%d\n", best);
	}

	return 0;
}

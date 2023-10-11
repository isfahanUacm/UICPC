#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using ll  = long long;

// This is a solution using bipartite matching that does not use the properties of the Manhattan distance at all. \
// Source of matching code: https://sites.google.com/site/indy256/algo_cpp/hopcroft_karp. 

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], previous[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    previous[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = previous[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = previous[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

int main() 
{
	ll answer = 0;
	int n;
	cin >> n;
	
	vector<ll> tutorsx(n, 0), tutorsy(n, 0), studentsx(n, 0), studentsy(n, 0);
	
	for(int i = 0; i < n; i++)
		cin >> studentsx[i] >> studentsy[i];
	for(int i = 0; i < n; i++)
		cin >> tutorsx[i] >> tutorsy[i];
	
	
	
	vector<vector<ll>> distances(n, vector<ll>(n));
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			distances[i][j] = abs(tutorsx[i] - studentsx[j]) + abs(tutorsy[i] - studentsy[j]);
	
	ll low = 0, high = 10000000000, mid; // Binary search, low inclusive, high exclusive.
	while(high - low > 2)
	{
		init(n, n);
		mid = (low + high) / 2; // This is the maximum allowed distance that we now check.
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(distances[i][j] <= mid)
					addEdge(i, j);
			
		if(maxMatching() == n)
			high = mid + 1;
		else if(maxMatching() < n)
			low = mid + 1;			
	}
	
	// low and low + 1 are still possibilities.
	init(n, n);
	for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(distances[i][j] <= low)
					addEdge(i, j);
			
	if(maxMatching() == n)
		answer = low;
	else answer = low + 1;	
	
	cout << answer << "\n";
}
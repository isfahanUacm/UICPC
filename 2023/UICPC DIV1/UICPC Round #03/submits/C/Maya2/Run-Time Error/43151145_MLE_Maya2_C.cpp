#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 2e5 + 10;
vector<vector<int>> g;
int weight[maxn];
priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int> > > pq;
int mark[maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		int w; 
		cin >> w;
		weight[i] = w;
	}
	
	int w = weight[0];
	weight[0] = 0;
	
	mark[0] = 1;
	pq.push({weight[0], 0});
	while (!pq.empty()) {
		pair<int, int> xy = pq.top();
		pq.pop(); 
		mark[xy.second] = 1;
		if (xy.first < w) w += xy.first;
		else break;
		for (int u : g[xy.second]) {
			if (mark[u]) continue;
			pq.push({weight[u], u});
		}
	}
	cout << w;

	return 0;

	}
		

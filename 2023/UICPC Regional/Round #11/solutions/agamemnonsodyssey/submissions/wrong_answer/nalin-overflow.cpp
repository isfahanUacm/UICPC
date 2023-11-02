#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = int(2e5)+5;

vector<pair<int, int>> graph[maxn];

pair<int, int> farthest(int node, int par)
{
	pair<int, int> res = {0ll, node};
	for(auto it: graph[node])
	{
		if(it.first != par)
		{
			auto tmp = farthest(it.first, node);
			tmp.first += it.second;
			res = max(res, tmp);
		}
	}
	return res;
}

int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int edgesum = 0ll;
	for(int i = 1;i < n;i++)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
		edgesum += c;
	}

	if(k == 1ll)
	{
		auto corner = farthest(0ll, -1ll);
		printf("%d\n", corner.first);
	}
	else printf("%d\n", edgesum);
}
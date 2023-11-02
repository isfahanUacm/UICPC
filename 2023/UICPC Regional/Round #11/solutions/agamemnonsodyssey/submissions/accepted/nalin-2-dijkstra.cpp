#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

typedef long long int lli;

const lli maxn = lli(2e5)+5, inf = lli(1e18)+5;

vector<pair<lli, lli>> graph[maxn];

pair<lli, lli> farthest(lli node)
{
	set<pair<lli, lli>> Q;
	vector<lli> D(maxn, inf);
	D[node] = 0;
	Q.insert({0ll, node});
	pair<lli, lli> res = {0ll, node};
	while(!Q.empty())
	{
		pair<lli, lli> top = *Q.begin();
		res = max(res, top);
		Q.erase(Q.begin());

		for(auto it: graph[top.second])
		{
			if(D[it.first] > top.first + it.second)
			{
				if(D[it.first] != inf) Q.erase({D[it.first], it.first});
				D[it.first] = top.first + it.second;
				Q.insert({D[it.first], it.first});
			}
		}
	}

	return res;
}

int main(void)
{
	lli n, k;
	scanf("%lld%lld", &n, &k);
	lli edgesum = 0ll;
	for(lli i = 1;i < n;i++)
	{
		lli u, v, c;
		scanf("%lld%lld%lld", &u, &v, &c);
		u--, v--;
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
		edgesum += c;
	}

	if(k == 1ll)
	{
		auto corner = farthest(0ll);
		auto dia = farthest(corner.second);
		printf("%lld\n", dia.first);
	}
	else printf("%lld\n", edgesum);
}
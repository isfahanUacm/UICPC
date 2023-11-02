#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int lli;

const lli maxn = lli(2e5)+5;

vector<pair<lli, lli>> graph[maxn];

pair<lli, lli> farthest(lli node, lli par)
{
	pair<lli, lli> res = {0ll, node};
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
		pair<lli, lli> res = {0ll, 0ll};
		for(lli i = 0;i < n;i++)
		{
			res = max(res, farthest(i, -1ll));
		}
		printf("%lld\n", res.first);
	}
	else printf("%lld\n", edgesum);
}
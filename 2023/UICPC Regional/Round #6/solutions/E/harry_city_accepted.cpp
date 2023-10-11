#include <iostream> // strings/streams
#include <cstdio> // utils
#include <string>
#include <cstring>
#include <sstream>
#include <vector> // datastructures
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple> // quick compare
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>
#include <complex>

#define REP(i,n)	for(auto i = decltype(n)(0); i<(n); i++)
#define all(v)		begin(v), end(v)

using namespace std;
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using ii  = pair<ll,ll>;
using vi  = vector<ll>;
using vii = vector<ii>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvii = vector<vii>;

constexpr int  INF = 1e9+1; // < 1e9 - -1e9
constexpr ll LLINF = 1e18+1;

struct Edge{ int v; ll weight; };	// input edges
struct PQ{ ll d; int v; };			// distance and target
bool operator>(const PQ &l, const PQ &r){ return l.d > r.d; }

ll dijkstra(vector<vector<Edge>> &edges, int s, int t, ll max) {
	vector<ll> dist(edges.size(),LLINF);
	priority_queue<PQ,vector<PQ>,greater<PQ>> pq;
	dist[s] = 0; pq.push({0, s});
	while (!pq.empty()) {
		auto d = pq.top().d; auto u = pq.top().v; pq.pop();
		if(u==t) break;			// target reached
		if (d == dist[u])
			for(auto &e : edges[u]) if (e.weight <= max && dist[e.v] > d + e.weight)
				pq.push({dist[e.v] = d + e.weight, e.v});
	}
	return dist[t];
}

int main()
{
	int n, m, x;
	cin >> n >> m >> x; 
	vector<vector<Edge>> edges(n);
	for(int i = 0; i < m; ++i) // Adding all edges. 
	{
		int c1, c2;
		ll t;
		cin >> c1 >> c2 >> t;
		c1--; c2--;
		Edge e1 = {c2, t};
		edges[c1].push_back(e1);
		Edge e2 = {c1, t}; // Both ways. 
		edges[c2].push_back(e2);
	}
	ll fastest = dijkstra(edges, 0, n-1, LLINF);
	ll max_allowed = (fastest * (100 + x))/100;
	ll low = 0;
	ll high = 1000000005; // Binary search, low inclusive, high exclusive.
	
	ll dist;
	while(high - low > 2)
	{
		ll mid = (low + high)/2;
		dist = dijkstra(edges, 0, n-1, mid);
		if(dist == LLINF || dist > max_allowed) // There exists no route, or the route is too slow.
		{
			low = mid + 1;
		}
		else high = mid + 1;		
	}
	
	ll ans;
	dist = dijkstra(edges, 0, n-1, low); // If high = low + 2, we have both low and low+1 as possible answers, so we check if low is possible.
	if(dist == LLINF || dist > max_allowed) 
	{
		ans = low + 1;
	}
	else ans = low;
	
	cout << ans << "\n"; 
}
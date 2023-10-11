#include <iostream>
#include <cassert>
#include <list>
#include <queue>
#include <climits>

using namespace std;

typedef pair <long long, int> arrow; // (distance, node)

int n, m;
long long x, c[100001][2], t[100001], maxdist, dist[10001];
list <arrow> nhbs[10001];
const long long INFINITY = LLONG_MAX-1;

long long dijkstra (int s, int t, long long maxarrow) {	// Dijkstra using only edges of length at most max arrow
	priority_queue <arrow, vector <arrow>, greater <arrow> > q;
	arrow cur;
	
	for (int i = 0; i < n; i++) {
		dist[i] = INFINITY;
	}
	
	dist[s] = 0;
	q.push(make_pair(dist[s],s));
	
	while (!q.empty()) {
		cur = q.top();
		q.pop();
		
		if (dist[cur.second] < cur.first) { continue; }
		
		if (cur.second == t) {
			return dist[t];
		}
		
		for (list <arrow>::iterator it = nhbs[cur.second].begin(); it != nhbs[cur.second].end(); ++it) {
			if ((cur.first + it->first < dist[it->second]) && (it->first <= maxarrow)) {
				dist[it->second] = cur.first + it->first;
				q.push(make_pair(dist[it->second], it->second));
			}
		}
	}
	
	return INFINITY;
}

bool impossible(long long maxarrow) {	// Is it impossible to get in time using only edges of size at most maxarrow?
	return (dijkstra(0, n-1, maxarrow) > maxdist);
}

int main () {
	cin >> n >> m >> x;
	assert(1 <= m);
	assert(2 <= n);	// Input checker
	assert(0 <= x);
	assert(n <= 10000LL);
	assert(m <= 100000LL);
	assert(x <= 10000LL);
	
	for (int i = 0; i < m; i++) {
		cin >> c[i][0] >> c[i][1] >> t[i];
		c[i][0]--; c[i][1]--;
		assert(0 <= c[i][0]);
		assert(0 <= c[i][1]);	// Input checker
		assert(c[i][0] <= n-1);
		assert(c[i][1] <= n-1);
		assert(1 <= t[i]);
		assert(t[i] <= 1000000000LL);
		
		nhbs[c[i][0]].push_back(make_pair(t[i], c[i][1]));
		nhbs[c[i][1]].push_back(make_pair(t[i], c[i][0]));
		
	}
	
	maxdist = dijkstra(0, n-1, INFINITY);
	assert(maxdist < INFINITY);	// Assert destination is reachable
	maxdist = (maxdist*(100+x))/100;

	long long lo = -1;
	long long hi = maxdist + 1;
	while (hi - lo > 1) {	// Binary search for solution
		long long mid = (lo+hi)/2;
		(impossible(mid) ? lo : hi) = mid;
	}
	cout << hi << '\n';

	return 0;
}




#include <bits/stdc++.h>
using namespace std;

struct edge{
    long long int t0, p, d;
};

long long int dist[100003], s, n, m, t0, p, d, u, v, departure, st0, sp, sd;
vector<pair<int, edge>> adj[100003];
priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;

bool judge(long long int  t){
    fill_n(dist, n+1, LLONG_MAX);
    dist[0] = t;
    pq.push({t, 0});
    pair<long long int, int> top;
    while(!pq.empty()){
        top = pq.top();pq.pop();
        if(dist[top.second] < top.first)
            continue;
        for (auto stop: adj[top.second]) {
            st0 = stop.second.t0, sp = stop.second.p, sd = stop.second.d;
            departure = max(0ll, (top.first-st0)/sp + (((top.first-st0)%sp)?1:0)) * sp + st0;
            if(departure + sd < dist[stop.first]){
                dist[stop.first] = departure + sd;
                pq.push({dist[stop.first], stop.first});
            }
        }
    }
    return dist[n-1] <= s;
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> t0 >> p >> d;
        edge e; e.t0 = t0, e.p = p, e.d = d;
        adj[u].push_back({v, e});
    }
    if(!judge(0)){
        cout << "impossible" << endl;
        return 0;
    }
    long long int lo = 0, hi = s, mid;
    while(lo < hi){
        mid = (lo + hi) / 2 + (lo + hi) % 2;
        if (judge(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << endl;
        
    return 0;
}


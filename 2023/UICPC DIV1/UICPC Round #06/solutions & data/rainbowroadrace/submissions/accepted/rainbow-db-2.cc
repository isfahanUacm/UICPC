// If the bounds were bigger, this this should be TLE.
// But with small bounds, a bad implementation of Dijkstra passes...

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;
vector<vector<pli> > adj;
vector<long long> dist;

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n << 7);
    dist.assign(n << 7, -1);
    
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v; u--; v--;
        int d; cin >> d;
        char c; cin >> c;
        int colour = string("ROYGBIV").find(c);
        for(int j=0;j<(1 << 7);j++){
            adj[(u << 7) + j].emplace_back(d, (v << 7) + (j | (1 << colour)) );
            adj[(v << 7) + j].emplace_back(d, (u << 7) + (j | (1 << colour)) );
        }
    }
    
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.emplace(0,0);
    dist[0] = 0;
    while(!pq.empty()){
       long long d = pq.top().first;
       int v = pq.top().second;
       pq.pop();
        
        if(v == (1 << 7)-1) break;
        
       for(const auto& u : adj[v])
	   if(dist[u.second] == -1 || dist[u.second] > d+u.first){
	    dist[u.second] = d+u.first;
            pq.emplace(d+u.first, u.second);
	   }
    }
    
    cout << dist[(1 << 7)-1] << endl;
}

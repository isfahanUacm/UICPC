#include <bits/stdc++.h>
using namespace std;

// Treasure Diving

#define inf INT_MAX
const int maxn = 1e4 + 5;

int n, m, p, a, tr[11], tmp[maxn], dist[11][11], dp[(1<<8)+3][11];
vector<pair<int, int>> adj[maxn];

void dijkstra(int t1){
    int s = tr[t1];
    fill_n(tmp, n, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;
    tmp[s] = 0, dij.push({0, s});
    while(!dij.empty()){
        int u = dij.top().second;
        int w = dij.top().first;
        dij.pop();
        if(tmp[u] < w)
            continue;
        for(pair<int, int> v : adj[u])
            if(w + v.second < tmp[v.first])
                tmp[v.first] = w + v.second, dij.push({tmp[v.first], v.first});     
    }
    for(int t2 = 0; t2 < p; t2++)
        dist[t1][t2] = tmp[tr[t2]];
}

inline int ones(int mask){
    int cnt = 0;
    while(mask){
        if(mask % 2)
            cnt++;
        mask /= 2;
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int x, y, w;
        while(m--)
            cin >> x >> y >> w, adj[x].push_back({y, w}), adj[y].push_back({x, w});
        cin >> p, p++, tr[0] = 0;
        for(int i = 1; i < p; i++)
            cin >> tr[i];
        cin >> a;
        for(int i = 0; i < p; i++)
            dijkstra(i);
        int ans = 0;
        for(int mask = 1; mask < (1<<(p-1)); mask++)
            for(int node = 0; node < p - 1; node++)
                if(mask & (1 << node)){
                    if(mask == 1 << node)
                        dp[mask][node] = dist[0][node+1];
                    else{
                        dp[mask][node] = inf;
                        for(int prevy = 0; prevy < p - 1; prevy++)
                            if(prevy != node && (mask & (1 << prevy))){
                                int subp = dp[mask - (1 << node)][prevy];
                                int di = dist[prevy+1][node+1];
                                if(subp != inf && di != inf)
                                    dp[mask][node] = min(dp[mask][node], subp + di);
                            }
                    }
                    if(dp[mask][node] != inf && dist[node+1][0] != inf && dp[mask][node] + dist[node+1][0] <= a)
                        ans = max(ans, ones(mask));
                }
        cout << ans << endl;
    }
}

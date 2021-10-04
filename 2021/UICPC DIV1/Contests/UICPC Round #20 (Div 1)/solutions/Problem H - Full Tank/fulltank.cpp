#include <bits/stdc++.h>
using namespace std;

// Full Tank?

#define inf INT_MAX

int n, m, p[1003], c, dis[1003][103];
vector<pair<int, int>> adj[1003];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", p+i);
    int u, v, w;
    while(m--)
        scanf("%d %d %d", &u, &v, &w), adj[u].push_back({v, w}), adj[v].push_back({u, w});
    int q;
    scanf("%d", &q);
    while(q--){
        int s, e;
        scanf("%d %d %d", &c, &s, &e);
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= c; j++)
                dis[i][j] = inf;
        dis[s][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dij;
        dij.push({0, {s, 0}});
        int ans = inf;
        while(!dij.empty()){
            int w = dij.top().first, u = dij.top().second.first, fuel = dij.top().second.second;
            dij.pop();
            if(dis[u][fuel] < w)
                continue;
            if(u == e){
                ans = w;
                break;
            }
            for(auto p : adj[u]){
                int v = p.first, way_fuel = p.second;
                if(fuel >= way_fuel && w < dis[v][fuel-way_fuel])
                    dis[v][fuel-way_fuel] = w, dij.push({w, {v, fuel-way_fuel}});
            }
            if(fuel < c && w + p[u] < dis[u][fuel+1])
                dis[u][fuel+1] = w + p[u], dij.push({w + p[u], {u, fuel+1}});
        }
        if(ans == inf)
            cout << "impossible" << endl;
        else
            cout << ans << endl;
    }
}
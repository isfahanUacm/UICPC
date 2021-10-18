#include <bits/stdc++.h>
using namespace std;

// Flowery Trails

#define inf INT_MAX

int n, m;
vector<pair<int, int>> adj[10003];
int dis[10003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;
int ans = 0;
bool vis[10003];

void dfs(int u){
    vis[u] = true;
    for(pair<int, int> v : adj[u])
        if(dis[v.first] + v.second == dis[u]){
            ans += v.second;
            if(!vis[v.first])
                dfs(v.first);
        }
}

int main(){
    cin >> n >> m;
    int x, y, w;
    while(m--)
        cin >> x >> y >> w, adj[x].push_back({y, w}), adj[y].push_back({x, w});
    fill_n(dis, n, inf);
    dis[0] = 0;
    dij.push({0, 0});
    while(!dij.empty()){
        int w = dij.top().first, u = dij.top().second;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, int> v : adj[u])
            if(w + v.second < dis[v.first])
                dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
    }
    dfs(n-1);
    cout << 2 * ans << endl;
} 
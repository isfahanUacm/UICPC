#include <bits/stdc++.h>
using namespace std;

// Shopping

#define num long long int 

const num inf = LLONG_MAX;

const int maxn = 1e5 + 3;

int n, m, s;
vector<pair<int, num>> adj[maxn];
vector<int> stores;

num dis[maxn], d[13][13], dp[(1 << 13)][13];
priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> dij;

inline void dijkstra(int src){
    fill_n(dis, n, inf);
    dis[src] = 0;
    dij.push({0, src});
    while(!dij.empty()){
        int u = dij.top().second;
        num w = dij.top().first;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(auto v : adj[u])
            if(w + v.second < dis[v.first])
                dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
    }
}

int main(){
    cin >> n >> m;
    int u, v;
    num w;
    while(m--)
        cin >> u >> v >> w, adj[u].push_back({v, w}), adj[v].push_back({u, w});
    stores.push_back(0);
    cin >> s;
    for(int i = 0; i < s; i++)
        cin >> u, stores.push_back(u);
    s++;
    for(int i = 0; i < s; i++){
        dijkstra(stores[i]);
        for(int j = 0; j < s; j++)
            d[i][j] = dis[stores[j]];
    }
    for(int mask = 1; mask < (1 << (s - 1)); mask++)
        for(int i = 0; i < s - 1; i++){
            if(mask == (1 << i))
                dp[mask][i] = d[0][i + 1];
            else if(mask & (1 << i)){
                dp[mask][i] = inf;
                for(int j = 0; j < s - 1; j++)
                    if(j != i && mask & (1 << j))
                        dp[mask][i] = min(dp[mask][i], dp[mask - (1 << i)][j] + d[i + 1][j + 1]);
            }
        }
    num ans = inf;
    for(int i = 0; i < s-1; i++)
        ans = min(ans, dp[(1 << (s - 1)) - 1][i] + d[i + 1][0]);
    cout << ans << endl;
}
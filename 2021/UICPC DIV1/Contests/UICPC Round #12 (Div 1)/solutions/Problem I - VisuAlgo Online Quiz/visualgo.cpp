#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10003
int dist[MAX_N];
int u, v, w, V, E, s, t;
vector<vector<pair<int, int>>> adj(MAX_N);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<vector<int>> par(MAX_N);
int dp[MAX_N];

int calc(int u){
    if(dp[u]!=INT_MAX)
        return dp[u];
    int res = 0;
    for (auto parent : par[u]) {
        res += calc(parent);
    }
    return dp[u]=res;
}

int main()
{
    cin>>V>>E;
    fill_n(dist, V, INT_MAX);
    for (int i = 0; i < E; ++i) {
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    cin>>s>>t;
    q.push({0, s});
    dist[s] = 0;
    pair<int, int> p;
    while(!q.empty()){
        p = q.top(); q.pop();
        w = p.first; u = p.second;
        if(w>dist[u])
            continue;
        if(u==t)
            break;
        for (auto edge : adj[u]) {
            if(dist[u]+edge.second==dist[edge.first]){
                par[edge.first].push_back(u);
            }
            else if(dist[u]+edge.second<dist[edge.first]){
                dist[edge.first] = dist[u] + edge.second;
                q.push({dist[edge.first], edge.first});
                par[edge.first].clear();
                par[edge.first].push_back(u);
            }
        }
    }
    fill_n(dp, V, INT_MAX);
    dp[s]=1;
    cout<<calc(t)<<endl;
    return 0;
}


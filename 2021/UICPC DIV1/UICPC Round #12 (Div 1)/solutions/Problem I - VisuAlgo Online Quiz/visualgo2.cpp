#include <bits/stdc++.h>
using namespace std;

// VisuAlgo Online Quiz

#define inf INT_MAX

int n, m, x, y, w, dis[10003];
vector<pair<int, int>> adj[10003], radj[10003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;
long long int dp[10003];

long long int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    if(u == x)
        return dp[u] = 1;
    long long int ans = 0;
    if(dis[u] != inf)
        for(pair<int, int> v : radj[u])
            if(dis[v.first] != inf && dis[v.first] + v.second == dis[u])
                ans += cdp(v.first);
    return dp[u] = ans;
}

int main(){
    cin >> n >> m;
    while(m--)
        cin >> x >> y >> w, adj[x].push_back({y, w}), radj[y].push_back({x, w});
    cin >> x >> y;
    fill_n(dis, n, inf);
    dis[x] = 0, dij.push({0, x});
    while(!dij.empty()){
        int w = dij.top().first, u = dij.top().second;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, int> v : adj[u])
            if(w + v.second < dis[v.first])
                dis[v.first] = w + v.second, dij.push({dis[v.first], v.first});
    }
    fill_n(dp, n, -1);
    cout << cdp(y) << endl;
}
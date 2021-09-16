#include <bits/stdc++.h>
using namespace std;

// Big Truck

#define inf INT_MAX

int n, m, t[103], dis[103], dp[103];
vector<pair<int, int>> adj[103];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dij;

int cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    int ans = t[u];
    for(pair<int, int> v : adj[u])
        if(dis[v.first] != inf && dis[v.first] + v.second == dis[u])
            ans = max(ans, t[u] + cdp(v.first));
    return dp[u] = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    cin >> m;
    int x, y, d;
    while(m--){
        cin >> x >> y >> d, x--, y--;
        adj[x].push_back({y, d}), adj[y].push_back({x, d});
    }
    fill_n(dis, n, inf);
    dis[0] = 0;
    dij.push({0, 0});
    while(!dij.empty()){
        int u = dij.top().second, w = dij.top().first;
        dij.pop();
        if(dis[u] < w)
            continue;
        for(pair<int, int> v : adj[u])
            if(dis[v.first] > w + v.second)
                dis[v.first] = w + v.second, dij.push({w + v.second, v.first});
    }
    if(dis[n-1] == inf){
        cout << "impossible" << endl;
        return 0;
    }
    fill_n(dp, n, -1);
    cout << dis[n-1] << " " << cdp(n-1) << endl;
}
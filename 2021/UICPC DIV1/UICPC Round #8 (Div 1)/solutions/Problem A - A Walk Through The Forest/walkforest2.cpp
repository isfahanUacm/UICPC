#include <bits/stdc++.h>
using namespace std;

#define num long long int
#define inf LLONG_MAX

// A Walk Through The Forest

int n;
vector<pair<int, num>> adj[1003];

num sp[1003];

void dijkstra(int source) {
    fill_n(sp, n, inf);
    sp[source] = 0;
    priority_queue<pair<num, int>, 
        vector<pair<num, int>>, 
        greater<pair<num, int>>> pq;
    pq.push(make_pair(0, source));
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        int u = top.second;
        num dis = top.first;
        if(dis > sp[u]) // lazy deletion
            continue;
        for(auto it: adj[u]){
            int v = it.first;
            num w = it.second;
            if(sp[u] + w < sp[v]){ // relaxation
                sp[v] = sp[u] + w;
                pq.push(make_pair(sp[v], v));
            }
        }
    }
}

num dp[1003];

num cdp(int node){
    if(dp[node] != -1)
        return dp[node];
    num ans = 0;
    for(auto u : adj[node])
        if(sp[u.first] < sp[node])
            ans += cdp(u.first);
    return dp[node] = ans;
}

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            dp[i] = -1;
        }
        int m, x, y;
        num d;
        cin >> m;
        while(m--){
            cin >> x >> y >> d;
            adj[x-1].push_back({y-1, d});
            adj[y-1].push_back({x-1, d});
        }
        dijkstra(1);
        dp[1] = 1;
        cout << cdp(0) << endl;
    }
}
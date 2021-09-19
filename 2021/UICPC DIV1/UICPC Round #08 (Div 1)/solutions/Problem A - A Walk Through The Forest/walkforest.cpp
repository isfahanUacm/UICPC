#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
long long int d;
vector<pair<int, long long int>> adj[1003];
vector<int> dadj[1003];
long long int dist[1003];
long long int dp[1003];

long long int cdp(int i){
    if(dp[i] != -1){
        return dp[i];
    }
    long long int ans = 0;
    for (auto v: adj[i]) {
        if(dist[v.first] < dist[i])
        ans += cdp(v.first);
    }
    return dp[i] = ans;
}

int main()
{
    while(cin >> n && n){
        cin >> m;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            dadj[i].clear();
            dist[i] = LLONG_MAX;
        }
        for (int i = 0; i < m; ++i){
            cin >> a >> b >> d, a--, b--;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        dist[1] = 0;
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
        pq.push({0, 1});
        pair<long long int, int> p;
        while(!pq.empty()){
            p = pq.top(); pq.pop();
            if(p.first > dist[p.second]){
                continue;
            }
            for(auto v: adj[p.second]){
                if(dist[v.first] > dist[p.second] + v.second){
                        dist[v.first] = dist[p.second] + v.second;
                        pq.push({dist[v.first], v.first});
                }
            }
        }
        fill_n(dp, n, -1);
        dp[1] = 1;
        cout << cdp(0) << endl;
    }
    return 0;
}


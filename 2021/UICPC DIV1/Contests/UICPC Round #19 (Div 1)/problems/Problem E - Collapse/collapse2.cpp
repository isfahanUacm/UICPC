#include <bits/stdc++.h>
using namespace std;

// Collapse

int n, t[100003], sum[100003];
vector<pair<int, int>> adj[100003];
bool vis[100003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int k, x, y;
        cin >> t[i] >> k, sum[i] = 0;
        while(k--)
            cin >> x >> y, sum[i] += y, adj[x-1].push_back({i, y});
    }
    fill_n(vis, n, false);
    queue<int> kahn;
    vis[0] = true, kahn.push(0);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        for(pair<int, int> v : adj[u])
            if(!vis[v.first]){
                sum[v.first] -= v.second;
                if(sum[v.first] < t[v.first])
                    vis[v.first] = true, kahn.push(v.first);
            }
    }
    cout << count(vis, vis+n, false) << endl;
}
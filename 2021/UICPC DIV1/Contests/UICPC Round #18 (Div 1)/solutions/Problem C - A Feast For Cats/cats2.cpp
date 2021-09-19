#include <bits/stdc++.h>
using namespace std;

// A Feast For Cats

int t, milk, n;
bool taken[2003];
vector<pair<int, int>> adj[2003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void prim(int u){
    taken[u] = true;
    for(pair<int, int> v : adj[u])
        if(!taken[v.first])
            pq.push({v.second, v.first});
}

int main(){
    cin >> t;
    while(t--){
        cin >> milk >> n;
        fill_n(taken, n, false);
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int x, y, w;
        int iters = (n * (n - 1)) / 2;
        while(iters--)
            cin >> x >> y >> w, adj[x].push_back({y, w}), adj[y].push_back({x, w});
        prim(0);
        int ans = 0;
        while(!pq.empty()){
            int u = pq.top().second, w = pq.top().first;
            pq.pop();
            if(taken[u])
                continue;
            ans += w;
            prim(u);
        }
        cout << ((ans + n <= milk) ? "yes" : "no") << endl;
    }
}
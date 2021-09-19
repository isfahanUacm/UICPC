#include <bits/stdc++.h>
using namespace std;

// Nature Reserve

#define num long long int

const int maxn = 1e4 + 3;

int n, m, s;
num l;
vector<int> sources;
vector<pair<int, num>> adj[maxn];
bool taken[maxn];
priority_queue<pair<num, int>, vector<pair<num, int>>, greater<pair<num, int>>> pq;

void prim(int u){
    taken[u] = true;
    for(auto v : adj[u])
        if(!taken[v.first])
            pq.push({v.second, v.first});
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> s;
        sources.clear();
        for(int i = 0; i < n; i++)
            adj[i].clear();
        fill_n(taken, n, false);
        int x, y;
        num w;
        while(s--)
            cin >> x, sources.push_back(x-1);
        while(m--)
            cin >> x >> y >> w, adj[x-1].push_back({y-1, w}), adj[y-1].push_back({x-1, w});
        for(int s : sources)
            prim(s);
        num ans = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            num w = pq.top().first;
            pq.pop();
            if(taken[u])
                continue;
            ans += w;
            prim(u);
        }
        cout << ans + (n - sources.size()) * l << endl;
    }
}
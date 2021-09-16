#include <bits/stdc++.h>
using namespace std;

// Cave Exploration

int n, m;
set<int> adj[10003];
int cnt = 1, dfsn[10003], dfsl[10003];

vector<pair<int, int>> bridges;
void dfs(int u, int p){
    dfsn[u] = dfsl[u] = cnt++;
    for(int v : adj[u]){
        if(!dfsn[v]){
            dfs(v, u);
            if(dfsl[v] > dfsn[u])
                bridges.push_back({u, v});
        }
        if(v != p)
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--)
        cin >> x >> y, adj[x].insert(y), adj[y].insert(x);
    dfs(0, -1);
    for(pair<int , int> p : bridges)
        adj[p.first].erase(p.second), adj[p.second].erase(p.first);
    cnt = 1, fill_n(dfsn, n, 0);
    dfs(0, -1);
    cout << cnt - 1 << endl;
}
#include <bits/stdc++.h>
using namespace std;

// Birthday Party

int n, m;
vector<int> adj[103];
int vis[103];
int par[103];
int cnt, dfsn[103], dfsl[103];
bool bridge;

void dfs(int u){
    vis[u] = 1, dfsn[u] = dfsl[u] = cnt++;
    for(int v : adj[u]){
        if(!vis[v]){
            par[v] = u, dfs(v);
            if(dfsl[v] > dfsn[u])
                bridge = true;
        }
        if(v != par[u])
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
    vis[u] = 2;
}

int main(){
    while(1){
        cin >> n >> m;
        if(!(n+m))
            break;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        int x, y;
        while(m--)
            cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
        fill_n(vis, n, 0), fill_n(par, n, -1);
        cnt = 0, bridge = false;
        dfs(0);
        for(int i = 1; i < n; i++)
            if(!vis[i])
                bridge = true;
        cout << (bridge ? "Yes" : "No") << endl;
    }
}
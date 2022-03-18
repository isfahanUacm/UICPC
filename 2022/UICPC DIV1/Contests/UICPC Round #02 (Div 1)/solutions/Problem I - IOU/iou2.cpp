#include <bits/stdc++.h>
using namespace std;

// I.O.U.

int n, m, vis[103], par[103], s, e;
map<int, int> adj[103];

void dfs(int u){
    vis[u] = 1;
    for(pair<int, int> v : adj[u]){
        if(!vis[v.first])
            par[v.first] = u, dfs(v.first);
        else if(vis[v.first] == 1 && s == -1)
            s = v.first, e = u;
    }
    vis[u] = 2;
}

vector<pair<pair<int, int>, int>> ans;

int main(){
    cin >> n >> m;
    int u, v, c;
    while(m--)
        cin >> u >> v >> c, adj[u][v] = c;
    while(1){
        fill_n(vis, n, 0);
        s = -1;
        for(int i = 0; i < n; i++)
            if(!vis[i]){
                dfs(i);
                if(s != -1)
                    break;
            }
        if(s == -1)
            break;
        int w = adj[e][s];
        int it = e;
        while(it != s)
            w = min(w, adj[par[it]][it]), it = par[it];
        adj[e][s] -= w;
        if(!adj[e][s])
            adj[e].erase(s);
        it = e;
        while(it != s){
            adj[par[it]][it] -= w;
            if(!adj[par[it]][it])
                adj[par[it]].erase(it);
            it = par[it];
        }
    }
    for(int i = 0; i < n; i++)
        for(pair<int, int> j : adj[i])
            ans.push_back({{i, j.first}, j.second});
    cout << ans.size() << endl;
    for(pair<pair<int, int>, int> item : ans)
        cout << item.first.first << " " << item.first.second << " " << item.second << endl;
}
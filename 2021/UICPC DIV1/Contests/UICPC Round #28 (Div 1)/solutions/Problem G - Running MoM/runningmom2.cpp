#include <bits/stdc++.h>
using namespace std;

// Running MoM

int n = 0, m;
map<string, int> id;

int gid(string name){
    if(id.find(name) != id.end())
        return id[name];
    return id[name] = n++;
}

vector<int> adj[10003];

int vis[10003];
bool safe;

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
        else if(vis[v] == 1)
            safe = true;
    }
    vis[u] = 2;
}

int main(){
    cin >> m;
    string x, y;
    while(m--)
        cin >> x >> y, adj[gid(x)].push_back(gid(y));
    while(cin >> x){
        fill_n(vis, n, false);
        safe = false;
        dfs(id[x]);
        cout << x << " " << (safe ? "safe" : "trapped") << endl;
    }   
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
bool visited[10003];
int n, m, l, x, y, z, s;

void dfs(int u){
    visited[u] = true;
    s++;
    int v;
    for (int i = 0; i < adj[u].size(); ++i) {
        v = adj[u][i];
        if(!visited[v])
            dfs(v);
    }
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {        
        cin>>n>>m>>l;
        fill_n(visited, n+1, false);
        s = 0;
        adj.clear();
        adj.resize(n+1);
        for (int j = 0; j < m; ++j) {
            cin>>x>>y;
            adj[x].push_back(y);
        }
        for (int j = 0; j < l; ++j) {
            cin>>z;
            if(!visited[z])
                dfs(z);
        }
        cout<<s<<endl;
    }
    return 0;
}


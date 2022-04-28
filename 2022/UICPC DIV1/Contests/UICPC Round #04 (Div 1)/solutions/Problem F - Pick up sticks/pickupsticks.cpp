#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1000003);
int visited[1000003];
int parent[1000003];
int n, m, a, b;
bool res = true;
vector<int> resv;

void dfs(int u){
    visited[u] = 1;
    for (auto v : adj[u]) {
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
            if(!res)
                return;
        }
        else if(visited[v]==1){
            res = false;
            return;
        }
    }
    visited[u]=2;
    resv.push_back(u);
}


int main()
{
    cin>>n>>m;
    fill_n(visited, n+1, 0);
    fill_n(parent, n+1, 0);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= n; ++i) {
        if(!visited[i]){
            dfs(i);
            if(!res)
                break;
        }
    }
    if(!res)
        cout<<"IMPOSSIBLE"<<endl;
    else{
        for (int i = resv.size()-1; i >= 0; i--) {
            cout<<resv[i]<<endl;
        }
    }
    return 0;
}
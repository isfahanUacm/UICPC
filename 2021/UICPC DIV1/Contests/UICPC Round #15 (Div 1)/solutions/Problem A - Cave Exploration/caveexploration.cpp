#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(10003);
int dfs_num[10003], dfs_low[10003];
int parent[10003];
bool visited[10003];
int n, m, a, b, nums, res;
bool bridge[10003][10003];

void findBridge(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    for (auto v:adj[u]) {
        if(dfs_num[v]==-1){
            parent[v] = u;
            findBridge(v);
            if(dfs_low[v] > dfs_num[u]){
                bridge[u][v] = true;
                bridge[v][u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(parent[u] != v){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void dfs(int u){
    visited[u] = true;res++;
    for (auto v: adj[u]) {
        if(!visited[v] && !bridge[u][v]){
            dfs(v);
        }
    }
}


int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bridge[i][j] = false;
        }
    }
    fill_n(dfs_num, n, -1);
    fill_n(dfs_low, n, -1);
    fill_n(parent, n, -1);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    nums = 0;
    findBridge(0);
    fill_n(visited, n, false);
    res = 0;
    dfs(0);
    cout<<res<<endl;
    
    return 0;
}


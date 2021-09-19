#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int dfs_num[103], dfs_low[103];
int parent[103]; 
int p, c, a, b;
bool ans = false;
int nums;
void findBridge(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    for (auto v:adj[u]) {
        if(dfs_num[v]==-1){
            parent[v] = u;
            findBridge(v);
            if(ans)
                return;
            if(dfs_low[v] > dfs_num[u]){
                ans = true;
                return;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(parent[u] != v){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    while(true){
        cin>>p>>c;
        if(p==0 && c==0)
            break;
        adj.clear();
        adj.resize(p);
        fill_n(dfs_num, p, -1);
        fill_n(dfs_low, p, -1);
        fill_n(parent, p, -1);
        for (int i = 0; i < c; ++i) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans = false;
        nums = 0;
        findBridge(0);
        for (int i = 0; i < p; ++i) {
            if(dfs_num[i]==-1)
                ans = true;
        }
        cout<<((ans)?"Yes":"No")<<endl;
    }
    return 0;
}


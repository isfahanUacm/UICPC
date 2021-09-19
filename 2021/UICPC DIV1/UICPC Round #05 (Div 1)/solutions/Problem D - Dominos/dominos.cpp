#include <bits/stdc++.h>
using namespace std;

int compo[100003];
vector<vector<int>> adj, adj2;
int dfs_num[100003], dfs_low[100003];
bool visited[100003];
int t, n, m, x, y, scc=0, nums = 0;
vector<int> s;

void calc(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    s.push_back(u);visited[u]=true;
    for (auto v: adj[u]) {
        if(dfs_num[v] == -1)
            calc(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        scc++;
        int w;
        while(true){
            w=s.back();s.pop_back();visited[w]=false;
            compo[w] = scc;
            if(w==u)
                break;
        }
    }
}

int main()
{
    cin>>t;
    while (t--) {
        cin>>n>>m;
        fill_n(dfs_num, n+1, -1);
        fill_n(dfs_low, n+1, -1);
        fill_n(visited, n+1, false);
        adj.clear();
        adj.resize(n+1);
        for (int i = 0; i < m; ++i) {
            cin>>x>>y;
            adj[x].push_back(y);
        }
        fill_n(compo, n+1, 0);
        nums = 0;
        scc = 0;
        for (int i = 1; i <= n; ++i)
            if(dfs_num[i] == -1)
                calc(i);
        bool indeg[scc+1];
        fill_n(indeg, scc+1, true);
        adj2.clear();
        adj2.resize(scc+1);
        for (int i = 1; i < n+1; ++i) {
            for (auto j : adj[i]) {
                if(compo[i]!=compo[j])
                    adj2[compo[i]].push_back(compo[j]);
            }
        }
        for (int i = 1; i < scc+1; ++i) {
            for (auto j: adj2[i]) {
                indeg[j] = false;
            }
        }
        int res = 0;
        for (int i = 1; i < scc+1; ++i) {
            if(indeg[i])res++;
        }
        cout<<res<<endl;
    }
    return 0;
}


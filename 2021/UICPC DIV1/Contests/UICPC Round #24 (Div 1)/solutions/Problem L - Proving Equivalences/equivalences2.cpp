#include <bits/stdc++.h>
using namespace std;

// Proving Equivalences

const int maxn = 2e5 + 3;

int n, m;
vector<int> adj[maxn], adjr[maxn];

int cnt, dfsn[maxn], dfsl[maxn];
bool vis[maxn];
stack<int> scc;
vector<vector<int>> sccs;

void dfs(int u){
    dfsn[u] = dfsl[u] = cnt++;
    vis[u] = 1;
    scc.push(u);
    for(int v : adj[u]){
        if(!dfsn[v])
            dfs(v);
        if(vis[v])
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
    if(dfsl[u] == dfsn[u]){
        vector<int> v;
        while(true){
            int x = scc.top();
            scc.pop();
            vis[x] = 0;
            v.push_back(x);
            if(x == u)
                break;
        }
        sccs.push_back(v);
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            adj[i].clear(), adjr[i].clear();
        int x, y;
        while(m--)
            cin >> x >> y, x--, y--, adj[x].push_back(y), adjr[y].push_back(x);
        cnt = 1;
        fill_n(dfsn, n, 0);
        sccs.clear();
        for(int i = 0; i < n; i++)
            if(!dfsn[i])
                dfs(i);
        if(sccs.size() == 1){
            cout << 0 << endl;
            continue;
        }
        int ans1 = 0, ans2 = 0;
        for(vector<int> scc : sccs){
            int indeg = 0, outdeg = 0;
            for(int u : scc){
                for(int v : adj[u])
                    if(dfsl[v] != dfsl[u])
                        indeg++;
                for(int v : adjr[u])
                    if(dfsl[v] != dfsl[u])
                        outdeg++;
            }
            if(!indeg)
                ans1++;
            if(!outdeg)
                ans2++;
        }
        cout << max(ans1, ans2) << endl;       
    }
}
#include <bits/stdc++.h>
using namespace std;

// Dominos

const int maxn = 1e5 + 3;

int n, m;
vector<int> adj[maxn], radj[maxn];

int cnt;
int dfsn[maxn], dfsl[maxn];
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
            adj[i].clear(), radj[i].clear();
        int x, y;
        while(m--)
            cin >> x >> y, x--, y--, adj[x].push_back(y), radj[y].push_back(x);
        cnt = 1;
        fill_n(dfsn, n, 0);
        sccs.clear();
        for(int i = 0; i < n; i++)
            if(!dfsn[i])
                dfs(i);
        int ans = 0;
        for(vector<int> scc : sccs){
            bool ok = true;
            for(int u : scc){
                for(int v : radj[u])
                    if(dfsl[v] != dfsl[u]){
                        ok = false;
                        break;
                    }
                if(!ok)
                    break;
            }
            if(ok)
                ans++;
        }
        cout << ans << endl;
    }
}
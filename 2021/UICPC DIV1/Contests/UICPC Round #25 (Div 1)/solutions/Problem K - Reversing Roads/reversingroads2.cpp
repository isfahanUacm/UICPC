#include <bits/stdc++.h>
using namespace std;

// Reversing Roads

int n, m;
pair<int, int> edges[50 * 50 + 3];
vector<int> adj[53];

int cnt, sccs, dfsn[53], dfsl[53];
bool vis[53];
stack<int> scc;
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
        sccs++;
        while(1){
            int v = scc.top();
            scc.pop();
            vis[v] = 0;
            if(v == u)
                break;
        }
    }
}

int main(){
    int t = 1;
    while(cin >> n >> m){
        cout << "Case " << t++ << ": ";
        for(int i = 0; i < m; i++)
            cin >> edges[i].first >> edges[i].second;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        for(int i = 0;  i < m; i++)
            adj[edges[i].first].push_back(edges[i].second);
        cnt = 1, sccs = 0;
        fill_n(dfsn, n, 0);
        for(int i = 0; i < n; i++)
            if(!dfsn[i])
                dfs(i);
        if(sccs == 1){
            cout << "valid" << endl;
            continue;
        }
        bool ok = false;
        for(int ig = 0; ig < m; ig++){
            for(int i = 0; i < n; i++)
                adj[i].clear();
            for(int i = 0; i < m; i++){
                if(i != ig)
                    adj[edges[i].first].push_back(edges[i].second);
                else adj[edges[i].second].push_back(edges[i].first);
            }
            cnt = 1, sccs = 0;
            fill_n(dfsn, n, 0);
            for(int i = 0; i < n; i++)
                if(!dfsn[i])
                    dfs(i);
            if(sccs == 1){
                cout << edges[ig].first << " " << edges[ig].second << endl;
                ok = true;
                break;
            }
        }
        if(!ok)
            cout << "invalid" << endl;
    }
}
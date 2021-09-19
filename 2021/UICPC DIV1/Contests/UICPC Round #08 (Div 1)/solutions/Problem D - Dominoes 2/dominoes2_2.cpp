#include <bits/stdc++.h>
using namespace std;

// Dominoes 2

int n, m, l;
vector<int> adj[10003];
bool vis[10003];

int ans;
void dfs(int u){
    if(vis[u])
        return;
    vis[u] = true, ans++;
    for(int v : adj[u])
        dfs(v);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> l;
        for(int i = 0; i < n; i++)
            adj[i].clear();
        fill_n(vis, n, false);
        int x, y;
        while(m--)
            cin >> x >> y, adj[x-1].push_back(y-1);
        ans = 0;
        while(l--)
            cin >> x, dfs(x-1);
        cout << ans << endl;
    }
}
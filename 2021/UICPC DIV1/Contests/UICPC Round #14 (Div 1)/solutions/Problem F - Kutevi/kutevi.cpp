#include <bits/stdc++.h>
using namespace std;

// Kutevi

int n, k;
vector<int> adj[360];
bool vis[360];

void dfs(int k){
    vis[k] = true;
    for(int v : adj[k])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin >> n >> k;
    int x;
    while(n--){
        cin >> x;
        for(int i = 0; i < 360; i++)
            adj[i].push_back((i + x) % 360), adj[i].push_back((i - x + 360) % 360);
    }
    fill_n(vis, n, false);
    dfs(0);
    while(k--){
        cin >> x;    
        cout << (vis[x] ? "YES" : "NO") << endl;
    }
}
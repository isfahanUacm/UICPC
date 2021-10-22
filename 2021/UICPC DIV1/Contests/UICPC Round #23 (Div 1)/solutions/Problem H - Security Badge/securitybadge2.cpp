#include <bits/stdc++.h>
using namespace std;

// Security Badge

int n, m, b, s, d;
vector<pair<int, pair<int, int>>> adj[1003];
set<int> chunks;

bool vis[1003];
int lo, hi;

void dfs(int u){
    vis[u] = true;
    for(auto v : adj[u])
        if(lo >= v.second.first && hi <= v.second.second && !vis[v.first])
            dfs(v.first);
}

int main(){
    cin >> n >> m >> b >> s >> d;
    int x, y, l, u;
    while(m--)
        cin >> x >> y >> l >> u, adj[x].push_back({y, {l, u}}), chunks.insert(l), chunks.insert(u);
    chunks.insert(1), chunks.insert(b);
    int ans = 0;
    for(int c : chunks){
        fill_n(vis, n+1, false);
        lo = hi = c;
        dfs(s);
        if(vis[d])
            ans++;
    }
    for(auto it = chunks.begin(); next(it) != chunks.end(); it++){
        lo = *it + 1, hi = *next(it)-1;
        if(lo > hi)
            continue;
        fill_n(vis, n+1, false);
        dfs(s);
        if(vis[d])
            ans += hi - lo + 1;
    }
    cout << ans << endl;
}
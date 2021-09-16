#include <bits/stdc++.h>
using namespace std;

// Adjoin the Networks

const int maxn = 1e5 + 3;

int n, m;
vector<int> adj[maxn];
bool vis[maxn];

int max_depth, farest;

void dfs(int u, int p, int d){
    vis[u] = true;
    if(d > max_depth)
        max_depth = d, farest = u;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u, d+1);
}

vector<int> networks;

int main(){
    int x, y;
    cin >> n >> m;
    while(m--)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(!vis[i]){
            max_depth = -1;
            dfs(i, -1, 0);
            max_depth = -1;
            dfs(farest, -1, 0);
            ans = max(ans, max_depth);
            networks.push_back(max_depth / 2 + max_depth % 2);
        }
    sort(networks.begin(), networks.end(), greater<int>());
    if(networks.size() >= 2)
        ans = max(ans, networks[0] + networks[1] + 1);
    if(networks.size() >= 3)
        ans = max(ans, networks[1] + networks[2] + 2);
    cout << ans << endl;
}
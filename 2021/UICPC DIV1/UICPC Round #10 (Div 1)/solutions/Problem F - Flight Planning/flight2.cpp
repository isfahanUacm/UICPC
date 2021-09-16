#include <bits/stdc++.h>
using namespace std;

// Flight Planning

int n;
set<int> adj[2503];
vector<pair<int, int>> edges;

int max_height, farest;

void dfs(int u, int p, int d){
    if(d > max_height)
        max_height = d, farest = u;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u, d+1);
}

int par[2503];

void dfs2(int u, int d){
    if(d == max_height)
        farest = u;
    for(int v : adj[u])
        if(v != par[u])
            par[v] = u, dfs2(v, d+1);
}

vector<int> path;

int main(){
    int x, y;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y, x--, y--;
        adj[x].insert(y);
        adj[y].insert(x);
        edges.push_back({x, y});
    }
    int ans = INT_MAX, af1, afh, af2, ash;
    pair<int, int> del;
    for(pair<int, int> e : edges){
        adj[e.first].erase(e.second), adj[e.second].erase(e.first);
        max_height = -1;
        dfs(e.first, -1, 0);
        int f1 = farest;
        dfs(f1, -1, 0);
        int fh = max_height;
        max_height = -1;
        dfs(e.second, -1, 0);
        int f2 = farest;
        dfs(f2, -1, 0);
        int sh = max_height;
        int curr = fh / 2 + fh % 2 + sh / 2 + sh % 2 + 1;
        curr = max(curr, fh), curr = max(curr, sh);
        if(curr < ans)
            ans = curr, af1 = f1, afh = fh, af2 = f2, ash = sh, del = e;
        adj[e.first].insert(e.second), adj[e.second].insert(e.first);        
    }
    cout << ans << endl;
    cout << del.first + 1 << " " << del.second + 1 << endl;
    adj[del.first].erase(del.second), adj[del.second].erase(del.first);
    max_height = afh;
    fill_n(par, n, -1);
    dfs2(af1, 0);
    path.clear();
    int it = farest;
    while(it != -1)
        path.push_back(it), it = par[it];
    cout << path[afh / 2] + 1 << " ";
    max_height = ash;
    fill_n(par, n, -1);
    dfs2(af2, 0);
    path.clear();
    it = farest;
    while(it != -1)
        path.push_back(it), it = par[it];
    cout << path[ash / 2] + 1 << endl;
}
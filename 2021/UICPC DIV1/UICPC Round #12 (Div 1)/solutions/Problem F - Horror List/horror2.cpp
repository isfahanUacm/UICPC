#include <bits/stdc++.h>
using namespace std;

// Horror List

const int maxn = 1e3 + 3;
const int inf = INT_MAX;

int n, h, l, dist[maxn];
vector<int> adj[maxn];
queue<int> bfs;

int main(){
    cin >> n >> h >> l;
    fill_n(dist, n, inf);
    int x, y;
    while(h--)
        cin >> x, dist[x] = 0, bfs.push(x);
    while(l--)
        cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dist[v] == inf)
                dist[v] = dist[u] + 1, bfs.push(v);
    }
    int ans = -1, best = 0;
    for(int i = 0; i < n; i++)
        if(dist[i] > best)
            ans = i, best = dist[i];
    cout << ans << endl;
}
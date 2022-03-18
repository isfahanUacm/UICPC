#include <bits/stdc++.h>
using namespace std;
#define Explored 1
#define Visited 2
#define Unvisited 0

int n, m, a, b, c;
vector<pair<int,pair<int, int>>> adj[103];
vector<pair<int, pair<int, int>>> edges;
int visited[103];
bool exedge[10003];
int loss;
int exedgevis = 0;
int explor[103];

void dfs2(int u, int targ){
    if(targ == adj[u][explor[u]].second.first)
        return;
    loss = min(loss, adj[u][explor[u]].second.second);
    dfs2(adj[u][explor[u]].second.first, targ);
}

bool dfs(int u){
    visited[u] = Explored;
    for (int vi = 0; vi < adj[u].size(); vi++) {
        auto& v = adj[u][vi];
        if(exedge[v.first])
            continue;
        int vj = v.second.first;
        int w =  v.second.second;
        if(visited[vj] == Unvisited){
            explor[u] = vi;
            if(dfs(vj)){
                v.second.second -= loss;
                edges[v.first].second.second -= loss;
                if(!v.second.second)
                    exedge[v.first] = true, exedgevis++;
                visited[vj] = Unvisited;
                if(visited[u] == Explored)
                    return true;
                else{
                    visited[u] = Explored;
                    vi--;
                }
            }
        }
        else if(visited[vj] == Explored){
            loss = w;
            explor[u] = vi;
            dfs2(vj, vj);
            v.second.second -= loss;
            edges[v.first].second.second -= loss;
            if(!v.second.second)
                exedge[v.first] = true, exedgevis++;
            visited[vj] = Unvisited;
            return true;
        }
    }
    visited[u] = Visited;
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({i,{b, c}});
        edges.push_back({a, {b, c}});
    }
    for (int i = 0; i < n; ++i) {
        while(!visited[i]){
            dfs(i);
        }
    }
    cout << m-exedgevis << endl;
    for (int i = 0; i < m; ++i) {
        if(!exedge[i]){
            cout << edges[i].first << " " << edges[i].second.first << " " << edges[i].second.second << endl;
        }
    }
    return 0;
}


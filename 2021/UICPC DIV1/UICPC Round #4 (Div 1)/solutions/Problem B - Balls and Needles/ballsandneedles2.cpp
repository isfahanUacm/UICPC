#include <bits/stdc++.h>
using namespace std; 

// Balls and Needles

int n1 = 0;
map<pair<pair<int, int>, int>, int> id; 

inline int gid(int x, int y, int z){
    if(id.find({{x, y}, z}) != id.end())
        return id[{{x, y}, z}];
    return id[{{x, y}, z}] = n1++;
}

vector<int> adj[2 * 50000 + 3];
int vis[2 * 50000 + 3];
int parent[2 * 50000 + 3];
bool cycle = false;

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v])
            parent[v] = u, dfs(v);
        else if(vis[v] == 1 && parent[u] != v)
            cycle = true;
    }
    vis[u] = 2;
}


int n2 = 0;
map<pair<int, int>, int> id2;

inline int gid2(int x, int y){
    if(id2.find({x, y}) != id2.end())
        return id2[{x, y}];
    return id2[{x, y}] = n2++;
}

vector<int> adj2[2 * 50000 + 3];
int vis2[2 * 50000 + 3];
int parent2[2 * 50000 + 3];
bool cycle2 = false;

void dfs2(int u){
    vis2[u] = 1;
    for(int v : adj2[u]){
        if(!vis2[v])
            parent2[v] = u, dfs2(v);
        else if(vis2[v] == 1 && parent2[u] != v)
            cycle2 = true;
    }
    vis2[u] = 2;
}

int main(){
    int n, x1, y1, z1, x2, y2, z2;
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int g1 = gid(x1, y1, z1), g2 = gid(x2, y2, z2);
        if(g1 != g2)
            adj[g1].push_back(g2), adj[g2].push_back(g1);
        g1 = gid2(x1, y1), g2 = gid2(x2, y2);
        if(g1 != g2)
            adj2[g1].push_back(g2), adj2[g2].push_back(g1);
    }
    fill_n(parent, n1, -1), fill_n(parent2, n2, -1);
    for(int i = 0; i < n1; i++)
        if(!vis[i])
            dfs(i);
    for(int i = 0; i < n2; i++)
        if(!vis2[i])
            dfs2(i);
    cout << (cycle ? "True closed chains" : "No true closed chains") << endl;
    cout << (cycle2 ? "Floor closed chains" : "No floor closed chains") << endl;
}
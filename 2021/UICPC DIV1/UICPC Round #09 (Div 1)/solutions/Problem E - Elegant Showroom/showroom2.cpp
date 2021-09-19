#include <bits/stdc++.h>
using namespace std;

// Elegant Showroom

int R, C;
char grid[403][403];

inline int hash_node(int x, int y){
    return x * C + y;
}

int adjR[4]{1, -1, 0, 0};
int adjC[4]{0, 0, 1, -1};
int n;
vector<pair<int, int>> adj[160003];

void make_node(int x, int y){
    int w = grid[x][y] == 'c';
    int node = hash_node(x, y);
    for(int k = 0; k < 4; k++){
        int nx = x + adjR[k];
        int ny = y + adjC[k];
        if(nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != '#')
            adj[node].push_back({hash_node(nx, ny), w});
    }
}

#define inf INT_MAX
int dis[160003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int s){
    for(int i = 0; i < 160003; i++)
        dis[i] = inf;
    dis[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto i = pq.top();
        pq.pop();
        int u = i.second;
        int d = i.first;
        if(d > dis[u])
            continue;
        for(auto p : adj[u]){
            int v = p.first;
            int w = p.second;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int srcx, srcy, src;

int main(){
    cin >> R >> C;
    n = R*C + 1;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> grid[i][j];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(grid[i][j] != '#')
                make_node(i, j);
    for(int i = 0; i < R; i++){
        if(grid[i][0] == 'D')
            adj[hash_node(i, 0)].push_back({n-1, 0});
        if(grid[i][C-1] == 'D')
            adj[hash_node(i, C-1)].push_back({n-1, 0});
    }
    for(int j = 0; j < C; j++){
        if(grid[0][j] == 'D')
            adj[hash_node(0, j)].push_back({n-1, 0});
        if(grid[R-1][j] == 'D')
            adj[hash_node(R-1, j)].push_back({n-1, 0});
    }
    cin >> srcx >> srcy;
    src = hash_node(srcx-1, srcy-1);
    dijkstra(src);
    cout << dis[n-1] << endl;
}
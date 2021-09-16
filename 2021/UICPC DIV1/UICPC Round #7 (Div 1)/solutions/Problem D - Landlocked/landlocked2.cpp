#include <bits/stdc++.h>
using namespace std;

// Landlocked

int adjR[8]{0, 0, -1, 1, -1, -1, 1, 1};
int adjC[8]{1, -1, 0, 0, -1, 1, -1, 1};

int n, m;
char g[1003][1003];
int cc = 0, id[1003][1003];
char region[1000003];

void dfs(int i, int j){
    id[i][j] = cc;
    for(int k = 0; k < 8; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == g[i][j] && !id[x][y])
            dfs(x, y);
    }
}

bool vis[1003][1003];
set<int> adj[1000003];

void dfs2(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 8; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m){
            if(g[x][y] != g[i][j])
                adj[id[i][j]].insert(id[x][y]);
            else if(!vis[x][y])
                dfs2(x, y);
        }
    }
}

int dis[1000003];
queue<int> bfs;
map<char, int> ans;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!id[i][j])
                cc++, region[cc] = g[i][j], dfs(i, j);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j])
                dfs2(i, j);
    fill_n(dis, cc + 1, INT_MAX);
    for(int i = 1; i <= cc; i++)
        if(region[i] == 'W')
            dis[i] = -1, bfs.push(i);
    while(!bfs.empty()){
        int u = bfs.front();
        bfs.pop();
        for(int v : adj[u])
            if(dis[v] == INT_MAX)
                dis[v] = dis[u] + 1, bfs.push(v);
    }
    for(int i = 1; i <= cc; i++)
        ans[region[i]] = INT_MAX;
    for(int i = 1; i <= cc; i++)
        ans[region[i]] = min(ans[region[i]], dis[i]);
    for(pair<char, int> p : ans)
        if(p.first != 'W')
            cout << p.first << " " << p.second << endl;
}
#include <bits/stdc++.h>
using namespace std;

// Car Vet

int n, m, g[253][253];
bool vis[253][253];
pair<int, int> par[253][253];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};


void dfs(int x, int y){
    vis[x][y] = true;
    vector<pair<int, pair<int, int>>> adj;
    for(int k = 0; k < 4; k++){
        int p = x + adjR[k], q = y + adjC[k];
        int u = x + 2 * adjR[k], v = y + 2 * adjC[k];
        if(p >= 0 && p < n && q >= 0 && q < m && u >= 0 && u < n && v >= 0 && v < m && g[p][q] != -2 && g[p][q] == g[u][v])
            adj.push_back({g[p][q], {u, v}}); 
    }
    sort(adj.begin(), adj.end());
    for(auto p : adj){
        if(!vis[p.second.first][p.second.second])
            par[p.second.first][p.second.second] = {x, y}, dfs(p.second.first, p.second.second);
    }
}

vector<int> path;

int main(){
    cin >> n >> m;
    pair<int, int> src, dst;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            par[i][j] = {-1, -1};
            cin >> g[i][j];
            if(g[i][j] == -1)
                src = {i, j};
        }
    cin >> dst.first >> dst.second, dst.first--, dst.second--;
    dfs(src.first, src.second);
    if(!vis[dst.first][dst.second]){
        cout << "impossible" << endl;
        return 0;
    }
    int itx = dst.first, ity = dst.second;
    while(!(itx == src.first && ity == src.second)){
        path.push_back(g[itx][ity]);
        pair<int, int> p = par[itx][ity];
        itx = p.first, ity = p.second;
    }
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}
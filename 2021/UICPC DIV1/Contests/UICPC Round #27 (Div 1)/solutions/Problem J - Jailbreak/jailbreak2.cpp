#include <bits/stdc++.h>
using namespace std;

// Jailbreak

int n, m;
char grid[103][103];
vector<pair<int, int>> adj[10003];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

int dis[3][10003];
priority_queue<pair<int, pair<int ,int>>, vector<pair<int, pair<int ,int>>>, greater<pair<int, pair<int ,int>>>> q;

int main(){
    int t;
    cin >> t;
    while(t--){   
        cin >> n >> m;
        vector<int> src;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '$')
                    src.push_back(i * m + j);
            }
        for(int i = 0; i <= n * m; i++)
            adj[i].clear();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] != '*'){
                    int w = grid[i][j] == '#';
                    for(int k = 0; k < 4; k++){
                        int x = i + adjR[k], y = j + adjC[k];
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '*')
                            adj[i * m + j].push_back({w, x * m + y});
                    }
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                        adj[i * m + j].push_back({w, n * m});
                }
        for(int k = 0; k < 3; k++)
            for(int i = 0; i <= n * m; i++)
                dis[k][i] = INT_MAX;
        dis[0][src[0]] = 0, dis[1][src[1]] = 0;
        q.push({0, {src[0], 0}}), q.push({0, {src[1], 1}});
        while(!q.empty()){
            int p = q.top().first, u = q.top().second.first, s = q.top().second.second;
            q.pop();
            if(dis[s][u] < p)
                continue;
            for(pair<int, int> vv : adj[u]){
                int w = vv.first, v = vv.second;
                if(p + w < dis[s][v])
                    dis[s][v] = p + w, q.push({p+w, {v, s}});
            }
            if(s != 2)
                for(pair<int, int> vv : adj[u]){
                    int w = vv.first, v = vv.second;
                    if(dis[1-s][v] == INT_MAX)
                        continue;
                    if(p + w + dis[1-s][v] < dis[2][v])
                        dis[2][v] = p + w + dis[1-s][v], q.push({p+w+dis[1-s][v], {v, 2}});
                }
        }
        cout << dis[2][n*m] << endl;
    }
}
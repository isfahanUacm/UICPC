#include <bits/stdc++.h>
using namespace std;

// Zoning

#define inf INT_MAX

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

int n;
char g[1503][1503];
int dis[1503][1503];
queue<pair<int, int>> bfs;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <n; j++){
            cin >> g[i][j];
            dis[i][j] = inf;
            if(g[i][j] == '3')
                dis[i][j] = 0, bfs.push({i, j}); 
        }
    int ans = INT_MIN;
    while(!bfs.empty()){
        pair<int, int> u = bfs.front();
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int x = u.first + adjR[k], y = u.second + adjC[k];
            if(x >= 0 && x < n && y >= 0 && y < n && dis[x][y] == inf){
                dis[x][y] = dis[u.first][u.second] + 1, bfs.push({x, y});
                if(g[x][y] == '1')
                    ans = max(ans, dis[x][y]);
            }
        }
    }
    cout << ans << endl;
}
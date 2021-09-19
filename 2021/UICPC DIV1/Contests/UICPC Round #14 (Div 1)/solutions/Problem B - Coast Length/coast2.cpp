#include <bits/stdc++.h>
using namespace std;

// Coast Length

int n, m;
char grid[1003][1003];
bool vis[1003][1003];

int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, 1, -1};

int ans = 0;
void dfs(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1'){
            if(!vis[x][y])
                dfs(x, y);
        }
        else ans += 1;
    }
}

int cnt;
bool p;
void dfs2(int i, int j){
    vis[i][j] = true;
    int nadj = 0;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m){
            nadj++;
            if(grid[x][y] == '1')
                cnt += 1;
            else if(!vis[x][y])
                dfs2(x, y);
        }
    }
    if(nadj != 4)
        p = false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], vis[i][j] = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == '1' && !vis[i][j])
                dfs(i, j);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == '0' && !vis[i][j]){
                cnt = 0, p = true;
                dfs2(i, j);
                if(p)
                    ans -= cnt;
            }
    cout << ans << endl;
}
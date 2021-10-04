#include <bits/stdc++.h>
using namespace std;

// Counting Stars

int n, m;
char grid[103][103];
bool vis[103][103];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

void dfs(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '-' && !vis[x][y])
            dfs(x, y);
    }
}

int main(){
    int test = 1;
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j], vis[i][j] = false;
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '-' && !vis[i][j])
                    ans++, dfs(i, j);
        cout << "Case " << test++ << ": " << ans << endl;
    }
}
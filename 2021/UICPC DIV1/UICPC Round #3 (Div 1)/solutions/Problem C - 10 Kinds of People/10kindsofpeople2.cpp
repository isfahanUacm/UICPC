#include <bits/stdc++.h>
using namespace std;

// 10 Kinds of People

int n, m, cnt = 0;
char grid[1003][1003];
int id[1003][1003];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

char c;
void dfs(int i, int j){
    id[i][j] = cnt;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && id[x][y] == -1 && grid[x][y] == c)
            dfs(x, y);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j], id[i][j] = -1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(id[i][j] == -1)
                c = grid[i][j], dfs(i, j), cnt++;
    int q, sx, sy, dx, dy;
    cin >> q;
    while(q--){
        cin >> sx >> sy >> dx >> dy, sx--, sy--, dx--, dy--;
        if(id[sx][sy] != id[dx][dy])
            cout << "neither" << endl;
        else cout << (grid[sx][sy] - '0' ? "decimal" : "binary") << endl;      
    }
}
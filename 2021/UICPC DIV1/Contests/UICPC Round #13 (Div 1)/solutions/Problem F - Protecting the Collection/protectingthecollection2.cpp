#include <bits/stdc++.h>
using namespace std;

// Protecting the Collection

const int maxn = 2003;

int n, c, r;
string g[maxn][maxn];
bool vis[maxn][maxn][3][4+3];

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

inline int change_dir(string c, int dir){
    if(c == "/"){
        if(dir == 2)
            return 1;
        if(dir == 1)
            return 2;
        if(dir == 0)
            return 3;
        return 0;
    }
    if(dir == 2)
        return 0;
    if(dir == 0)
        return 2;
    if(dir == 1)
        return 3;
    return 1;
}

void dfs(int i, int j, bool m, int dir){
    vis[i][j][m][dir] = 1;
    if(j == n)
        return;
    int tmp = dir;
    if(g[i][j] != ".")
        tmp = change_dir(g[i][j], dir);
    int x = i + adjR[tmp], y = j + adjC[tmp];
    if(x >= 0 && x < n && y >= 0 && y <= n && !vis[x][y][m][tmp])
        dfs(x, y, m, tmp);
    if(m && g[i][j] == "."){
        tmp = change_dir("/", dir);
        x = i + adjR[tmp], y = j + adjC[tmp];
        if(x >= 0 && x < n && y >= 0 && y <= n && !vis[x][y][0][tmp])
            dfs(x, y, 0, tmp);
        tmp = change_dir("\\", dir);
        x = i + adjR[tmp], y = j + adjC[tmp];
        if(x >= 0 && x < n && y >= 0 && y <= n && !vis[x][y][0][tmp])
            dfs(x, y, 0, tmp);
    }
}

int main(){
    cin >> n >> c >> r, c--, r--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    dfs(0, c, 1, 2);
    cout << ((vis[r][n][0][0] || vis[r][n][1][0]) ? "YES" : "NO") << endl;
}
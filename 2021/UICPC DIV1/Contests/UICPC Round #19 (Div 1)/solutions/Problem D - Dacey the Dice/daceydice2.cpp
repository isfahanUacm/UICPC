#include <bits/stdc++.h>
using namespace std;

// Dacey the Dice

int t, n, sx, sy;
char grid[23][23];
bool vis[23][23][9][9];

int adjR[4]{0, 0, -1, 1}, adjC[4]{-1, 1, 0, 0};
int a[24 * 3]{1, 2, 4, 1, 3, 2, 1, 4, 5, 1, 5, 3, 2, 1, 3, 2, 3, 6, 2, 4, 1, 2, 6, 4,
              3, 1, 5, 3, 2, 1, 3, 5, 6, 3, 6, 2, 4, 1, 2, 4, 2, 6, 4, 5, 1, 4, 6, 5,
              5, 1, 4, 5, 3, 1, 5, 4, 6, 5, 6, 3, 6, 2, 3, 6, 3, 5, 6, 4, 2, 6, 5, 4};
int b[9][9];

bool ans;
void dfs(int i, int j, int u, int l){
    if(ans)
        return;
    vis[i][j][u][l] = true;
    if(grid[i][j] == 'H' && u == 2){
        ans = true;
        return;
    }
    for(int k = 0; k < 4; k++){
        int ni = i + adjR[k], nj = j + adjC[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != '*'){
            int m = b[u][l], nu, nl;
            if(k == 0)
                nu = 7 - l, nl = u;
            if(k == 1)
                nu = l, nl = 7-u;
            if(k == 2)
                nu = m, nl = l;
            if(k == 3)
                nu = 7-m, nl = l;
            if(!vis[ni][nj][nu][nl])
                dfs(ni, nj, nu, nl);
        }
    }
}

int main(){
    for(int i = 0; i < 24 * 3; i += 3)
        b[a[i]][a[i+1]] = a[i+2];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'S')
                    sx = i, sy = j;
                for(int u = 1; u <= 6; u++)
                    for(int l = 1; l <= 6; l++)
                        vis[i][j][u][l] = false;
            }
        ans = false;
        dfs(sx, sy, 1, 5);
        cout << (ans ? "Yes" : "No") << endl;
    }
}
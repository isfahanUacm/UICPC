#include <bits/stdc++.h>
using namespace std;

// Finding Connected Components

// O(V + E)

int n, m, q, cc = 0;
bool vis[1003][1003];
int id[1003][1003];
char grid[1003][1003];
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {1, 0, -1, 0};
bool inrange(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int uy, int ux){
    vis[uy][ux] = true;
    id[uy][ux] = cc;
    for(int i = 0; i < 4; i++){
        int newy = uy + dirr[i], newx = ux + dirc[i];
        if(inrange(newy, newx) && grid[newy][newx] == grid[uy][ux] && !vis[newy][newx])
            dfs(newy, newx);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for(int uy = 0; uy < n; uy++)
        for(int ux = 0; ux < m; ux ++)
            if(!vis[uy][ux]){
                dfs(uy, ux);
                cc++;
            }
    cin >> q;
    int r1, c1, r2, c2;
    for (int i = 0; i < q; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, r2--, c1--, c2--;
        if(id[r1][c1] == id[r2][c2]){
            if(grid[r1][c1] == '0'){
                cout << "binary" << endl;
            }
            else{
                cout << "decimal" << endl;
            }
        }
        else{
            cout << "neither" << endl;
        }
    }
}

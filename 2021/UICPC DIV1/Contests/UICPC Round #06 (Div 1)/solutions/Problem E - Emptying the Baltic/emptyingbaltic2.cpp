#include <bits/stdc++.h>
using namespace std;

// Emptying the Baltic

int n, m, g[503][503]; 
priority_queue<pair<int, pair<int, int>>> dij;

int adjR[8]{0, 0, 1, -1, 1, 1, -1, -1};
int adjC[8]{1, -1, 0, 0, 1, -1, 1, -1};

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j], g[i][j] *= -1;
    int x, y;
    cin >> x >> y, x--, y--;
    dij.push({g[x][y], {x, y}});
    long long int ans = 0;
    while(!dij.empty()){
        int ux = dij.top().second.first, uy = dij.top().second.second, w = dij.top().first;
        dij.pop();
        if(g[ux][uy] <= 0)
            continue;
        g[ux][uy] = 0;
        ans += w;
        for(int k = 0; k < 8; k++){
            int vx = ux + adjR[k], vy = uy + adjC[k];
            if(vx >= 0 && vx < n && vy >= 0 && vy < m && g[vx][vy] > 0)
                dij.push({min(w, g[vx][vy]), {vx, vy}});
        }
    }
    cout << ans << endl;
}
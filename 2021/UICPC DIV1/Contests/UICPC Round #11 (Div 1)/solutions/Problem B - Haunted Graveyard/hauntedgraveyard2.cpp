#include <bits/stdc++.h>
using namespace std;

// Haunted Graveyard

#define inf INT_MAX

int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};

int w, h, g, e;
char grid[33][33];
int r[33][33], c[33][33], t[33][33];
long long int dis[33][33];

int main(){
    while(1){
        cin >> w >> h;
        if(!(w + h))
            break;
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                grid[i][j] = '.', dis[i][j] = inf;
        cin >> g;
        int x, y;
        while(g--)
            cin >> x >> y, grid[x][y] = '#';
        cin >> e;
        while(e--)
            cin >> x >> y, grid[x][y] = '@', cin >> r[x][y] >> c[x][y] >> t[x][y];
        dis[0][0] = 0;
        bool ngc = false;
        for(int _ = 0; _ < w * h; _++)
            for(int i = 0; i < w; i++)
                for(int j = 0; j < h; j++){
                    if(dis[i][j] == inf || (i == w - 1 && j == h - 1))
                        continue;
                    if(grid[i][j] == '.'){
                        for(int k = 0; k < 4; k++){
                            int x = i + adjR[k], y = j + adjC[k];
                            if(x >= 0 && x < w && y >= 0 && y < h && grid[x][y] != '#'){
                                if(_ == w * h - 1 && dis[i][j] + 1 < dis[x][y])
                                    ngc = true;
                                dis[x][y] = min(dis[x][y], dis[i][j] + 1);
                            }
                        }
                    }
                    else if(grid[i][j] == '@'){
                        int x = r[i][j], y = c[i][j];
                        if(_ == w * h - 1 && dis[i][j] + t[i][j] < dis[x][y])
                            ngc = true;
                        dis[x][y] = min(dis[x][y], dis[i][j] + t[i][j]);
                    }
                }
        if(ngc)
            cout << "Never" << endl;
        else if(dis[w-1][h-1] == inf)
            cout << "Impossible" << endl;
        else
            cout << dis[w-1][h-1] << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

// Lava

#define inf INT_MAX
int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};

int a, f, l, w;

inline bool good(pair<int, int> u, pair<int, int> v){
    int dx = u.first - v.first, dy = u.second - v.second;
    return dx * dx + dy * dy <= a * a;
}

char g[1003][1003];
vector<pair<int, int>> safe;
pair<int, int> src, dst;
int disa[1003][1003];
queue<pair<int, int>> bfsa;
int disf[1003][1003];
queue<pair<int, int>> bfsf;

int main(){
    cin >> a >> f >> l >> w;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < w; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S')
                g[i][j] = 'W', src = {i, j};
            if(g[i][j] == 'G')
                g[i][j] = 'W', dst = {i, j};
            if(g[i][j] == 'W')
                safe.push_back({i, j});
            disa[i][j] = inf;
            disf[i][j] = inf;
        }
    disa[src.first][src.second] = 0;
    bfsa.push(src);
    while(!bfsa.empty()){
        pair<int, int> u = bfsa.front();
        bfsa.pop();
        for(pair<int, int> v : safe)
            if(disa[v.first][v.second] == inf && good(u, v))
                disa[v.first][v.second] = disa[u.first][u.second] + 1, bfsa.push(v);
    }
    disf[src.first][src.second] = 0;
    bfsf.push(src);
    while(!bfsf.empty()){
        pair<int, int> u = bfsf.front();
        bfsf.pop();
        for(int k = 0; k < 4; k++)
            for(int v = 1; v <= f; v++){
                int x = u.first + v * adjR[k], y = u.second + v * adjC[k];
                if(x >= 0 && x < l && y >= 0 && y < w && g[x][y] == 'W' && disf[x][y] == inf)
                    disf[x][y] = disf[u.first][u.second] + 1, bfsf.push({x, y});
            }
    }
    int ansa = disa[dst.first][dst.second], ansf = disf[dst.first][dst.second];
    if(ansa == inf && ansf == inf)
        cout << "NO WAY" << endl;
    else if(ansa == ansf)
        cout << "SUCCESS" << endl;
    else if(ansa < ansf)
        cout << "GO FOR IT" << endl;
    else
        cout << "NO CHANCE" << endl;
}
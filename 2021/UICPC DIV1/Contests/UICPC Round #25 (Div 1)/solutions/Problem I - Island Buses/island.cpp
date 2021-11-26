#include <bits/stdc++.h>
using namespace std;

// Island Buses

vector<string> lines;

int n, m;
char grid[83][83];
bool vis[83][83];

int adjR[4]{1, -1, 0, 0};
int adjC[4]{0, 0, -1, 1};

void islands(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && (grid[x][y] == '#' || grid[x][y] == 'X') && !vis[x][y])
            islands(x, y);
    }
}

map<pair<int, int>, vector<pair<int, int>>> adjX;
int bridges;

void construct_bridge(int i, int j, int k){
    bool success = false;
    int itx = i + adjR[k], ity = j + adjC[k];
    while(itx >= 0 && itx < n && ity >= 0 && ity < m){
        if(grid[itx][ity] == 'X'){
            success = true;
            break;
        }
        if(grid[itx][ity] != 'B')
            break;
        itx = itx + adjR[k], ity = ity + adjC[k];
    }
    if(success){
        adjX[{i, j}].push_back({itx, ity});
        bridges++;
    }
}

void buses(int i, int j){
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '.' && grid[x][y] != 'B' && !vis[x][y])
            buses(x, y);
    }
    if(grid[i][j] == 'X')
        for(pair<int, int> adj : adjX[{i, j}])
            if(!vis[adj.first][adj.second])
                buses(adj.first, adj.second);
}

int test = 1;
void solve(){
    if(test != 1)
        cout << endl;
    cout << "Map " << test++ << endl;
    n = lines.size(), m = lines[0].size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            grid[i][j] = lines[i][j], vis[i][j] = false;
    int cc = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((grid[i][j] == '#' || grid[i][j] == 'X') && !vis[i][j])
                cc++, islands(i, j);
    cout << "islands: " << cc << endl;
    adjX.clear();
    bridges = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == 'X')
                for(int k = 0; k < 4; k++){
                    int x = i + adjR[k], y = j + adjC[k];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'B')
                        construct_bridge(i, j, k);
                }
    cout << "bridges: " << bridges / 2 << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            vis[i][j] = false;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if((grid[i][j] == '#' || grid[i][j] == 'X') && !vis[i][j])
                ans++, buses(i, j);
    cout << "buses needed: " << ans << endl;
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str.size() == 0){
            solve();
            lines.clear();
        }
        else lines.push_back(str);
    }
    if(!lines.empty())
        solve();
}
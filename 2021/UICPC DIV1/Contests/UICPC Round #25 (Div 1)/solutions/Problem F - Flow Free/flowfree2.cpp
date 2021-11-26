#include <bits/stdc++.h>
using namespace std;

// Flow Free

char g[4 + 3][4 + 3];
map<char, vector<pair<int, int>>> colors_coordinates;
set<char> colors;
vector<pair<int, int>> whites;
bool vis[4 + 3][4 + 3];
int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};
map<char, int> cnt;
bool solvable;

inline int encode(pair<int, int> p){
    return p.first * 4 + p.second;
}

inline pair<int, int> decode(int x){
    return {x / 4, x % 4};
}

vector<pair<int, int>> masks;

void dfs(int i, int j, char c, int mask, int d, int x){
    if(x == d)
        masks.push_back({encode({i, j}), mask});
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int ni = i + adjR[k], nj = j + adjC[k];
        if(ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && !vis[ni][nj] && g[ni][nj] == c && x < d)
            dfs(ni, nj, c, mask | (1 << encode({ni, nj})), d, x + 1);
    }
    vis[i][j] = 0;
}

set<int> masks2[16];

void dfs2(int i, int j, char c, int mask, int d, int x){
    if(x == d)
        masks2[encode({i, j})].insert(mask);
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int ni = i + adjR[k], nj = j + adjC[k];
        if(ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && !vis[ni][nj] && g[ni][nj] == c && x < d)
            dfs2(ni, nj, c, mask | (1 << encode({ni, nj})), d, x + 1);
    }
    vis[i][j] = 0;
}

void track(int i){
    if(i == whites.size()){
        bool ok = 1;
        for(char c : colors){
            masks.clear();
            for(int i = 0; i < 16; i++)
                masks2[i].clear();
            dfs(colors_coordinates[c][0].first, colors_coordinates[c][0].second, c, (1 << encode(colors_coordinates[c][0])), cnt[c] / 2 + (cnt[c] % 2), 1);
            dfs2(colors_coordinates[c][1].first, colors_coordinates[c][1].second, c, (1 << encode(colors_coordinates[c][1])), cnt[c] / 2, 1);
            int total_mask = 0;
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(g[i][j] == c)
                        total_mask += (1 << encode({i, j}));
            bool not_solvable_this_color = 1;
            for(auto m : masks){
                auto endd = decode(m.first);
                for(int k = 0; k < 4; k++){
                    int ni = endd.first + adjR[k], nj = endd.second + adjC[k];
                    if(ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && g[ni][nj] == c && masks2[encode({ni, nj})].find(total_mask - m.second) != masks2[encode({ni, nj})].end()){
                        not_solvable_this_color = 0; 
                        break;
                    }
                }
                if(!not_solvable_this_color)
                    break;
            }
            if(not_solvable_this_color){
                ok = 0;
                break;
            }
        }
        if(ok)
            solvable = 1;
    }
    else for(char c : colors){
        g[whites[i].first][whites[i].second] = c;
        cnt[c]++;
        track(i + 1);
        cnt[c]--;
    }
}

int main(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            cin >> g[i][j];
            if(g[i][j] != 'W')
                colors.insert(g[i][j]), colors_coordinates[g[i][j]].push_back({i, j});
            else
                whites.push_back({i, j});
        }
    for(char c : colors)
        cnt[c] = 2;
    track(0);
    if(solvable)
        cout << "solvable" << endl;
    else
        cout << "not solvable" << endl;
}
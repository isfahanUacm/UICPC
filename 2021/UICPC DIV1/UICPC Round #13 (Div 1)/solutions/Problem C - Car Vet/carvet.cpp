#include <bits/stdc++.h>
using namespace std;

int m, n, srcr, srcc, dstr, dstc;
int g[253][253];
bool vis[253][253];
int adjR[4]{-1, 1, 0, 0};
int adjC[4]{0, 0, -1, 1};
int adjR2[4]{-2, 2, 0, 0};
int adjC2[4]{0, 0, -2, 2};
pair<int, int> p[253][253];

void dfs(int i, int j){
    vis[i][j] = 1;
    vector<pair<int, pair<int, int>>> adjs;
    for(int k = 0; k < 4; k++){
        int ni = i + adjR[k], ni2 = i + adjR2[k], nj = j + adjC[k], nj2 = j + adjC2[k];
        if(ni >= 0 && ni < m && ni2 >= 0 && ni2 < m && nj >= 0 && nj < n && nj2 >= 0 && nj2 < n)
            if(g[ni][nj] == g[ni2][nj2] && g[ni][nj] != -2 && g[ni2][nj2] != -2)
                adjs.push_back({g[ni2][nj2], {ni2, nj2}});
    }
    sort(adjs.begin(), adjs.end());
    for(auto x : adjs)
        if(!vis[x.second.first][x.second.second]){
            p[x.second.first][x.second.second] = {i, j};
            dfs(x.second.first, x.second.second);
        }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            p[i][j] = {-1, -1};
            if(g[i][j] == -1)
                srcr = i, srcc = j;
        }
    cin >> dstr >> dstc;
    dstr--, dstc--;
    dfs(srcr, srcc);
    if(p[dstr][dstc].first == -1){
        cout << "impossible" << endl;
        return 0;
    }
    vector<int> path;
    int i = dstr, j = dstc;
    while(i != srcr || j != srcc){
        path.push_back(g[i][j]);
        int tmp = i;
        i = p[tmp][j].first, j = p[tmp][j].second;
    }
    reverse(path.begin(), path.end());
    for(int x : path)
        cout << x << " ";
    cout << endl;
}
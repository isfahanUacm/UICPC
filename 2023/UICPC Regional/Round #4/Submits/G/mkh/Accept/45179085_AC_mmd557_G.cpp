#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef pair<int,int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<pair<int, int>> vii;

typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;

void dfs(vs grnd, int& res, pii s, vvb& vis) {
    vis [s.first][s.second] = true;

    pii u ={s.first-1, s.second}, d ={s.first+1, s.second};
    pii l ={s.first, s.second-1},r={s.first, s.second+1};
    vii list= {l,u,r,d};
    for(auto c : list) {
        if (c.first < 0 || c.first >= grnd.size()
            || c.second < 0 || c.second >= grnd[0].size() )
            continue;
        if (grnd[c.first][c.second] == 'T')
            return;
    }
    for(auto c : list) {
        if (c.first < 0 || c.first >= grnd.size()
        || c.second < 0 || c.second >= grnd[0].size() )
            continue;
        if (vis[c.first][c.second] || grnd[c.first][c.second] == '#')
            continue;
        if (grnd[c.first][c.second] == 'G')
            res++;
        dfs(grnd, res, c, vis);
    }
}

int main() {
    int a, b;
    cin >>b>>a;
    vs grnd(a);
    pii s;
    for (int i = 0; i < a; ++i) {
        cin >>grnd[i];
        for (int j = 0; j < b; ++j) {
            if(grnd[i][j] == 'P') {
                s = {i, j};
                break;
            }
        }

    }
    vvb vis(a, vb(b, false));
    int res=0;
    dfs(grnd,res, s,vis);
    cout <<res;
    return 0;
}
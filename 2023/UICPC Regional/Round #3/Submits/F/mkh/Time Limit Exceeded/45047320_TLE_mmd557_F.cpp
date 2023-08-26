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

void man_bfs(vvc& map, vvi &res, vii& fire_list) {
    queue<piii> q;
    for(auto fire : fire_list) {
        q.emplace(fire, 0);
    }

    while (!q.empty()) {
        auto fire = q.front();
        q.pop();

        auto s = fire.first;
        res[s.first][s.second] = fire.second;
        pii u = {s.first-1, s.second}, d{s.first+1, s.second};
        pii l = {s.first, s.second-1}, r{s.first, s.second+1};
        vii list = {r, d, l, u};

        for (auto n: list) {
            if (n.first >= map.size() || n.first < 0 || n.second >= map[0].size() || n.second < 0) {
                continue;
            }
            if (res[n.first][n.second] >= 0)
                continue;

            if (map[n.first][n.second] == '.') {
                q.emplace(n, fire.second+1);
            }
        }
    }
}

void fire_bfs(vvc& map, vvi &res, vii& fire_list) {
    queue<piii> q;
    for(auto fire : fire_list) {
        q.emplace(fire, 0);
    }

    while (!q.empty()) {
        auto fire = q.front();
        q.pop();

        auto s = fire.first;
        res[s.first][s.second] = fire.second;
        pii u = {s.first-1, s.second}, d{s.first+1, s.second};
        pii l = {s.first, s.second-1}, r{s.first, s.second+1};
        vii list = {r, d, l, u};

        for (auto n: list) {
            if (n.first >= map.size() || n.first < 0 || n.second >= map[0].size() || n.second < 0) {
                continue;
            }
            if (res[n.first][n.second] >= 0)
                continue;

            if (map[n.first][n.second] != '#') {
                q.emplace(n, fire.second+1);
            }
        }
    }
}
int main() {
    int rep;
    cin >>rep;
    for (int i = 0; i < rep; ++i) {
        int a,b;
        cin >>b>>a;
        vvc v(a, vector<char>(b));
        vii man;
        vii fire_list;
        for (int j = 0; j < a; ++j) {
            for (int k = 0; k < b; ++k) {
                cin>>v[j][k];
                if (v[j][k] == '*') {
                    fire_list.emplace_back(j, k);
                } else if (v[j][k] == '@') {
                    man.emplace_back(j, k);
                }
            }
        }
        vvi man_res(a, vi(b, -1));
        man_bfs(v, man_res, man);

        vvi fire_res(a, vi(b, -1));
        fire_bfs(v, fire_res, fire_list);

        int res = INFINITY;
        bool p = false;
        for (int m = 0; m < a; ++m) {
            for (int n = 0; n < b; ++n) {
                if (m == 0 || m == a - 1 || n == 0 || n == b - 1) {
                    if (man_res[m][n] < 0) {
                        continue;
                    }
                    if (man_res[m][n] <= fire_res[m][n]) {
                        if (man_res[m][n] < res){
                            res = man_res[m][n];
                            p = true;
                        }
                    }
                }
            }
        }
        if(p) {
            cout << res+1 <<endl;
        } else {
            cout << "IMPOSSIBLE" <<endl;
        }

    }
    return 0;
}
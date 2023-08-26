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

int bfs(vvc& map, pii start) {
    queue<piii> q;
    q.emplace(start, 0);
    int fire_dis = -1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (fire_dis != -1 && fire_dis < cur.second)
            return -1;

        auto s = cur.first;
        pii u = {s.first-1, s.second}, d{s.first+1, s.second};
        pii l = {s.first, s.second-1}, r{s.first, s.second+1};
        vii list = {r, d, l, u};

        for (auto n: list) {
            if (n.first >= map.size() || n.first < 0 || n.second >= map[0].size() || n.second < 0) {
                continue;
            }

            if (map[n.first][n.second] == '@') {
                return cur.second+1;
            } else if (map[n.first][n.second] == '*') {
                fire_dis = cur.second;
            }else if (map[n.first][n.second] == '.') {
                q.emplace(n, cur.second + 1);
            }
        }
    }
    return -1;
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
            }
        }

        int res = INFINITY;
        bool p = false;
        for (int m = 0; m < a; ++m) {
            for (int n = 0; n < b; ++n) {
                if (m == 0 || m == a - 1 || n == 0 || n == b - 1) {
                    if (v[m][n] == '#')
                        continue;
                    int tmp =bfs(v, {m, n});
                    if (tmp == -1)
                        continue;
                    if (tmp < res) {
                        res = tmp;
                        p = true;
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
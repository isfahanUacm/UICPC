#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;

bool ir(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

pair<int, int> mv[] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
};
char mp[1001][1001];
int tt[1001][1001];
int bfst[1001][1001];

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> m >> n;
        memset(tt, -1, sizeof(tt));
        memset(bfst, -1, sizeof(bfst));
        int sx , sy;
        queue<pair<int, int>> fire;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mp[i][j];
                if (mp[i][j] == '@') {
                    sx = i; sy = j;
                }
                if (mp[i][j] == '*') {
                    fire.emplace(i, j);
                    tt[i][j] = 0;
                }
            }
        }

        while (!fire.empty()) {
            pair<int, int> x = fire.front();
            fire.pop();

            for (auto t: mv) {
                int nx = x.first + t.first;
                int ny = x.second + t.second;
                int ti = tt[x.first][x.second] + 1;
                if (!ir(nx,ny)) {
                    continue;
                }

                if (mp[nx][ny] != '#') {
                    if (tt[nx][ny] == -1 || tt[nx][ny] > ti) {
                        tt[nx][ny] = ti;
                        fire.emplace(nx, ny);
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        bfst[sx][sy] = 0;
        q.emplace(sx, sy);
        int ans = -1;
        while (!q.empty()) {
            auto x = q.front();
            int nxt = bfst[x.first][x.second] + 1;
            q.pop();

            if (x.first == 0 || x.first == n - 1 || x.second == 0 || x.second == m - 1) {
                ans = nxt;
                break;
            }

            for (auto t: mv) {
                int nx = x.first + t.first;
                int ny = x.second + t.second;

                if (ir(nx, ny)) {
                    if (mp[nx][ny] != '#' && tt[nx][ny] > nxt && bfst[nx][ny] == -1) {
                        bfst[nx][ny] = nxt;
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        if (ans == -1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}

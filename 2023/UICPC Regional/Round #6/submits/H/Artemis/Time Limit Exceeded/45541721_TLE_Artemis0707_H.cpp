#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[142][122];
int n, m;
int a, b;

vector<float> ans;
int visited[142][122];
int color = 0;

void solve(int sx, int sy, int xh, int yh, int sum) {
    if (visited[xh][yh] == color)
        return;
    visited[xh][yh] = color;
    int area = (xh - sx + 1) * (yh - sy + 1);
    if (area > b)
        return;

    if (area >= a && area <= b) {
        ans.push_back((float)sum / area);
    }

    if (xh < n - 1) {
        int sum1 = sum;
        for (int i = sy; i <= yh; ++i) {
            sum1 += mp[xh + 1][i];
        }
        solve(sx, sy, xh + 1, yh, sum1);
    }
    if (yh < m - 1) {
        int sum2 = sum;
        for (int i = sx; i <= xh; ++i) {
            sum2 += mp[i][yh+1];
        }
        solve(sx, sy, xh, yh + 1, sum2);
    }
}

int main() {
    cin >> n >> m;
    cin >> a >> b;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            solve(i, j, i, j, mp[i][j]);
            color++;
        }
    }

    sort(ans.begin(), ans.end());
    if (ans.size() % 2 == 0) {
        printf("%.5f\n", (ans[ans.size()/2 - 1] + ans[ans.size()/2]) / 2);
    }
    else {
        printf("%.5f\n", ans[ans.size() / 2]);
    }
}


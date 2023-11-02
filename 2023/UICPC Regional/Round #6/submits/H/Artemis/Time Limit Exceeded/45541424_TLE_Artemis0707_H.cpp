#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mp[142][122];
ll n, m;
ll a, b;

vector<double> ans;
int visited[142][122];
int color = 0;

void solve(ll sx, ll sy, ll xh, ll yh, ll sum) {
    if (visited[xh][yh] == color)
        return;
    visited[xh][yh] = color;
    ll area = (xh - sx + 1) * (yh - sy + 1);
    if (area > b)
        return;

    if (area >= a && area <= b) {
        ans.push_back((double)sum / area);
    }

    if (xh < n - 1) {
        ll sum1 = sum;
        for (ll i = sy; i <= yh; ++i) {
            sum1 += mp[xh + 1][i];
        }
        solve(sx, sy, xh + 1, yh, sum1);
    }
    if (yh < m - 1) {
        ll sum2 = sum;
        for (ll i = sx; i <= xh; ++i) {
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
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
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

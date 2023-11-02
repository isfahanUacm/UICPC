#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 150;
ll mp[mx][mx];
ll n, m;
ll a, b;

vector<double> ans;
bool visited[mx][mx];

void solve(ll sx, ll sy, ll xh, ll yh, ll sum) {
    if (visited[xh][yh])
        return;
    visited[xh][yh] = true;
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

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            memset(visited, false, sizeof(visited));
            solve(i, j, i, j, mp[i][j]);
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

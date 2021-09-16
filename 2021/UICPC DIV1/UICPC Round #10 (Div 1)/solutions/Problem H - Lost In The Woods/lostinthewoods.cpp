#include <bits/stdc++.h>
using namespace std;

vector<int> adj[23];
double dp[23][10003];
int n, m, a, b;

double cdp(int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == n-1){
        return j;
    }
    if(j == 10000){
        return 0;
    }
    int s = adj[i].size();
    double ans = 0;
    for (auto v : adj[i]) {
        ans += 1.0 * cdp(v, j+1) / s;
    }
    return dp[i][j] = ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < 10001; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << fixed << setprecision(7) << cdp(0, 0) << endl;
    return 0;
}


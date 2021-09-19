#include <bits/stdc++.h>
using namespace std;

// Eating Everything Efficiently

int n, m;
vector<int> adj[500003];
double f2[63], c[500003], dp[500003][63];

double cdp(int u, int k){
    if(dp[u][k] != -1)
        return dp[u][k];
    if(k == 61)
        return dp[u][k] = 0;
    double ans = c[u] * f2[k];
    for(int v : adj[u])
        ans = max(ans, max(cdp(v, k), c[u] * f2[k] + cdp(v, k + 1)));
    return dp[u][k] = ans;
}

int main(){
    f2[0] = 1;
    for(int i = 1; i < 63; i++)
        f2[i] = f2[i-1] / 2;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    int x, y;
    while(m--)
        cin >> x >> y, adj[x].push_back(y);
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= 61; j++)
            dp[i][j] = -1;
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, cdp(i, 0));
    cout << fixed << setprecision(10) << ans << endl;
}
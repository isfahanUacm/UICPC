#include <bits/stdc++.h>
using namespace std;

// Great GDP

const int maxn = 1e5 + 3;

#define EPS 1e-9

int n, preorder[maxn], nexty[maxn], cnt = 0;
vector<int> adj[maxn];
double c[maxn], k[maxn], dp[maxn];

void dfs(int u, int p){
    int save = cnt;
    preorder[cnt++] = u;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u);
    nexty[save] = cnt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        cin >> k[i];
    int x, y;
    for(int i = 0; i < n-1; i++)
        cin >> x >> y, adj[x-1].push_back(y-1), adj[y-1].push_back(x-1);
    dfs(0, -1);
    double lo = 0, hi = INT_MAX;
    while(fabs(hi - lo) > EPS){
        double mid = (lo + hi) / 2;
        dp[n] = 0;
        for(int i = n-1; i > 0; i--)
            dp[i] = max(dp[nexty[i]], c[preorder[i]] - mid * k[preorder[i]] + dp[i+1]);
        dp[0] = c[preorder[0]] - mid * k[preorder[0]] + dp[1];
        if(dp[0] > 0)
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed << setprecision(7) << lo << endl;
}
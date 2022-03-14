#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
double dp[100003], r;
int c[100003], k[100003];
int n, uu, vv;
vector<int> adj[100003];
int parent[100003];
int cnt = 0;
int order[100003];
int nexty[100003];

void dfs(int u){
    int nobat = cnt;
    order[cnt++] = u;
    for (auto v: adj[u]) {
        if(parent[u] != v){
            parent[v] = u;
            dfs(v);
        }
    }
    nexty[nobat] = cnt;
}

double cdp(int i){
    if(dp[i] != -1){
        return dp[i];
    }
    if(i == n){
        return 0;
    }
    double res = INT_MIN;
    if(parent[order[i]] != -1){
        res = cdp(nexty[i]);
    }
    res = max(res, cdp(i+1) + (1.0*c[order[i]] - r * k[order[i]]));
    return dp[i] = res;
}

int main()
{
    cin >> n;
    fill_n(parent, n+1, -1);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> k[i];
    for (int i = 0; i < n-1; ++i) {
        cin >> uu >> vv; uu--; vv--;
        adj[uu].push_back(vv);
        adj[vv].push_back(uu);
    }
    dfs(0);
    double lo = 0, hi = INT_MAX;
    while(fabs(lo - hi) > EPS){
        fill_n(dp, n+1, -1);
        r = (lo + hi) / 2;
        if(cdp(0) < 0){
            hi = r;
        }
        else{
            lo = r;
        }
    }
    cout << fixed << setprecision(7) << lo << endl;
    return 0;
}


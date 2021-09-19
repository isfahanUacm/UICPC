#include <bits/stdc++.h>
using namespace std;

const int maxn = 253;
int n, m;
long long int dp[maxn][maxn], st[maxn], k, r;
pair<long long int, long long int> curv[maxn];

long long int cdp(int i, int lane){
    if(dp[i][lane] != -1){
        return dp[i][lane];
    }
    int diff = st[i]/k;
    if(i == n-1){
        return dp[i][lane] = ((lane <= diff)?st[i] + lane * r:LLONG_MAX);
    }
    long long int ans = LLONG_MAX;
    long long int nxtans;
    for (int j = max(0, lane-diff); j <= min(m-1, lane+diff); ++j) {
        nxtans = cdp(i+1, j);
        ans = min(ans, (nxtans == LLONG_MAX)?LLONG_MAX:(st[i] + abs(j-lane) * r + curv[i].first + curv[i].second * (j+1) + nxtans));
    }
    return dp[i][lane] = ans;
}


int main()
{
    cin >> n >> m;
    cin >> k >> r;
    for (int i = 0; i < n; ++i) {
        cin >> st[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin >> curv[i].first >> curv[i].second;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << cdp(0, 0) << endl;
    
    return 0;
}


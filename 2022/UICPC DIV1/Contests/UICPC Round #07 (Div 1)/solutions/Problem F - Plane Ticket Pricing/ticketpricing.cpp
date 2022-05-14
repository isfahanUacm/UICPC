#include <bits/stdc++.h>
using namespace std;

// Plane Ticket Pricing

int n, W;
int wsi[55];
int p[55][103];
int s[55][103];

int dp[303][55];
int ans = INT_MAX;

int cdp(int n, int w){
    if(dp[n][w] != -1)
        return dp[n][w];
    if(n == 0 || w == W)
        return dp[n][w] = 0;
    int best = INT_MIN;
    for(int i = 0; i < wsi[w]; i++){
        int curr = cdp(max(n-s[w][i], 0), w+1) + min(n, s[w][i]) * p[w][i];
        if(w == 0){
            if(curr > best)
                ans = p[w][i];
            else if(curr == best && p[w][i] < ans)
                ans = p[w][i];
        }
        best = max(best, curr);
    }
    return dp[n][w] = best;
}

int main(){
    cin >> n >> W, W++;
    for(int i = 0; i < W; i++){
        cin >> wsi[i];
        for(int j = 0; j < wsi[i]; j++)
            cin >> p[i][j];
        for(int j = 0; j < wsi[i]; j++)
            cin >> s[i][j];
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= W; j++)
            dp[i][j] = -1;
    cout << cdp(n, 0) << endl;
    cout << ans << endl;
}
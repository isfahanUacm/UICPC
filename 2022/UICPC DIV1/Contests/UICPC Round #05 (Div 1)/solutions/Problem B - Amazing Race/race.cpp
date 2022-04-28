#include <bits/stdc++.h>
using namespace std;

// Amazing Race

#define inf INT_MAX

int n, T, p[23], t[23], d[23], g[23][23], dp[(1<<20)+3][23];

int main(){
    cin >> n >> T;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> t[i] >> d[i];
    for(int i = 0; i < n + 2; i++)
        for(int j = 0; j < n + 2; j++)
            cin >> g[i][j];
    int ans = 0, cand;
    for(int mask = 1; mask < (1 << n); mask++)
        for(int i = 0; i < n; i++){
            dp[mask][i] = inf;
            if(mask == (1 << i)){
                if(d[i] == -1 || g[n][i] + t[i] <= d[i])
                    dp[mask][i] = g[n][i] + t[i];
            }
            else if(mask & (1 << i))
                for(int j = 0; j < n; j++)
                    if(j != i && (mask & (1 << j))){
                        int prev = mask - (1 << i);
                        if(dp[prev][j] != inf && (d[i] == -1 || dp[prev][j] + g[j][i] + t[i] <= d[i]))
                            dp[mask][i] = min(dp[mask][i], dp[prev][j] + g[j][i] + t[i]);
                    }
            if(dp[mask][i] != inf && dp[mask][i] + g[i][n+1] <= T){
                int profit = 0;
                for(int i = 0; i < n; i++)
                    if(mask & (1<<i))
                        profit += p[i];
                if(profit > ans)
                    ans = profit, cand = mask;
                else if(profit == ans)
                    cand = min(cand, mask);
            }
        }
    cout << ans << endl;
    if(ans)
        for(int i = 0; i < n; i++)
            if(cand&(1 << i))
                cout << i + 1 << " ";
    cout << endl;
}
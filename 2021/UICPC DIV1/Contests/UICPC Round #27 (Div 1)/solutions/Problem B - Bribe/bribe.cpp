#include <bits/stdc++.h>
using namespace std;

// Bribe

int n, c, m;
pair<int, double> henchmen[20];

double dp[65540][20];

double cdp(int mask, int c){
    if(dp[mask][c] != -1)
        return dp[mask][c];
    if(c == 0)
        return dp[mask][c] = 1;
    if(mask == 0)
        return dp[mask][c] = 0;
    int money = m; // recover it due to mask
    for(int i = 0; i < n; i++)
        if(!(mask & (1<<i)))
            money -= henchmen[i].first;
    double ans = 0;
    for(int i = 0; i < n; i++)
        if((mask & (1<<i)) && (money >= henchmen[i].first))
            ans = max(ans, henchmen[i].second * cdp(mask - (1<<i), c-1) + (1 - henchmen[i].second) * cdp(mask - (1<<i), c));
    return dp[mask][c] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << fixed << setprecision(6);
        cin >> n >> c >> m;
        for(int i = 0; i < n; i++)
            cin >> henchmen[i].first >> henchmen[i].second, henchmen[i].second /= 100.0;
        for(int i = 0; i < (1<<n); i++)
            for(int j = 0; j <= c; j++)
                dp[i][j] = -1;
        cout << cdp((1<<n)-1, c) << endl;
    }
}
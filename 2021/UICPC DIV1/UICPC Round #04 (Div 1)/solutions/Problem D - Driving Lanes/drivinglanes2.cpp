#include <bits/stdc++.h>
using namespace std;

// Driving Lanes

#define num long long int
const num inf = LLONG_MAX;

int n, m;
num k, r, l[253], s[253], c[253], dp[253][253];

int main(){
    cin >> n >> m >> k >> r;
    for(int i = 0; i < n; i++)
        cin >> l[i];
    for(int i = 0; i < n-1; i++)
        cin >> s[i] >> c[i];
    dp[n][0] = 0;
    for(int x = 1; x < m; x++)
        dp[n][x] = inf;
    for(int i = n-1; i >= 0; i--)
        for(int x1 = 0; x1 < m; x1++){
            dp[i][x1] = inf;
            for(int x2 = 0; x2 < m; x2++){
                num f = abs(x1 - x2);
                if(f * k <= l[i] && dp[i+1][x2] != inf)
                    dp[i][x1] = min(dp[i][x1], f * r + l[i] + s[i] + c[i] * (x2 + 1) + dp[i+1][x2]);
            }
        }
    cout << dp[0][0] << endl;
} 
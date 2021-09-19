#include <bits/stdc++.h>
using namespace std;

// Polly Gone

int n, P, e[1003], p[1003]; 
int dp[10003];

int main(){
    double tmp;
    cin >> n >> tmp;
    P = tmp * 10000 + 1e-9;
    for(int i = 0; i < n; i++)
        cin >> e[i] >> tmp, p[i] = tmp * 10000 + 1e-9;
    fill_n(dp, 10001, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 10000; j >= 0; j--)
            if(dp[j] != INT_MAX && j + p[i] <= 10000)
                dp[j + p[i]] = min(dp[j + p[i]], dp[j] + e[i]);
    int ans = INT_MAX;
    for(int i = P; i <= 10000; i++)
        ans = min(ans, dp[i]);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

double dp[10003][503];
int n, K, s;

double cdp(int i, int k){
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    if(i == n && k == 0){
        return 1;
    }
//    cerr << i << " " << k << endl;
    if(i == 0){
        return dp[i][k] = cdp(i+1, k-1);
    }
    if(n-i == k){
        return dp[i][k] = 1.0 * (s-K+k) * cdp(i+1, k-1) / s;
    }
    double ans = 0;
    if(k > 0){
        ans += 1.0 * (s-K+k) * cdp(i+1, k-1) / s;
    }
    else{
        ans += 1.0 * (s-K+k) * cdp(i+1, k) / s;
    }
    if(n-i > k){
        ans += 1.0 * (K-k) * cdp(i+1, k) / s;
    }
//    cerr << i << " " << k << " " << K << " " << ans << " " << K-k << " " << s-K+k << endl;
    return dp[i][k] = ans;
}

int main()
{
    cin >> n >> s >> K;
    if(n < K){
        cout << fixed << setprecision(8) << 0.0 << endl;
        return 0;
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= K; ++j)
            dp[i][j] = -1;
    cout << fixed << setprecision(8) << cdp(0, K) << endl;
    return 0;
}


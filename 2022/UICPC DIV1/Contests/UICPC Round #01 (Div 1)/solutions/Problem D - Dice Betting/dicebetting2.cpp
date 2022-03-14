#include <bits/stdc++.h>
using namespace std;

// Dice Betting

int n, k, s;
double dp[10003][503];

int main(){
    cin >> n >> s >> k;
    for(int i = n; i >= 0; i--)
        for(int t = 0; t <= s; t++){
            if(i == n)
                dp[i][t] = t >= k;
            else
                dp[i][t] = double(s-t)/s * dp[i+1][t+1] + double(t)/s * dp[i+1][t];
        }
    cout << fixed << setprecision(8) << dp[0][0] << endl;
}
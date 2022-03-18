#include <bits/stdc++.h>
using namespace std;

// Bridge Automation

int n;
int t[4003];
int dp[4003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        dp[i] = 140 + dp[i+1];
        for(int j = i+1; j < n; j++){
            int d = t[j] - (j - i) * 20 - 60;
            dp[i] = min(dp[i], t[j] - min(t[i]+1740, d) + 80 + dp[j+1]);
        }
    }
    cout << dp[0] << endl;
}
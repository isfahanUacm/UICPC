#include <bits/stdc++.h>
using namespace std;

int dp[4003];
int arr[4003];

int main()
{
    int n, d;
    cin>>n;
    dp[n] = 0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = n-1; i >= 0 ; i--) {
        dp[i] = 140 + dp[i+1];
        for (int j = i+1; j < n; ++j) {
            d = arr[j] - (j-i)*20 -60;
            dp[i] = min(dp[i], arr[j] - min(arr[i]+1740, d)+80+dp[j+1]);
        }
    }
    cout<<dp[0]<<endl;
    
    return 0;
}


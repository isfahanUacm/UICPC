#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long int dp[303][303];

int main()
{
    int h, w;
    cin>>h>>w;
    if(h==1 && w==1){
        cout<<1<<endl;
        return 0;
    }
    else if (h==1){
        cout<<0<<endl;
        return 0;
    }
        
    for (int i = 0; i < h; ++i) {
        dp[0][i]=1;
    }
    for (int i = 1; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int n = 1; n < w; ++n) {
        for (int k = 1; k < h; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[n][k] = (dp[n][k] + (dp[i][k-1] * dp[n-i-1][k]))%mod;
            }
        }
    }
    cout<< (dp[w-1][h-1] - dp[w-1][h-2]+mod)%mod<<endl;
    return 0;
}

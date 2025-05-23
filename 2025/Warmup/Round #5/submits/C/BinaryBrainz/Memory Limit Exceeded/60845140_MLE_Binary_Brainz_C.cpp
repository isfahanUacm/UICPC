#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  endl '\n'
void solve() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    vector<vector<ll>>dp(n,vector<ll>(n));
    for(int i =0 ; i < n;i++){
        dp[i][i] = arr[i];
    }
    for(int k =1 ;k< n - 1;k++){
        for(int i =0 ; i+k<n;i++){
            int j = i + k;

            dp[i][j] = dp[i][j-1] + arr[j];
        }
    }
    ll best  = 0;

    for(int k =0;k <= n/2;k++){
        if(n % (k+1)) continue;

        ll min = LLONG_MAX;
        ll max = -1;
        for(int i =0 ; i+k < n ; i+= k+1){
            int j = i + k;

            if(dp[i][j] < min)
                min = dp[i][j];
            if (dp[i][j] > max)
                max = dp[i][j];
        }

        if((max - min) >  best )
            best = max - min;
    }

    cout << best;

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << '\n';
    }
}

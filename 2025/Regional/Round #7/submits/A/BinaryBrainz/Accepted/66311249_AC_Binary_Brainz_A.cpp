#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ll n , k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vll dp(n);
    for (int i = 0; i < n; ++i) {
        if(i < k){
            if(i == 0){
                if(a[i] < 0){
                    dp[i] = 0;
                }
                else{
                    dp[i] = a[i];
                }
            }
            else{
                dp[i] = max(a[i] , dp[i - 1]);
            }
        }
        else{
            dp[i] = max(dp[i - 1] , (ll)(a[i] + dp[i - k]));
        }
    }
    if(dp[n - 1] < 0){
        cout << 0;
    }
    else{
        cout << dp[n - 1];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}
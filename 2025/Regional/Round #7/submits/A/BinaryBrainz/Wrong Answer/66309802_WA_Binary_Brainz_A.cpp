#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n , k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vll dp(n , 0);
    ll max1 = -1;
    multiset<ll , greater<>> temp;
    for (int i = 0; i < n; ++i) {
        if(i < k){
            dp[i] = a[i];
        }
        else{
            max1 = max(max1 , dp[i - k]);
            dp[i] = max(* temp.begin() , a[i] + max1);
        }
        temp.insert(dp[i]);
        if(i >= k - 1){
            temp.erase(dp[i - k + 1]);
        }

    }
    if(k == n){
        int ans = * temp.begin();
        if(ans < 0){
            cout << 0;
        }
        else{
            cout << ans;
        }
        return;
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
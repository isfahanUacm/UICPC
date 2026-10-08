#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ll n , T;
    cin >> n >> T;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll low = 1;
    ll high = T;
    ll mid;
    ll ans = 1e12;
    while(low <= high){
        mid = (low + high) / 2;
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            s += (a[i] / mid);
            if(a[i] % mid){
                s++;
            }
        }
        if(s > T){
            low = mid + 1;
        }
        else{
            ans = min(ans , mid);
            high = mid - 1;
        }
    }
    cout << ans;
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
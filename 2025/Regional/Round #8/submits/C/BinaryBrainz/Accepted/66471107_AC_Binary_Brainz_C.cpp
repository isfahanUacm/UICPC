#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n;
    cin >> n;
    while(n){
        ll ans = 0;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                ans += (ll) (i * j);
            }
        }
        cout << ans << "\n";
        cin >> n;
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
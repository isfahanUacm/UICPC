#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define ll long long


void solve() {

    ll n , m , k;
    cin >> n >> m >> k;
    if (k <= n) {
        cout << k;
        return;
    }
    if (m % 2 == 0) {
        m--;
    }
    ll ans = n;
    ll x = k / (m);
    ll y = k % (m);
    if (x <= n) {
        if (y == 0) {
            cout << ans;
        }
        else {
            cout << ans - y;
        }
    }
    else {
        ll f = (x - n) * (m);
        f += y;
        cout << ans - f;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
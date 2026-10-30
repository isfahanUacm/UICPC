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
    vll a(n , 1);
    k -= n;
    if (m % 2 == 0) {
        m--;
    }
    for (ll i = 0; i < n; i++) {
        if (m - a[i] <= k) {
            k -= (m - a[i]);
            a[i] = m;
        }
        else {
            a[i] += k;
            k = 0;
        }
    }
    int i = 0;
    while (k != 0) {
        a[i] ++;
        i++;
        k--;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
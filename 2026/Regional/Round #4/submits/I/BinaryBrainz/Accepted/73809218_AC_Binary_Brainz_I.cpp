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
    k -= n;
    if (m % 2 == 0) {
        m--;
    }
    if (m != 1) {
        ll x = k / (m - 1);
        ll y = k % (m - 1);
        if (x < n) {
            if (y == 0) {
                cout << n;
            }
            else {
                if ((y + 1) % 2 == 0) {
                    cout << n - 1;
                }
                else {
                    cout << n;
                }
            }
        }
        else if (x == n) {
            if (y == 0) {
                cout << n;
            }
            else {
                cout << n - y;
            }
        }
        else {
            ll f = (x - n) * (m - 1);
            f += y;
            cout << n - f;
        }
    }
    else {
        cout << n - k;
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

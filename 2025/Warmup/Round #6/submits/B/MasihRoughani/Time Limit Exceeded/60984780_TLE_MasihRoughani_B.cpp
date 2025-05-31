#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a = 1, b = n - 1;
        ll min = lcm(a, b);
        for (ll i = 1; i <= n / 2; i++) {
            ll j = n - i;
            ll lcm1 = lcm(i, j);
            if (lcm1 < min) {
                min = lcm1;
                a = i;
                b = j;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}

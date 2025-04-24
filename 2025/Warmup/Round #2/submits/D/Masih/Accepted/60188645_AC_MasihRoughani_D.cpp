#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll t;
    for (ll j = 0; j < n; j++) {
        cin >> t;
        for (ll i = 1; i <= t; i += 2) {
            cout << i << " ";
        }
        for (ll i = 2; i <= t; i += 2) {
            cout << i << " ";
        }
    }
}
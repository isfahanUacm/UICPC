#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll n, c;
        cin >> n >> c;
        ll temp = c;
        vector<ll> litr(n);
        for (ll j = 0; j < n; j++) {
            cin >> litr[j];
        }
        int counter = 1;
        for (ll j = 0; j < n; j++) {
            if (litr[j] < temp) {
                temp -= litr[j];
            } else {
                counter++;
                temp = c;
            }
        }
        cout << counter << endl;
    }
}
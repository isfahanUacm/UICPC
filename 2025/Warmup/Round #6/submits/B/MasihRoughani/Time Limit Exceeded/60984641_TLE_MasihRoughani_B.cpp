#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, pair<ll, ll>>> lcma;

        for (ll a = 1; a < n; a++) {
            for (ll b = 1; b < n; b++) {
                if (a + b == n) {
                    ll temp = lcm(a, b);
                    lcma.push_back({temp, {a, b}});
                }
            }
        }

        sort(lcma.begin(), lcma.end());

        cout << lcma[0].second.first << " ";
        cout << lcma[0].second.second << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define ll long long

void solve() {

    ll n;
    cin >> n;

    ll u = 0, d = 0, m = 0;
    ll ans = 0;

    ll x,y;
    for (int i =0; i <n;i++) {
        cin >> x >> y;
        if (y > x) {
            u++;
        }
        else if (y < x) {
            d++;
        }
        else if (y == x) {
            m++;
        }
    }



    ans += u * d; // 2
    ans += u * m; // 4
    ans += d * m; // 2
    ans += m * (m - 1) / 2; // 1

    cout << ans;
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
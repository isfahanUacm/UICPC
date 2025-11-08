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
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll x = a[0] / 3;
    ll y = a[1] - (2 * x);
    ll z = a[n - 1] / 3;
    cout << x << " " << y << " " << z;
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
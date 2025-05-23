#include "bits/stdc++.h"
#ifndef LOCAL
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#else
#define fastio
#endif

#define nl '\n'
#define pb push_back
#define arr array
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long; using ld = long double; using str = string;
const int N = 1e6+5;
int n, a[N];
void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    int ans = 0;
    for (int i=1; i<n; i++) {
        if (a[i] <= a[i-1]) {
            ans += a[i-1]+1-a[i];
            a[i] = a[i-1]+1;
        }
    }
    cout << ans << nl;

}

int32_t main() {
    int t=1;
//cin >> t;
    while(t--) {
        solve();
        cerr << "-----------------" << nl;
    }
}

#include<bits/stdc++.h>
#ifndef ONPC
#define LINE
#else
#define LINE cout << "----------" << nl;
#endif
using namespace std;
using ll = long long;
#define nl '\n'
#define arr array
#define pb push_back

const int N =  5e5+5;
string a;
void solve() {
    cin >> a;
    int n = a.size(), c = 0, ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i]=='1') {
            if (c) ans++;
            c = 0;
        } else {
            c++;
        }
    }
    if (c) ans++;
    cout << ans << nl;

}

int32_t main() {
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}
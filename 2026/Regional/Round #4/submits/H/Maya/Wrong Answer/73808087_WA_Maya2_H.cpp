#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int x = 0;
    bool f = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            f = false;
            if (x == -1) {
                x = i;
            }
        }
    }

    int cn = 0;
    for (int i = x; i < n; i++) {
        if (a[i] == a[x]) {
            cn++;
        } else {
            break;
        }
    }

    if (f) {
        cout << 0 << '\n';
    } else if (count(a.begin(), a.end(), a[x]) == cn) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size(), zeros = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zeros++;
        }
        else {
            break;
        }
    }
    cout << n - 1 - (count(s.begin(), s.end(), '0') - zeros) << '\n';
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

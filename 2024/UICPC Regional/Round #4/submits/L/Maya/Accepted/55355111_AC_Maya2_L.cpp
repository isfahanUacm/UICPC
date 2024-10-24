#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size(), num = 0, end = 0, st = -1;
    for (int i = 0; i < n; i++) {
        num += s[i] == '(' ? 1 : -1;
        if (num == 0) {
            end = i;
            break;
        }
    }
    for (int i = end + 1, k = end + 1, j = 0; i < n; i++, j++) {
        if (s[i] != s[j]) {
            st = k;
        }
        if (j == end) {
            k = j + 1;
            j = -1;
        }
    }
    if (st == -1) {
        cout << "no\n";
        return;
    }
    for (int i = st; i < n; i++) {
        cout << s[i];
    }
    for (int i = 0; i < st; i++) {
        cout << s[i];
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

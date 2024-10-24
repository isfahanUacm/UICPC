#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        s[i] -= 'A' - 'a';
    }

    cout << s << '\n';
    if (s.contains("ss")) {
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i] == 's' && s[i + 1] == 's') {
                s[i] = 'A';
                cout << 'B';
                i++;
            }
            else {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    if (s.contains("Ass")) {
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i] == 's' && s[i + 1] == 's') {
                cout << 'B';
                i++;
            }
            else if (s[i] > 'A') {
                cout << s[i];
            }
            else {
                cout << 's';
            }
        }
        cout << '\n';
    }
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

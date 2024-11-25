#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/babilash/blue-folder/cp/cf/debug.h"
#else
#define dbg(...)
#define dbgarr(...)
#endif

void solve() {
    string s;
    cin >> s;

    if (s[1] == '=') {
        if (s[0] == s[2]) {
            cout << s << endl;
        } else if (s[0] < s[2]) {
            cout << s[0] << '<' << s[2] << endl;
        } else {
            cout << s[0] << '>' << s[2] << endl;
        }
    } else if (s[1] == '<') {
        if (s[0] < s[2]) {
            cout << s << endl;
        } else if (s[0] == s[2]) {
            cout << s[0] << '=' << s[2] << endl;
        } else {
            cout << s[0] << '>' << s[2] << endl;
        }
    } else {
        if (s[0] > s[2]) {
            cout << s << endl;
        } else if (s[0] == s[2]) {
            cout << s[0] << '=' << s[2] << endl;
        } else {
            cout << s[0] << '<' << s[2] << endl;
        }
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

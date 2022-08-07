#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll tc;
    cin >> tc;
    string vals[] = {"AA", "BB", "CC", "ABAB", "BCBC"};
    while (tc--) {
        string a, b;
        cin >> a >> b;

        bool possible = true;
        int i = 0, j = 0;

        while (i < a.length() && j < b.length()) {
            bool a_f = false;
            bool b_f = false;
            int ih = i, jh = j;

            for (const auto &x : vals) {
                if (a.substr(i, x.length()) == x) {
                    i += x.length();
                    a_f = true;
                    break;
                }
            }

            for (const auto &x : vals) {
                if (b.substr(j, x.length()) == x) {
                    j += x.length();
                    b_f = true;
                    break;
                }
            }

            if (!a_f || !b_f) {
                possible = false;
            }

            if (!possible) {
                if (a[ih] == b[jh]) {
                    possible = true;
                    i = ih + 1;
                    j = jh + 1;
                } else {
                    break;
                }
            }
        }


        if (i != a.length() || j != b.length()) {
            possible = false;
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}




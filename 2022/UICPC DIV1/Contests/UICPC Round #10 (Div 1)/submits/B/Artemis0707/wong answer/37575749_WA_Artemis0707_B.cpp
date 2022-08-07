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

        while (i != a.length() && j != b.length()) {
            if (a[i] != b[j]) {
                bool a_f = false;
                bool b_f = false;
                int ih = i, jh = j;

                for (const auto &x : vals) {
                    if (a.substr(i, x.length()) == x) {
                        i += x.length();
                        a_f = true;
                    }
                    if (b.substr(j, x.length()) == x) {
                        j += x.length();
                        b_f = true;
                    }
                }

                if (!a_f || !b_f) {
                    if (ih > 0 && jh > 0) {
                        a_f = false;
                        b_f = false;
                        i = ih - 1;
                        j = jh - 1;
                        for (const auto &x : vals) {
                            if (a.substr(i, x.length()) == x) {
                                i += x.length();
                                a_f = true;
                            }
                            if (b.substr(j, x.length()) == x) {
                                j += x.length();
                                b_f = true;
                            }
                        }
                    }

                    if (!a_f || !b_f) {
                        possible = false;
                        break;
                    }
                }
            } else {
                i++;
                j++;
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



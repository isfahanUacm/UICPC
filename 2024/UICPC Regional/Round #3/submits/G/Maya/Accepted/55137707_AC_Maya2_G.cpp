#include <bits/stdc++.h>
using namespace std;

void solve() {
    array<int, 3> s1, e1, s2, e2;    
    cin >> s1[0] >> s1[1] >> s1[2] >> e1[0] >> e1[1] >> e1[2];
    cin >> s2[0] >> s2[1] >> s2[2] >> e2[0] >> e2[1] >> e2[2];

    auto print = [&](array<int, 3> &a, array<int, 3> &b) {
        cout << '(' << a[0] << ' ' << a[1] << ' ' << a[2] << ") ";
        cout << '(' << b[0] << ' ' << b[1] << ' ' << b[2] << ")\n";
    };

    auto f = [&](int i, int j, int k) {
        if (s1[i] == s2[i]) {
            s1[i]++;
            print(s1, s2);
        }
        while ((s1[j] != e1[j] || s1[k] != e1[k]) || (s2[j] != e2[j] || s2[k] != e2[k])) {
            if (s1[j] != e1[j]) {
                s1[j] += s1[j] < e1[j] ? 1 : -1;
            }
            else if (s1[k] != e1[k]) {
                s1[k] += s1[k] < e1[k] ? 1 : -1;
            }

            if (s2[j] != e2[j]) {
                s2[j] += s2[j] < e2[j] ? 1 : -1;
            }
            else if (s2[k] != e2[k]) {
                s2[k] += s2[k] < e2[k] ? 1 : -1;
            }
            print(s1, s2);
        }
        while ((s1[i] != e1[i]) || (s2[i] != e2[i])) {
            if (s1[i] != e1[i]) {
                s1[i] += s1[i] < e1[i] ? 1 : -1;
            }
            if (s2[i] != e2[i]) {
                s2[i] += s2[i] < e2[i] ? 1 : -1;
            }
            print(s1, s2);
        }
    };

    print(s1, s2);
    if (e1[0] == e2[0]) {
        f(0, 1, 2);
    }
    else if (e1[1] == e2[1]) {
        f(1, 0, 2);
    }
    else {
        f(2, 0, 1);
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

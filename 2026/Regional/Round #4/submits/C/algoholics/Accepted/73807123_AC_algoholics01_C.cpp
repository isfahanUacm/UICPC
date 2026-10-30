#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long p[n][2];
        long long a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p[i][0] >> p[i][1];
            if (p[i][0] > p[i][1])
                ++a;
            else if (p[i][0] == p[i][1])
                ++c;
            else
                ++b;
        }
        cout << a * b + c * (a + b) + (c * (c - 1)) / 2 << '\n';
    }
    return 0;
}
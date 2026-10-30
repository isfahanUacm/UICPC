#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        bool ans = true;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] > i) {
                ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
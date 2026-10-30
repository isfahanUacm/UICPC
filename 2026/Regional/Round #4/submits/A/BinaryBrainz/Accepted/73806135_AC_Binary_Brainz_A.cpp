#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = n - 1 ; i >= 0; i--) {
        if (v[i] > i + 1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
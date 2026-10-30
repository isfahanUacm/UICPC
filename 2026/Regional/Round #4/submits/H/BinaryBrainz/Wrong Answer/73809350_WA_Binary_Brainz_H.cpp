#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define ll long long


void solve() {

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    if (int(s.size()) > 1) {
        cout << 2;
    }
    else {
        if (*s.begin() == 1) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
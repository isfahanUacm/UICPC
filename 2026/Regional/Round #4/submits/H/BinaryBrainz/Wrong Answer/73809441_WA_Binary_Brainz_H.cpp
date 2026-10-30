#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define ll long long


void solve() {

    ll n;
    cin >> n;

    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int num = a[0];
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != num) {
            flag = false;
            break;
        }
    }
    if (flag) {
        if (a[0] == 1) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    else {
        cout << 2;
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
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
    ll num = a[0];
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != num) {
            flag = false;
            break;
        }
    }
    if (flag) {
        if (num == 1) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    else {
        int i = 0;
        while (i < n && a[i] == 1) {
            i++;
        }
        ll num = a[i];
        while (i < n && a[i] == num) {
            i++;
        }
        if (i == n) {
            cout << 1;
            return;
        }
        if (a[i] != 1) {
            cout << 2;
            return;
        }
        while (i < n && a[i] == 1) {
            i++;
        }
        if (i == n) {
            cout << 1;
            return;
        }
        if (a[i] != 1) {
            cout << 2;
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
        if (t)
            cout << endl;
    }

    return 0;
}
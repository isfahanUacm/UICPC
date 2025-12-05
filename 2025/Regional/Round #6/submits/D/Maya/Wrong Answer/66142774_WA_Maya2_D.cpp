#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        return;
    }

    for (int i = 0; i < n; i++) {
        int pk = k;
        for (int j = 0; j < n; j++) {
            cout << i + 1 << ' ' << 1 << endl;
            cin >> k;
            if (k > pk) {
                break;
            } else if (k < pk) {
                cout << i + 1 << ' ' << -1 << endl;
                cin >> k;
                break;
            }
        }
    }

    cout << 1 << ' ' << 1 << endl;
    cin >> k;

    if (n == 3) {
        cout << 2 << ' ' << 2 << endl;
        cin >> k;
        if (k == 1) {
            return;
        }
        cout << 2 << ' ' << -2 << endl;
        cin >> k;
        cout << 3 << ' ' << 2 << endl;
        cin >> k;
        return;
    }

    vector<int> vis(n);
    vis[0] = 1;
    for (int i = 1; i < n; i++) {
        int pk = k;
        cout << i + 1 << ' ' << 1 << endl;
        cin >> k;
        if (k != pk) {
            cout << i + 1 << ' ' << -1 << endl;
            cin >> k;
        } else {
            cout << i + 1 << ' ' << 1 << endl;
            cin >> k;
            if (k == pk) {
                cout << i + 1 << ' ' << -2 << endl;
                cin >> k;
                vis[i] = 1;
                break;
            } else {
                cout << i + 1 << ' ' << -2 << endl;
                cin >> k;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                int pk = k;
                cout << j + 1 << ' ' << 1 << endl;
                cin >> k;
                if (k != pk) {
                    cout << j + 1 << ' ' << -1 << endl;
                    cin >> k;
                } else {
                    cout << j + 1 << ' ' << i - 1 << endl;    
                    cin >> k;
                    break;
                }
            }
        }
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

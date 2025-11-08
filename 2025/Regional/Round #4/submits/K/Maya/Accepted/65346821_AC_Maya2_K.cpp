#include <bits/stdc++.h>
using namespace std;

void solve() {
    auto query = [&](int x, int y) {
        cout << "? " << x + 1 << ' ' << y + 1 << endl;
        int res;
        cin >> res;
        return res;
    };

    auto ans = [&](int x, int y) {
        cout << "! " << x + 1 << ' ' << y + 1 << endl;
    };

    int r31 = query(3, 1);
    if (r31) {
        int r30 = query(3, 0); 
        if (r30) {
            int r20 = query(2, 0);
            if (r20) {
                ans(2, 0);
                return;
            } else {
                ans(3, 0);
                return;
            }
        } else {
            int r21 = query(2, 1);
            if (r21) {
                ans(2, 1);
                return;
            } else {
                ans(3, 1);
                return;
            }
        }
    }

    int r33 = query(3, 3);
    if (r33) {
        int r32 = query(3, 2);
        if (r32) {
            int r22 = query(2, 2);
            if (r22) {
                ans(2, 2);
                return;
            } else {
                ans(3, 2);
                return;
            }
        } else {
            int r23 = query(2, 3);
            if (r23) {
                ans(2, 3);
                return;
            } else {
                ans(3, 3);
                return;
            }
        }
    }

    int r13 = query(1, 3);
    if (r13) {
        int r12 = query(1, 2);
        if (r12) {
            int r02 = query(0, 2);
            if (r02) {
                ans(0, 2);
                return;
            } else {
                ans(1, 2);
                return;
            }
        } else {
            int r03 = query(0, 3);
            if (r03) {
                ans(0, 3);
                return;
            } else {
                ans(1, 3);
                return;
            }
        }
    }

    int r10 = query(1, 0);
    if (r10) {
        int r00 = query(0, 0);
        if (r00) {
            ans(0, 0);
            return;
        } else {
            ans(1, 0);
            return;
        }
    } else {
        int r01 = query(0, 1);
        if (r01) {
            ans(0, 1);
            return;
        } else {
            ans(1, 1);
            return;
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

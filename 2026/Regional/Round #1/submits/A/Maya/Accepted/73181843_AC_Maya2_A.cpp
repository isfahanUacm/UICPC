#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, p, q;
    cin >> n >> p >> q;

    vector solved(n, vector<int>(p));
    vector<array<int, 3>> v(n); // #p, #time, #id
    vector wrong(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        v[i][2] = i;
    }
    while (q--) {
        int M, ID, T, V;
        cin >> M >> ID >> T >> V;
        ID--, T--;
        if (V) {
            if (solved[ID][T] == 0) {
                v[ID][0]--;
                solved[ID][T] = M;
                v[ID][1] += M + 20 * wrong[ID][T];
            }
        } else {
            if (solved[ID][T] == 0) {
                wrong[ID][T]++;
            }
        }
    }
    sort(v.begin(), v.end());

    int prank;
    for (int i = 0; i < n; i++) {
        int rank = i + 1;
        if (i != 0 && v[i - 1][0] == v[i][0] && v[i - 1][1] == v[i][1]) {
            rank = prank;
        }
        prank = rank;
        cout << rank << ' ' << v[i][2] + 1 << ' ' << -v[i][0] << ' ' << v[i][1] << '\n';
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

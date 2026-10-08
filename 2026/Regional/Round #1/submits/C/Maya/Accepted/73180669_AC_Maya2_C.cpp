#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int na = a.size(), nb = b.size(), nc = c.size();

    string x = a + b + c;
    int n = x.size();

    vector<int> alpha(26, -1);
    vector<int> vis(10);
    vector<int> nums(n);
    int ans = 0, aa, bb, cc;
    auto work = [&](auto&& self, int ind) -> void {
        if (ind == n) {
            int ta = 0, tb = 0, tc = 0;
            for (int i = 0; i < n; i++) {
                if (i < na) {
                    ta = ta * 10 + nums[i]; 
                } else if (i < na + nb) {
                    tb = tb * 10 + nums[i]; 
                } else {
                    tc = tc * 10 + nums[i]; 
                }
            }
            if (ta != 0 && tb != 0 && tc != 0 && ta + tb == tc && to_string(ta).size() == na && to_string(tb).size() == nb && to_string(tc).size() == nc) {
                ans++;
                aa = ta, bb = tb, cc = tc;
            }
            return;
        }

        if (alpha[x[ind] - 'A'] != -1) {
            nums[ind] = alpha[x[ind] - 'A'];
            self(self, ind + 1);
        } else {
            for (int i = 0; i < 10; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    alpha[x[ind] - 'A'] = i;
                    nums[ind] = i;
                    self(self, ind + 1);
                    vis[i] = 0;
                    alpha[x[ind] - 'A'] = -1;
                }
            }
        }
    };
    work(work, 0);

    cout << ans << '\n';
    if (ans) {
        cout << aa << '\n';
        cout << bb << '\n';
        cout << cc << '\n';
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

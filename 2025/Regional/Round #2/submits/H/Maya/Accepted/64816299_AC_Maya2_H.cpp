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

    vector<char> ch;
    for (auto x : a) {
        ch.push_back(x);
    }
    for (auto x : b) {
        ch.push_back(x);
    }
    for (auto x : c) {
        ch.push_back(x);
    }

    sort(ch.begin(), ch.end());
    ch.erase(unique(ch.begin(), ch.end()), ch.end());
    dbg(ch);

    int ans = 0;
    int ans_a, ans_b, ans_c;
    vector<char> val(26, -1);
    vector<char> vis(10);
    auto work = [&](auto&& self, int x) -> void {
        if (x == (int)ch.size()) {
            int aa = 0, bb = 0, cc = 0;
            for (auto y : a) {
                aa = aa * 10 + val[y - 'A'];
            }
            for (auto y : b) {
                bb = bb * 10 + val[y - 'A'];
            }
            for (auto y : c) {
                cc = cc * 10 + val[y - 'A'];
            }
            if (val[a[0] - 'A'] != 0 && val[b[0] - 'A'] != 0 && val[c[0] - 'A'] != 0 && aa + bb == cc) {
                ans_a = aa, ans_b = bb, ans_c = cc;
                ans++;
            }
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (val[ch[x] - 'A'] == -1 && !vis[i]) {
                val[ch[x] - 'A'] = i;
                vis[i] = true;
                self(self, x + 1);
                val[ch[x] - 'A'] = -1;
                vis[i] = false;
            }
        }
    };
    work(work, 0);

    cout << ans << '\n';
    if (ans) {
        cout << ans_a << '\n' << ans_b << '\n' << ans_c << '\n';
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

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    char ch;
    int len, mul, add;
    cin >> ch >> len >> mul >> add;
    int num = ch - 'a';
    dbg(num);
    
    string s;
    s.reserve(len);

    s.push_back(num + 'a');
    for (int64_t i = 1; i < len; i++) {
        num = (num * mul + i * add) % 26;
        s.push_back(num + 'a'); 
    }
    dbg(s);

    int q;
    cin >> q;

    vector<bool> ans(q);
    vector<int> lens(q), muls(q), adds(q);
    vector<vector<pair<int, int>>> wh(26);
    for (int i = 0; i < q; i++) {
        cin >> ch >> len >> mul >> add;
        num = ch - 'a';
        lens[i] = len;
        muls[i] = mul;
        adds[i] = add;
        wh[num].emplace_back(i, 0);
    }

    for (auto x : s) {
        int xx = x - 'a';
        auto wh_tmp = wh[xx];
        wh[xx].clear();
        for (auto [i, ind] : wh_tmp) {
            int new_ind = ind + 1;
            if (new_ind == lens[i]) {
                ans[i] = true;
                continue;
            }
            num = (xx * muls[i] + new_ind * adds[i]) % 26;
            wh[num].emplace_back(i, new_ind);
        }
    }

    
    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "BRAVO" : "REPEAT") << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mahdi.in", "r", stdin);

    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ":\n";
        solve();
    }

    return 0;
}

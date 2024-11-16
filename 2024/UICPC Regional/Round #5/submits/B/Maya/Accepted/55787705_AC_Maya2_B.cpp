#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

vector<pair<int64_t, int64_t>> v;
void solve() {
    int64_t n;
    cin >> n;
    
    pair<int64_t, int64_t> p = {n, 2e18};
    int ans = lower_bound(v.begin(), v.end(), p) - v.begin();
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    auto work = [&](auto &&self, int num, int last, int64_t mul) {
        if (last == 10 || num == 0) {
            if (s != "") {
                v.emplace_back(stoll(s), mul);
            }
            return;
        }
        string tmp_s = s;
        int64_t tmp_mul = mul;
        for (int i = 0; i <= num; i++) {
            self(self, num - i, last + 1, mul);
            s.push_back('0' + last);
            mul *= last;
        }
        s = tmp_s;
        mul = tmp_mul;
    };
    work(work, 18, 1, 1);
    v.emplace_back(10, 0);

    sort(v.begin(), v.end(), [&](auto a, auto b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second; 
    });
    v.erase(unique(v.begin(), v.end(), [&](auto a, auto b) {
            return a.second == b.second; 
    }), v.end());
    sort(v.begin(), v.end(), [&](auto a, auto b) {
        return a.first < b.first; 
    });

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

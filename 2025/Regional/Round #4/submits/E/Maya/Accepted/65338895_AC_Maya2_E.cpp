#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;

constexpr int INF32 = 1E9;
constexpr i64 INF64 = 1E18;
constexpr int MOD = 1e9 + 7;

#define sz(x) (int)x.size()
#define F first
#define S second

const int N = 2e5 + 1;

void solve() {
    i64 a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        vector<pair<int, int>> u, v;
        int nr, ny;
        cin >> nr;
        for (int i = 0; i < nr; i++) {
            int x, y;
            cin >> x >> y;
            u.push_back({x, y});
        }
        
        cin >> ny;
        for (int i = 0; i < ny; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        vector<i64> p, q;
        i64 mn1 = INF64, mn2 = INF64;
        for (auto [x, y] : u) {
            p.push_back((x - 144) * (x - 144) + (y - 84) * (y - 84));
            mn1 = min(mn1, p.back());
        }
        for (auto [x, y] : v) {
            q.push_back((x - 144) * (x - 144) + (y - 84) * (y - 84));
            mn2 = min(mn2, q.back());
        }

        if (mn1 > mn2) {
            for (i64 x : q) {
                if (x < mn1) {
                    a += 1;
                }
            }
        } else {
            for (i64 x : p) {
                if (x < mn2) {
                    b += 1;
                }
            }
        }
    }

    cout << b << " " << a << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--)
        solve();

    return 0;
}


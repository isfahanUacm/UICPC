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
        vector<pair<i64, i64>> u, v;
        i64 nr, ny;
        cin >> nr;
        for (int i = 0; i < nr; i++) {
            i64 x, y;
            cin >> x >> y;
            u.push_back({x, y});
        }
        
        cin >> ny;
        for (int i = 0; i < ny; i++) {
            i64 x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        set<i64> p, q;
        for (auto [x, y] : u) {
            p.insert((x - 144) * (x - 144) + (y - 84) * (y - 84));;
        }
        for (auto [x, y] : v) {
            q.insert((x - 144) * (x - 144) + (y - 84) * (y - 84));;
        }

        if (*p.begin() > *q.begin()) {
            i64 mn = *p.begin();
            for (i64 x : q) {
                if (x < mn) {
                    a += 1;
                }
            }
        } else if (*p.begin() < *q.begin()) {
            i64 mn = *q.begin();
            for (i64 x : p) {
                if (x < mn) {
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


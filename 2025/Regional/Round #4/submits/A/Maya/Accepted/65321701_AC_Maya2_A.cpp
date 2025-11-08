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
    int r, g, b, cr, cg, cb, crg, cgb;
    cin >> r >> g >> b >> cr >> cg >> cb >> crg >> cgb;

    r -= cr, g -= cg, b -= cb;
    r = max(0, r);
    g = max(0, g);
    b = max(0, b);

    int ans = r + g + b;

    if (crg >= r) {
        crg -= r;
        if (cgb >= b) {
            cgb -= b;
            if (crg + cgb >= g) {
                cout << ans << endl;
                return;
            } 
        }
    }
    cout << -1 << endl;;
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


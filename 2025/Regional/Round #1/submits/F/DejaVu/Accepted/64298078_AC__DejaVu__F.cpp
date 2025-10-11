#include <bits/stdc++.h>
#include <functional>
using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = unsigned int64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;
using my_pair = pair<int, pair<int, int>>;

constexpr int INF32 = 1E9;
constexpr i64 INF64 = 1E18;
constexpr int MOD = 1e9 + 7;

#define sz(x) (int)x.size()
#define F first
#define S second

const int N = 2e5 + 1;
int cnt = 1;

void solve() {
    i64 n;
    cin >> n;

    function<i128(i128)> f = [&](i128 x) -> i128 {
        return (2 * x + 1) * (x + 1) * x / 6;
    };

    i128 l = 1, r = 1e7, ans = r;
    while (l <= r) {
        i128 m = (l + r) / 2;
        i128 val = f(m);
        if (val >= n) {
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    i128 p = (ans - 1) * (ans - 1);
    i128 q = f(ans - 1);

    n -= q;
    if (n > ans * (ans + 1) / 2) {
        n -= ans * (ans + 1) / 2;
        p += ans;

        i128 l1 = 1, r1 = ans - 1, ans1 = r1;
        while (l1 <= r1) {
            i128 m1 = (l1 + r1) / 2;
            if (m1 * (ans - 1) - m1 * (m1 - 1) / 2 >= n) {
                ans1 = min(ans1, m1);
                r1 = m1 - 1;
            } else {
                l1 = m1 + 1;
            }
        }

        cout << "Case "<< cnt++ << ": " << i64(p + ans1) << endl;
    } else {
        i128 l1 = 1, r1 = ans, ans1 = r1;
        while (l1 <= r1) {
            i128 m1 = (l1 + r1) / 2;
            if (m1 * (m1 + 1) / 2 >= n) {
                ans1 = min(ans1, m1);
                r1 = m1 - 1;
            } else {
                l1 = m1 + 1;
            }
        }

        cout << "Case "<< cnt++ << ": " << i64(p + ans1) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("army.in", "r", stdin);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}


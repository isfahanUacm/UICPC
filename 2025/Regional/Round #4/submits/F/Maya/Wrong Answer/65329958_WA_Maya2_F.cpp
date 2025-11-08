#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
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
    i64 n, k;
    cin >> n >> k;
    multiset<i64> s;
    i64 sm = 0;
    for (int i = 0; i < n; i++) {
        i64 u;
        cin >> u;
        s.insert(u);
        sm += u;
    }

    while (n > k) {
        i64 u = *s.begin();
        i64 v = *s.rbegin();

        if (sm - n * u > v * n - sm) {
            s.erase(s.begin());
            sm -= u;
        } else {
            s.erase(s.find(*s.rbegin()));
            sm -= v;
        }

        n -= 1;
    }


    ld mean = 1.0 * sm / n, ans = 0.0;
    for (i64 u : s) {
        ans += (mean - u) * (mean - u);
    }

    cout << fixed << showpoint << setprecision(6) << ans << endl;
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


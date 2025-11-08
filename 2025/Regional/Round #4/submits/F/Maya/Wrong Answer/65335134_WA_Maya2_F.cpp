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
    int n, k;
    cin >> n >> k;
    vector<int> s(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> s[i];
    }

    sort(s.begin() + 1, s.end());

    i64 sm1 = 0, sm2 = 0;
    for (int i = 1; i < k; i++) {
        sm1 += s[i];
        sm2 += s[i] * s[i];
    }

    ld ans = 1e18;
    for (int i = k; i <= n; i++) {
        sm1 -= s[i - k];
        sm2 -= s[i - k] * s[i - k];
        sm1 += s[i];
        sm2 += s[i] * s[i];

        ld mean = 1.0 * sm1 / k;
        ld res = mean * mean * k + sm2 - 2 * mean * sm1;
        ans = min(ans, res);
    }

    cout << fixed << setprecision(6) << ans << endl;
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


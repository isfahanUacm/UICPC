#include <cstdint>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

constexpr int MOD = 998244353;

map<int64_t, int> memo;

int solve(int64_t n, int t) {
    assert(n >= 0);
    if (n == 0) {
        return 1;
    }

    auto it = memo.find(n);
    if (it != end(memo)) {
        return it->second;
    }

    int ans = 0;
    for (int d = n % 2; d <= t && d <= n; d += 2) {
        assert((n - d) % 2 == 0);
        ans += solve((n - d) / 2, t);
        if (ans >= MOD)
            ans -= MOD;
    }

    return memo[n] = ans;
}

int32_t main() {
    int64_t n;
    int t;
    cin >> n >> t;

    cout << solve(n, t) << '\n';

    return 0;
}

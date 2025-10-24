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
    int n, s;
    cin >> n >> s;

    char c;
    cin >> c;

    if (c == 'L') {
        cout << (s + 1) / 2 << " " << (s + 1) / 2 << " " << n - s << endl;
    } else {
        cout << (s - 1) << " " << (n - s + 2) / 2 << " " << (n - s + 2) / 2 << endl;
    }
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


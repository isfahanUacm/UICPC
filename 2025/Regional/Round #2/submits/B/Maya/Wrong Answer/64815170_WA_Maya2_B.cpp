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
    int n, p;
    cin >> n >> p;

    vector<int> a(n), b(n), c(n);
    for (int j  = 0; j < n; j++) {
        for (int i = 0; i < p; i++) {
            char x;
            int u;
            cin >> x >> u;

            if (x == '+') {
                a[i]++;
            }

            if (!(x == '-' and u == 0)) {
                b[i]++;
            }

            c[i] += u;
        }
    }

    for (int i = 0; i < p; i++) {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
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


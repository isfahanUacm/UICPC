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
    int n, p, q;
    cin >> n >> p >> q;

    vector<vector<i64>> atmp(n, vector<i64>(p));
    vector<vector<bool>> solved(n, vector<bool>(p));
    vector<i64> ns(n), np(n);

    while (q--) {
        i64 m, id, t, v;
        cin >> m >> id >> t >> v;
        id--, t--;

        if (v) {
            solved[id][t] = true;
            np[id] += atmp[id][t] * 20;
            np[id] += m;
            ns[id] += 1;
        } else {
            if (!solved[id][t]) {
                atmp[id][t] += 1;
            }
        }
    }

    vector<tuple<int, int, int>> teams;
    for (int i = 0; i < n; i++) {
        teams.push_back({-ns[i], np[i], i + 1});
    }

    sort(teams.begin(), teams.end());
    int rnk = 1;
    cout << 1 << " " << get<2>(teams[0]) << " " << -get<0>(teams[0]) << " " << get<1>(teams[0]) << endl;
    for (int i = 1; i < n; i++) {
        if (get<0>(teams[i]) == get<0>(teams[i - 1]) and get<1>(teams[i]) == get<1>(teams[i - 1])) {
            cout << rnk << " " << get<2>(teams[i]) << " " << -get<0>(teams[i]) << " " << get<1>(teams[i]) << endl;
        } else {
            cout << i + 1 << " " << get<2>(teams[i]) << " " << -get<0>(teams[i]) << " " << get<1>(teams[i]) << endl;
            rnk = i + 1;
        }
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


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
    int n, m;
    cin >> n >> m;

    vector<set<int>> r(n);

    vector<int> p(n);
    vector<bool> vis(m);
    vector<bool> good(m);
    vector<bool> used(m);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        good[p[i]] = true;

        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            r[i].insert(x);
        }
    }

    set<int> u[m], v[m];
    for (int i = 0; i < n; i++) {
        for (int x : r[i]) {
            u[p[i]].insert(x);
        }
        
        if (!vis[p[i]]) {
            for (int x : r[i]) {
                v[p[i]].insert(x);
            }
            vis[p[i]] = true;
        } else {
            set<int> intersect;
            set_intersection(r[i].begin(), r[i].end(), v[p[i]].begin(), v[p[i]].end(), inserter(intersect, intersect.begin()));
            v[p[i]] = intersect;
        }
    }

    set<int> locs;
    bool valid = true;
    for (int i = m - 1; i >= 0 and valid; i--) {
        locs.insert(i);

        if (!good[i]) {
            continue;
        }

        int inc = -1;
        for (int x : v[i]) {
            if (!used[x]) {
                inc = x;
                break;
            }
        }

        if (inc == -1) {
            valid = false;
            break;
        }

        if (locs.empty()) {
            valid = false;
            break;
        }

        used[inc] = true;
        locs.erase(locs.begin());

        for (int x : u[i]) {
            if (!used[x]) {
                if (locs.empty()) {
                    valid = false;
                    break;
                } else {
                    used[x] = true;
                    locs.erase(locs.begin());
                }
            }
        }
    }

    cout << (valid ? "yes" : "no") << endl;;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}


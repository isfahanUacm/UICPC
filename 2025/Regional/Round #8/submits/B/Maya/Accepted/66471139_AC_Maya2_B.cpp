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
bool tst = true;

struct KMP {
    string t;
    int m;
    vector<int> f, deg, dep, sub_sz;
    vector<vector<int>> adj, nxt;

    KMP(const string& t) : t(t) {
        m = sz(t);
        f.resize(m + 1);
        deg.resize(m + 1);
        dep.resize(m + 1);
        sub_sz.resize(m + 1);
        adj.resize(m + 1);
        build();
    }

    void dfs(int u, int p) {
        sub_sz[u] = 1;
        for (int v : adj[u]) {
            if (v != p) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
                sub_sz[u] += sub_sz[v];
            }
        }
    }

    void build() {
        f[0] = -1;
        int k = -1;

        for (int i = 1; i <= m; i++) {
            while (k != -1 and t[k] != t[i - 1]) {
                k = f[k];
            }
            f[i] = ++k;
            deg[f[i]] += 1;
            adj[f[i]].push_back(i);
            adj[i].push_back(f[i]);
        }

        dfs(0, -1);
    }
};

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        tst = false;
        return;
    }

    string s;
    cin >> s;

    KMP kmp(s);
    int ans = kmp.f[n];
    string p = s;
    for (int i = ans; i < n; i++) {
        p.push_back(s[i]);
    }

    cout << p << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (tst)
        solve();

    return 0;
}
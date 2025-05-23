#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'

void solve(int tc) {
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> mt;
    vector<bool> used;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        if (1 <= a[i] && a[i] <= n) {
            g[i+1].push_back(a[i]);
        }
        for (int j=0; j<=21; j++) {
            if (!((a[i]>>j)&1)) continue;

            int t = a[i] & (~(1<<j));
            if (1 <= t && t <= n) {
                g[i+1].push_back(t);
            }
        }
    }
    dbg(g);

    auto try_kuhn = [&] (auto&& self, int v) -> bool {
        if (used[v])
            return false;
        used[v] = true;
        for (int to : g[v]) {
            if (mt[to] == -1 || self(self, mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    };

    mt.assign(n+1, -1);
    for (int v = 1; v <= n; ++v) {
        used.assign(n+1, false);
        try_kuhn(try_kuhn, v);
    }
    int c = 0;
    for (int i=1; i<=n; i++) {
        if (mt[i] != -1) {
            c++;
        }
    }
    dbg(c);
    cout << (c == n ? "Yes" : "No") << nl;

    /*
    for (int i = 0; i < n; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
    */
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}


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
    vector<int> a(n);
    vector g(n, vector<int>());
    vector<int> v1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] != -1) {
            g[a[i]].push_back(i);
        } else {
            v1.push_back(i);
        }
    }
    vector<int> cnt(n);
    auto dfs = [&] (auto&& self, int u, int par=-1) -> void {
        cnt[u]++;
        for (int v: g[u]) {
            if (v == par) continue;
            self(self, v);
            cnt[u] += cnt[v];
        }
    };
    for (int i: v1) {
        dfs(dfs, i, -1);
    }
    int mx = -1, idx = -1;
    for (int i: v1) {
        if (cnt[i] > mx) {
            idx = i;
            mx = cnt[i];
        }
    }
    cout << idx+1 << ' ' << mx << nl;
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


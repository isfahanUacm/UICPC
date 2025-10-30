#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve(int tc) {
    int n; cin >> n;
    int l, h; cin >> l >> h;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        while (a[i] < l) {
            a[i] += 12;
            b[i]++;
        }
        while (a[i] > h) {
            a[i] -= 12;
            b[i]--;
        }
    }
    dbg(b);
    const int INF = 1e9+5;
    int c = 0, mn = INF, beg = -1, res = 0;
    for (int i=0; i<n; i++) {
        c++;
        if (i+1 == n || b[i] != b[i+1]) {
            if (c < mn) {
                mn = c;
                res = b[i];
                beg = i-c+1;
            }
            c = 0;
        }
    }
    int end = beg+mn;
    beg--;
    int ans = mn;
    auto ok = [&] (int x) {
        int y = x+12*res;
        return l <= y && y <= h;
    };
    while (beg >= 0 && ok(a[beg])) {
        beg--;
        ans++;
    }
    while (end < n && ok(a[end])) {
        end++;
        ans++;
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}


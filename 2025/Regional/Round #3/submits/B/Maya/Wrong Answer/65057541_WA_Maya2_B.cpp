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
        int t = a[i];
        while (t < l) {
            t += 12;
            b[i]++;
        }
        while (t > h) {
            t -= 12;
            b[i]--;
        }
    }
    dbg(b);
    const int INF = 1e9+5;
    int c = 0, mn = INF, beg = -1;
    for (int i=0; i<n; i++) {
        c++;
        if (i+1 == n || b[i] != b[i+1]) {
            if (c < mn) {
                mn = c;
                beg = i-c+1;
            }
            c = 0;
        }
    }
    int end = beg+mn;
    dbg(beg, end);

    auto ok = [&] (int x, int t) {
        int y = x+12*t;
        return l <= y && y <= h;
    };
    int ans = 0;
    for (int i = -15; i<=15; i++) {
        bool good = 1;
        for (int j=beg; j<end; j++) {
            if (!ok(a[j], i)) {
                good = 0;
                break;
            }
        }
        if (!good) continue;

        int res = mn;

        int beg1 = beg-1, end1 = end;
        while (beg1 >= 0 && ok(a[beg1], i)) {
            beg1--;
            res++;
        }
        while (end1 < n && ok(a[end1], i)) {
            end1++;
            res++;
        }
        ans = max(ans, res);
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


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
#define nl endl; cout.flush();

void solve(int tc) {
    int n; cin >> n;
    vector<int> a(n);
    int l = 0, r = n-1;
    int C = 125;
    while (C--) {
        cout << l+1 << ' ' << r+1 << nl;

        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int p; cin >> p;
        if (p >= 70) {
            break;
        }
        dbg(a);

        int sum = 0, mn = 0;
        int best = 0, L = -1;
        l = -1;
        for (int i=0; i<n; i++) {
            sum += (a[i]==0?2:-1);
            if (sum-mn > best) {
                best = sum;
                r = i;
                L = l+1;
            }
            if (sum < mn) {
                mn = sum;
                l = i;
            }
        }
        l = L;
    }
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



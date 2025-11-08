#include<bits/stdc++.h>
#include <iomanip>
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
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    ld ans = 0;
    sort(b.begin(), b.end(), greater<int>());
    ld sum = 0;
    for (int i=0; i<n; i++) {
        sum += b[i];
        ans = max(ans, (sum+a[i])/(i+1));
    }
    cout << fixed << setprecision(6) << ans << nl;

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

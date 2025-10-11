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
    cout << "Case " << tc << ":" << nl;
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin>> a[i];
    }
    assert((int)a.size() >= 11);
    sort(a.begin(), a.end());
    int x = a[0]/2, y = a[0]-x;
    vector<int> v1, v2;
    for (int i=0; i<6; i++) {
        v2.push_back(a[i]-x);
    }
    for (int i=0; i<6; i++) {
        v1.push_back(a[i]-y);
    }
    for (int i: v1) {
        cout << i << ' ';
    }
    cout << nl;
    for (int i: v2) {
        cout << i << ' ';
    }
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dice.in", "r", stdin);
    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}


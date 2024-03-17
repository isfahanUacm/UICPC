#include "bits/stdc++.h"
#ifndef LOCAL
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#else
#define fastio
#endif

#define nl '\n'
#define pb push_back
#define arr array
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long; using ld = long double; using str = string;
const int N = 3e5+5;
int cm, gm, cs, gs, rate;
void solve() {
    cin >> cm >> gm >> cs >> gs >> rate;
    int x = cm+rate*gm, y = cs+rate*gs;
    cout << (x >= y? "Yes": "No") << nl;
}

int32_t main() {
    int t=1;
//cin >> t;
    while(t--) {
        solve();
        cerr << "-----------------" << nl;
    }
}
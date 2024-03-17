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
const int N = 2e5+5;
void solve() {
    int n; cin >> n;
    vector<int> v(n+5);
    v[0] = 1; v[1] = 1;
    for (int i=2; i<=n; i++) {
        v[i] = v[i-1]+v[i-2];
    }
    cout << v[n] << nl;
}

int main() {
  int T = 1;
  //cin >> T;
  while (T--) {
    solve();
  }
    return 0;
}


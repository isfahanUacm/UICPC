#include "bits/stdc++.h"
#ifndef LOCAL
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#else
#define fastio
#endif

#define nl endl
#define pb push_back
#define arr array
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long; using ld = long double; using str = string;

const int N = 2e5+5;
int n;
void solve() {
 cin >> n;
 int ans = 1;
 int x, y;
 while (n--) {
  cin >> x >> y;
  if (x==ans) {
   ans = y;
  } else if (y==ans) {
   ans = x;
  }
 }
 cout << ans << nl;
}
int32_t main() {
 fastio
 int t=1;
//cin >> t;
 while (t--) {
  solve();
  cerr << "-----------" << nl;
 }
 return 0;
}

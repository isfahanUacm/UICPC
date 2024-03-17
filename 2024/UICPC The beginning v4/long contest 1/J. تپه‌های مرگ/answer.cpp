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
int a, b;
void solve() {
	cin >> a >> b;
	if (a > b) swap(a, b);
	int x = b-a;
	if (a-x>=0 && a-x == b-2*x && (a-x)%3==0) cout << "YES" << nl;
	else cout << "NO" << nl;
}
int32_t main() {
 fastio
 int t=1;
cin >> t;
 while (t--) {
  solve();
  //cerr << "-----------" << nl;
 }
 return 0;
}


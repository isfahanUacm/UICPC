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
int n, a[N];
void solve() {
	cin >> n;
	for (int i=0; i<2*n; i++) {
		cin >> a[i];
	}
	sort(a, a+2*n, greater<int>());
	ll ans = 0;
	for (int i=0; i<2*n; i+=2) {
		ans += a[i+1];
	}
	cout << ans << nl;

}
int32_t main() {
 fastio
 int t=1;
//cin >> t;
 while (t--) {
  solve();
 }
 return 0;
}


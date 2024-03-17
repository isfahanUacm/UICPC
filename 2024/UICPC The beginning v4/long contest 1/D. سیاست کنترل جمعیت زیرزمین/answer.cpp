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

const int N = 3e5+5;
void solve() {
	int n; cin >> n;
	if (n%3==0) cout << "Second" << nl;
	else cout << "First" << nl;
}
int32_t main() {
	fastio
	int t=1;
cin >> t;
	while (t--) {
		solve();
		cerr << "-----------" << nl;
	}
	return 0;
}

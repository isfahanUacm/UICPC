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
int a, b, c, d;
void solve() {
	cin >> a >> b >> c >> d;
	if (d==0) {
		cout << "SADKEK" << nl;
		return;
	}
	 if (b==0 || (a==0&&c==0)) {
		cout << "KEKW" << nl;
		return;
	 }
	 if (c==0) {
		 if ((a<d || b<d) || (a==d && b<=2*d) || (b==d && a<=2*d)) {
			cout << "KEKW" << nl;
		 } else cout << "SADKEK" << nl;
	 } else if (a==0) {
		 if ((b<d || c<d) || (b==d && c<=2*d) || (c==d && b<=2*d)) {
			cout << "KEKW" << nl;
		 } else cout << "SADKEK" << nl;
	 } else {
		 if ((b<d || a+c<d) || (b == d && a+c<=2*d) || ((a+c==d && b<=2*d))) {
			cout << "KEKW" << nl;
		 } else cout << "SADKEK" << nl;
	 }
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


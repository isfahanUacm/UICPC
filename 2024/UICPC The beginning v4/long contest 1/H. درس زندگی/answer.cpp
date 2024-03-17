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
const int N = 1e6+5;
int a, b;
void solve() {
	cin >> a >> b;
	if ((a+b)%2==0) {
		cout << "Matine Tanha" << nl;
	} else cout << "Pouyaye Hakim" << nl;

}

int32_t main() {
    int t=1;
cin >> t;
    while(t--) {
        solve();
        cerr << "-----------------" << nl;
    }
}

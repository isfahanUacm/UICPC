/**
 * created by: poconut(MPouya)
 */
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MOD1 998244353
#define nl "\n"
#define INF 2e9
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ar array
#define lb lower_bound
#define ub upper_bound
#define tostr to_string
typedef string str; typedef long double ld; typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef vector<pii> vpii; typedef vector<pll> vpll;
#ifdef ONPC
#include "/home/pouya/cp.cpp"
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(...)
#define arrdebug(...)
#define delay()
#define LINE
#define TIME
#endif
/*******************************************************************************/

const int mxn = 150+10;
pii a[mxn];
void solve() {
    int n; cin >> n;
    int x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        a[i] = {x, y};
    }
    vector<ld> v;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i].ff+a[j].ff>=76) {
                v.pb((long double)a[i].ss*a[j].ss/100);
            }
        }
    }

    sort(all(v));
    cout << fixed << setprecision(9) << v.back() << nl;
}

int main() {
    fastio();
	int T = 1;
	cin >> T;
	while (T--) {
        solve();
        LINE
	}
    TIME
    return 0;
}



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

const int mxn = 1000+10;
int a[mxn][mxn], b[mxn][mxn];
void solve() {
    int n, q; cin >> n >> q;
    for (int i=1; i<=n; i++) {
        str s;
        cin >> s;
        for (int j=0; j<n; j++) {
            if (s[j]=='*') {
                a[i][j+1]=1;
                b[i][j+1]=1;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            b[i][j] += b[i][j-1];
        }
    }
    for (int j=1; j<=n; j++) {
        for (int i=2; i<=n; i++) {
            b[i][j] += b[i-1][j];
        }
    }
    /*
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << b[i][j] << ' ';
        } cout << nl;
    }
    */
    while (q--) {
        int x1, x2, y2, y1;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << b[x2][y2]+b[x1-1][y1-1]-(b[x1-1][y2]+b[x2][y1-1]) << nl;
    }

}

int main() {
    fastio();
	int T = 1;
	//cin >> T;
	while (T--) {
        solve();
        LINE
	}
    TIME
    return 0;
}


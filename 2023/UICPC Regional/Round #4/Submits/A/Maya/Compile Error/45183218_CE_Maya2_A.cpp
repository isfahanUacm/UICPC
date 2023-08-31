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
typedef string str; typedef long double ld; typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<int, int> pi; typedef pair<ll, ll> pl; typedef vector<pi> vpi; typedef vector<pl> vpl;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
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

const int N = 2000+10;
ld n, l, w, a[N];
ld b[N];

ld dis(ld x, ld y) {
    ld ans = sqrt((x-y)*(x-y)+ w*w);
    return ans;
}
void solve() {
    cin >> n >> l >> w;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    n/=2;
    b[0] = 0;
    for (int i=1; i<n; i++) {
        b[i] = b[i-1]+(l/(n-1.0));
    }
    vector<ld> v;
    ld ans = 0;
    for (int i=0; i<n; i++) {
        ld op1 = dis(a[2*i], b[i])+fabs(a[2*i+1]-b[i]);
        ld op2 = dis(a[2*i+1], b[i])+fabs(a[2*i]-b[i]);
        if (op1<op2) ans+=op1;
        else ans+=op2;
    }
    cout << fixed << setprecision(9) << ans << nl;

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



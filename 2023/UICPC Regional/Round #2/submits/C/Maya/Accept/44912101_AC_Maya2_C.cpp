#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define pf push_front
#define nl '\n'
#define MOD 1000000007
#define MOD1 998244353
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
/**************************************************************/

int a[109];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(a, a + n), mn = *min_element(a, a + n);
    int ans = 2 * (mx - mn);
    cout << ans << nl;
}

int32_t main()
{
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    
    #ifdef LOCAL
    LINE
    TIME
    #endif
    
    return 0;
}
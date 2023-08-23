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

const int N = 2e5 + 9;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    ll ans = 0;
    for (int i = 2; i < n; i += 3) ans += a[i];
    cout << ans << nl;
}

int32_t main()
{
    fastio();
    solve();
    
    #ifdef LOCAL
    LINE
    TIME
    #endif
    
    return 0;
}
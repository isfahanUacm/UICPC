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
#ifdef LOCAL
#include "/home/mamad/debug.h"
#else
#define debug(...) 
#define arrdebug(...) 
#define delay() 
#define LINE 
#define TIME 
#endif
/**************************************************************/

const int N = 2e5 + 9;
pl a[N];
priority_queue<ll> pq;

void solve()
{
    ll k, n, y, p, ans = -1;
    cin >> k >> n;
    cin >> y >> p;
    a[0].F = y, a[0].S = p;
    for (int i = 1; i <= n + k - 2; i++) cin >> a[i].F >> a[i].S;
    sort(a, a + n + k - 1);
    arrdebug(a, n + k - 1);
    for (int i = 0; i < k; i++) pq.push(a[i].S);
    for (int i = k; i <= n + k - 2; i++) {
        ll u = pq.top();
        pq.pop();
        pq.push(a[i].S);
        debug(u);
        if (u == p) {
            ans = i - k + a[0].F;
            break;
        }
    }
    
    if (ans == -1) cout << "unknown\n";
    else cout << ans << nl;
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
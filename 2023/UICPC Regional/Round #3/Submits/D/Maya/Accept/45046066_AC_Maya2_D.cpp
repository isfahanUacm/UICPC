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
#include "/home/mmd/debug.h"
#else
#define debug(...) 
#define arrdebug(...) 
#define delay() 
#define LINE 
#define TIME 
#endif
/**************************************************************/

ll sum[20], pw10[20], num[20], sum9[20];

ll f(ll x) {
    if (x <= 0) return 0;
    string s = to_string(x);    
    int n = sz(s);
    string tmp = ""; 
    debug(s);
    for (int i = n - 1; i >= 0; i--) {
        tmp = s[i] + tmp;
        num[i] = stoll(tmp);
    }
    num[n] = 0;
    ll ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            ans += sum[(s[i] - '0' - 1)] * pw10[n - i - 1]; debug(ans);
            ans += (s[i] - '0') * (num[i + 1] + 1); debug(ans);
            ans += (s[i] - '0') * sum9[n - i - 1]; debug(ans);
        }
    }
    return ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll ans1 = f(a - 1), ans2 = f(b);
    ll ans = ans2 - ans1;
    cout << ans << nl;
}

int32_t main()
{
    fastio();
    for (int i = 1; i <= 9; i++) sum[i] = sum[i - 1] + i;
    pw10[0] = 1;
    for (int i = 1; i <= 16; i++) pw10[i] = pw10[i - 1] * 10;
    for (int i = 1; i <= 16; i++) sum9[i] = (sum9[i - 1] * 10) + (pw10[i - 1] * sum[9]);
    arrdebug(sum9, 20);
    int t;
    cin >> t;
    while (t--) {
        solve();
        LINE
    }
    
    #ifdef LOCAL
    TIME
    #endif
    
    return 0;
}
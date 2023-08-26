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

pair<ld, int> a[159];
priority_queue<pair<ld, pair<int, vector<int>>>> q;
int dis[159];


void solve()
{
    while (!q.empty()) q.pop();
    memset(dis, 0, sizeof dis);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    sort(a, a + n);

    ld mn = 1e9;
    for (int i = 0; i < n; i++) {
        ld x = 100;
        if (a[i].F >= 76) mn = min(mn, a[i].S / x);
    }
    if (mn != 1e9) {
        cout << mn << nl;
        return;
    }

    for (int i = 0; i < n; i++) {
        ld tmp = 1.0 * a[i].S / 100;
        a[i].S = a[i].F;
        a[i].F = tmp;

    }
    sort(a, a + n, greater<pair<ld, int>>());

    vector<int> v(77, 0);
    q.push({1, {0, v}});

    while (!q.empty()) {
        auto u = q.top();
        vi v1 = u.S.S;
        ld per = u.F;
        int d = u.S.F;
        q.pop();

        for (int i = 0; i < n; i++) {
            if (v1[i] == 0) {
                if (d + a[i].S >= 76) {
                    ld ans = u.F * a[i].F * 100;
                    cout << fixed << setprecision(6);
                    cout << ans << nl;
                    return;
                }
                if (per * a[i].F > dis[d + a[i].S]) {
                    dis[d + a[i].S] = per * a[i].F;
                    v1[i] = 1;
                    q.push({per * a[i].F, {d + a[i].S, v1}});
                    v1[i] = 0;
                }
            }
        }
    }
}

int32_t main()
{
    fastio();
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
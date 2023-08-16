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

int a[30], room[30];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(room, room + 20, 1);

    int x = 0;
    bool f;
    while (true) {
        f = true;
        for (int i = 12; i >= 1; i--) {
            if (a[i] && room[i + x] && i + x <= 12) {
                f = false;
                a[i]--;
                room[i + x]--;
                if (x >= 2) room[x - 1]++;
                break;
            }
        }
        if (f) x++;
        else x = 0;
        if (x == 12) break;
    }

    int ans = -1;
    bool done = true;
    for (int i = 12; i >= 1; i--) {
        if (room[i] == 0) {
            ans = i;
            break;
        }
    }
    for (int i = 1; i <= 12; i++) if (a[i]) done = false;
    if (done && ans != -1) cout << ans << nl;
    else cout << "impossible\n";
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
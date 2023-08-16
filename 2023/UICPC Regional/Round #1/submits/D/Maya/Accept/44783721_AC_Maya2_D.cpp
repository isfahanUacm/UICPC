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

const int N = 1e6 + 9;
int mark[N];
queue<pi> q;

void solve()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    ll ans = -1;

    q.push({s, 0});
    mark[s] = 1;
    while (!q.empty()) {
        int x = q.front().F;
        int num = q.front().S;
        q.pop();

        if (x == g) {
            ans = num;
            break;
        }

        if (x + u <= f && !mark[x + u]) {
            mark[x + u] = 1;
            q.push({x + u, num + 1});
        }
        if (x - d >= 1 && !mark[x - d]) {
            mark[x - d] = 1;
            q.push({x - d, num + 1});
        }
    }

    if (ans != -1) 
        cout << ans << nl;
    else    
        cout << "use the stairs\n";
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
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
int gx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, gy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define xx (x + gx[i])
#define yy (y + gy[i])
#define condition(n, m) ((xx >= 0) && (xx <= (n) - 1) && (yy >= 0) && (yy <= (m) - 1))
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

const int N = 1e3 + 9;
char g[N][N];
vector<pi> f1, f2, p1, p2;

void solve()
{
    f1.clear(); f2.clear(); p1.clear(); p2.clear();

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < w; i++) for (int j = 0; j < h; j++) cin >> g[i][j];

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (g[i][j] == '*') f1.pb({i, j});
            else if (g[i][j] == '@') p1.pb({i, j});
        }
    }

    int ans = 0;
    while (!p1.empty()) {
        ans++;
        while (!f1.empty()) {
            int x = f1.back().F, y = f1.back().S;
            f1.pop_back();
            for (int i = 0; i < 4; i++) {
                if (condition(w, h)) {
                    if (g[xx][yy] == '.' || g[xx][yy] == '@') {
                        g[xx][yy] = '*';
                        f2.pb({xx, yy});
                    }
                }
            }
        }
        f1 = f2;
        f2.clear();

        while (!p1.empty()) {
            int x = p1.back().F, y = p1.back().S;
            p1.pop_back();
            for (int i = 0; i < 4; i++) {
                if (condition(w, h)) {
                    if (g[xx][yy] == '.') {
                        g[xx][yy] = '@';
                        p2.pb({xx, yy});
                    }
                }
                else {
                    cout << ans << nl;
                    return;
                }
            }
        }
        p1 = p2;
        p2.clear();
    }

    cout << "IMPOSSIBLE\n";
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
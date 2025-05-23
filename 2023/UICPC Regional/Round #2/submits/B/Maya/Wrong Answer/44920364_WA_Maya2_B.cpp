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

const int N = 1e4 + 9;
pi a[N];
pi mark[N];

void solve ()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> a[i].F >> a[i].S;
    for (int i = 0; i <= m; i++) mark[i] = {-1, 0};
    
    for (int i = 0; i < m; i++) {
        if (mark[a[i].F].F == -1) {
            mark[a[i].F] = {i, 1};
        }
        else if (mark[a[i].S].F == -1) {
            mark[a[i].S] = {i, 2};
        }
        else {
            int x = mark[a[i].F].F;
            int y = mark[a[i].F].S;
            mark[a[i].F] = {i, 1};
            int zz = 0;
            bool f = false;
            while (true) {
                if (y == 1) {
                    if (mark[a[x].S].F == -1) {
                        mark[a[x].S] = {x, 2};
                        break;
                    }
                    else {
                        int xx = mark[a[x].S].F;
                        y = mark[a[x].S].S;
                        mark[a[x].S] = {x, 2};
                        x = xx;
                    }
                }
                else {
                    if (mark[a[x].F].F == -1) {
                        mark[a[x].F] = {x, 1};
                        break;
                    }  
                    else {
                        int xx = mark[a[x].F].F;
                        y = mark[a[x].F].S;
                        mark[a[x].F] = {x, 1};
                        x = xx;
                    }
                }
                
                if (zz++ > 4 * n) {
                    f = true;
                    break;;
                }
            }
                
            if (!f) break;
            x = mark[a[i].S].F;
            y = mark[a[i].S].S;
            mark[a[i].S] = {i, 2};
            zz = 0;
            while (true) {
                if (y == 1) {
                    if (mark[a[x].S].F == -1) {
                        mark[a[x].S] = {x, 2};
                        break;
                    }
                    else {
                        int xx = mark[a[x].S].F;
                        y = mark[a[x].S].S;
                        mark[a[x].S] = {x, 2};
                        x = xx;
                    }
                }
                else {
                    if (mark[a[x].F].F == -1) {
                        mark[a[x].F] = {x, 1};
                        break;
                    }  
                    else {
                        int xx = mark[a[x].F].F;
                        y = mark[a[x].F].S;
                        mark[a[x].F] = {x, 1};
                        x = xx;
                    }
                }
                
                if (zz++ > 4 * n) {
                    cout << "rehash necessary\n";
                    return;
                }
            }
        }
    }
    cout << "successful hashing\n";
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
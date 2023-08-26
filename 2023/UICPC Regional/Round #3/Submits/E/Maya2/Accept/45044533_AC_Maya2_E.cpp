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

const int N = 1e4 + 9;
char ans[N];

void solve()
{
    string s;
    cin >> s;
    int n;
    n = sz(s);
    int sq = sqrt(n); debug(sq);
    for (int i = 0; i < n; i++) {
        ans[(i / sq) + ((sq - (i % sq) - 1) * sq)] = s[i];
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << nl;
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
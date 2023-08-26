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

int sq[10][10];

void solve()
{
    string s;
    int r1, c1, r2, c2;
    memset(sq, 0, sizeof sq);
    cout << "3 1 3 6" << endl;
    while (true) {
        cin >> s;
        if (s == "GAME") return;
        cin >> r1 >> c1 >> r2 >> c2;

        if (r1 == 1) cout << 4 << ' ';
        else if (r1 == 2) cout << 5 << ' ';
        else if (r1 == 4) cout << 1 << ' ';
        else cout << 2 << ' ';
        cout << c1 << ' ';
        if (r2 == 1) cout << 4 << ' ';
        else if (r2 == 2) cout << 5 << ' ';
        else if (r2 == 4) cout << 1 << ' ';
        else cout << 2 << ' ';
        cout << c2 << endl;
    }
}

int32_t main()
{
    //fastio();
    setlinebuf(stdout); 
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
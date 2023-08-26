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

const int N = 1e5 + 9;
int a[N];

void solve()
{
    string s;
    cin >> s;
    int n, m = sz(s);;
    cin >> n;
    char ch;
    cin >> ch;
    for (int i = 0; i < n; i++) cin >> a[i] >> ch;
    if (n == 0) cin >> ch;

    int nd = count(all(s), 'D');
    if (nd > n) {
        cout << "error\n";
        return;
    } 

    int st = 0, e = n - 1;
    bool f = true;

    for (int i = 0; i < m; i++) {
        if (s[i] == 'R') f = !f;
        else if (f) st++;
        else e--; 
    }

    cout << '[';
    if (f) {
        for (int i = st; i <= e; i++) {
            cout << a[i];
            if (i != e) cout << ',';
        }
    }
    else {
        for (int i = e; i >= st; i--) {
            cout << a[i];
            if (i != st) cout << ',';
        }
    }
    cout << "]\n";
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
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

string pat;

bool calc(string s) 
{
    debug(s);
    int n = s.size();
    int m = pat.size();
    string check = "";
    int j = 0;
    bool f = false;
    for (int i = 0; i < m; i++) {
        debug(check); debug(i);
        if (pat[i] == '*' && check != "") {
            int x = s.find(check, j); debug(x);
            if (x == 0) f = true;
            if (x == string::npos) {
                return false;
            }
            j = x + check.size();
            check = "";
        }
        else if (pat[i] != '*') check += pat[i];
    }
    if (pat[m - 1] != '*') {
        int x = s.find(check, j);
        if (x == string::npos) {
            return false;
        }
        j = x + check.size();
    }
    if (!f && pat[0] != '*') return false;
    if (pat[m - 1] != '*') {
        int x = s.find(check, n - check.size());
        if (x == string::npos) {
            return false;
        }
    }
    return true;
}

void solve()
{
    cin >> pat; debug(pat);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (calc(a)) cout << a << nl;
    }
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
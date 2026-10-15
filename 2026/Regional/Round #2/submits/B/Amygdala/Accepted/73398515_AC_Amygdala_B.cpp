#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
// #define endl '\n'

void solve()
{
    string s, t;
    cin >> s >> t;
    int ns = s.size(), nt = t.size();

    if(s == t) {cout << "0\n"; return;}

    if(ns > nt)
    {
        bool flag = true;
        for(int i=0; i<nt; i++) if(s[i] != t[i]) {flag = false; break;}
        if(flag) {cout << "1\n"; return;}

        flag = true;
        for(int i=1; i<=nt; i++) if(s[ns-i] != t[nt-i]) {flag = false; break;}
        if(flag) {cout << "1\n"; return;}
    }
    else if(nt > ns)
    {
        int a, b;

        a = 0;
        while(a<ns && s[a] == t[a]) a++;

        b = 1;
        while(b <= ns && s[ns-b] == t[nt-b]) b++;
        
        if(a + b >= ns + 1) {cout << "1\n"; return;}
    }

    cout << "2\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
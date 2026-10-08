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
#define endl '\n'

void solve()
{
    cint(n);
    string s, t;
    cin >> s >> t;

    string p;
    for(int i=0; i<(n+1)/2; i++)
    {
        vector<char> v = {s[i], s[n-i-1], t[i], t[n-i-1]};
        sort(v.begin(), v.end());
        p.push_back(v[1]);
    }

    int ss = p.size();
    // cout << p << endl;
    for(int i=((n&1) ? ss-2: ss-1); i>=0; i--)
    {
        p.push_back(p[i]);
    }

    cout << p << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
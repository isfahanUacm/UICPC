#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << endl
#define int ll
// #define endl '\n'

void solve()
{
    string s; cin >> s;
    if(s.size()%2 == 0) cout << ":)\n";
    else cout << s[s.size()/2] << '\n';
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
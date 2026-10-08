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
    int n, s;
    char w;
    cin >> n >> s >> w;

    if(w == 'L')
    {
        cout << (s+1)/2 << ' ' << (s+1)/2 << ' ' << n-s; 
    }
    else
    {
        cout << s-1 << ' ' << (n-s+1)/2 << ' ' << (n-s+1)/2; 
    }
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
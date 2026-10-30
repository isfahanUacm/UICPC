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

int is_up(int x, int y)
{
    if(x == y) return 0;

    if(x > y) return -1;
    else return 1;
}

void solve()
{
    int n; cin >> n;

    int up=0, down=0, on=0;
    for(int i=0; i<n; i++)
    {
        int x, y; cin >> x >> y;
        
        int res = is_up(x, y);
        if(res == 0) on ++;
        else if(res > 0) up++;
        else down++;
    }

    int ans = up * down + on * (n-on) + on*(on-1)/2;
    cout << ans << '\n';
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
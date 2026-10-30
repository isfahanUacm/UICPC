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
    int n, k, m; cin >> n >> m >> k;

    int val = k/n;
    int rem = k % n;

    if(k <= n) {cout << k << '\n'; return;}

    // cout << "n,m,k,val,rem = " << n << ',' << m << ',' << k << ',' << val << ',' << rem <<endl;

    if(val & 1)
    {
        if(val > m || (val==m && rem)) cout << 0;
        else if(val == m) cout << n;
        else if(val == m-1) cout << n-rem;
        else cout << n-rem + rem-(rem%2);
        cout << '\n';
    }
    else
    {
        if(val >= m) cout << 0;
        // else if(val == m-1) cout << rem;
        else cout << (n-rem) - ((n-rem)%2) + rem;
        cout << '\n';
    }
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
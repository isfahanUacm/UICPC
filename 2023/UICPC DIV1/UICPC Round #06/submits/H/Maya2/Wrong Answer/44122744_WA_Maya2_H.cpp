#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define vi vector<int>
#define si set<int>
#define pb push_back
#define pf push_front
#define MOD 1000000007
#define all(x) x.begin(), x.end()

void solve()
{
    ll q, m, s, l;
    cin >> q >> m >> s >> l;
    ll ans = ((l / m) * q);
    //cout << ans << '\n';
    if (l % m) ans += q;
    //cout << ans << '\n';
    if (s > ((m - (l % m)) * q)) {
        s -= ((m - (l % m)) * q);
        ans += (m / s);
        if (m % s) ans++;
    }
    cout << ans << '\n';
}

int main()
{
    solve();
    
    return 0;
}
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
    ll n, m, ans = 0;
    cin >> n >> m;
    if (n - 1 == m) ans = m * (m + 1) / 2;
    else if (n == 2 || n == 3) ans = n * (n - 1) / 2;
    else {
        int d = m - n + 1;
        n -= 3;
        ans += 3;
        int x = 3, y = 1;
        while (n) {
            // cout << x << ' ' << y << ' ' << d << ' ' << ans << '\n';
            if (d >= y) {
                x += y;
                d -= y;
                y++;
                ans += x;
                x++;
                n--;
            }
            else if (d != 0) {
                x += d;
                d = 0;
                y++;
                ans += x;
                x++;
                n--;
            }
            else {
                ans += ((x + n - 1) * (x + n) / 2) - ((x - 1) * (x) / 2);
                n = 0;
            }
        }
    } 
    cout << ans << '\n';
}

int main()
{
    solve();
    
    return 0;
}
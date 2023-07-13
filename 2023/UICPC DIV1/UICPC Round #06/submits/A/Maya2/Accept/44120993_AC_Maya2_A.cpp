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
    int n;
    cin >> n;
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ld a, b;
        cin >> a >> b;
        ans += a * b;
    }
    cout << fixed << setprecision(3) << ans << '\n';
}

int main()
{
    solve();
    
    return 0;
}
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

const int maxn = 2e5 + 10;
int arr[maxn];

void solve()
{
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < k; i++) cin >> arr[i];
    arr[k] = 2e9;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (*lower_bound(arr, arr + k, i) == 2e9) continue;
        ans += n - (*lower_bound(arr ,arr + k, i)) + 1;
        // cout << ans << '\n';
    }
    cout << ans << '\n';
}

int main()
{
    solve();
    
    return 0;
}
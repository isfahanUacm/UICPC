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
ll arr[maxn];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= i + 1) ans = max(ans, arr[i]);
    }
    cout << ans << '\n';
}

int main()
{
    solve();
    
    return 0;
}
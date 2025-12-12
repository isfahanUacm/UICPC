#include <bits/stdc++.h>

#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define int long long
#define pb push_back
#define MOD (int)1e9 + 7
using namespace std;

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ar(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1], dp[min(n, i + k)] + ar[i]);
    }
    cout << dp[0];
}
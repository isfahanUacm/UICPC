#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll r;
    cin >> r;
    vector<ll> arr(r + 10);
    for (ll i = 0; i < r + 10; i++)
    {
        arr[i] = i * i;
    }
    long double ans = 2e9;
    ll x, y;
    for (ll i = 0; i <= r; i++)
    {
        ll remain = r * r - i * i;
        ll curr = *upper_bound(arr.begin(), arr.end(), remain);
        long double dis = sqrt(i * i + curr);
        if (dis < ans)
        {
            x = i;
            y = sqrt(curr);
            ans = dis;
        }
    }
    cout << x << ' ' << y;

    return 0;
}
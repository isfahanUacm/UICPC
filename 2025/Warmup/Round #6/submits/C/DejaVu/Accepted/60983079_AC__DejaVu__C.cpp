#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> arr(100000);
    for (ll i = 1; i < 100000; i++)
    {
        arr[i] = i * i;
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        auto low = lower_bound(arr.begin(), arr.end(), l);
        auto high = upper_bound(arr.begin(), arr.end(), r);
        cout << high - low << endl;
    }

    return 0;
}
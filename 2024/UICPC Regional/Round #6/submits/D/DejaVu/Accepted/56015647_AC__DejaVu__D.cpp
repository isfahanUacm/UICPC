#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> sub(n + 1);
    sub[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        sub[i + 1] = arr[i] - sub[i];
    }
    ll min_e = *min_element(all(sub));
    ll first_range = -min_e;
    sub[0] = 1000000000;
    for (ll i = 0; i < n; i++)
    {
        sub[i + 1] = arr[i] - sub[i];
    }
    ll last_range = 1000000000 + *min_element(all(sub));
    ll temping = 0;
    cout << max(last_range - first_range + 1, temping);

    return 0;
}
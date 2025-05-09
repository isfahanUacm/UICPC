#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll c;
    cin >> c;
    ll m;
    cin >> m;
    ll arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        if (c % arr[i] == 0)
        {
            cout << min(arr[i], c / arr[i]) << " " << max(arr[i], c / arr[i]);
            break;
        }
    }

    return 0;
}
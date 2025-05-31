#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

ll find(ll n)
{
    ll tmp = sqrt(n) + 1;
    ll ans = 1;
    for (int i = 2; i <= tmp; i++)
    {
        if (n % i == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = find(n);
        if (ans == 1)
            cout << 1 << ' ' << n - 1 << endl;
        else
            cout << n / ans << ' ' << n / ans * (ans - 1) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll b;
    cin >> b;
    b--;
    for (ll i = 2; i <= log2(b); i++)
    {
        ll ans = 0;
        ll j = 2;
        while (true)
        {
            ans += ((ll)pow(j, i));
            if (ans == b)
            {
                cout << i + 1 << " " << j;
                return 0;
            }
            else if (ans > b)
                break;
            j++;
        }
    }
    cout << "impossible";

    return 0;
}
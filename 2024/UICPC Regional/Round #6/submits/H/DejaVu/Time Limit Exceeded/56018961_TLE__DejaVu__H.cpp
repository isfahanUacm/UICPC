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

    for (ll i = 2; i <= log2(b); i++)
    {
        ll ans = 0;
        ll j = 1;
        if (i == 2)
        {
            ll l = 1, r = sqrt(b) + 1, ans = 100000;
            while(l <= r) {
                ll m = (l + r) / 2;
                ll val = m * (m + 1) * (2 * m + 1) / 6;
                if(val >= b) {
                    ans = min(ans, m);
                    r = m - 1;
                }
                else 
                    l = m + 1;
            }
            if(ans * (ans + 1) * (2 * ans + 1) / 6 == b) {
                cout << i + 1 << ' ' << ans << endl;
                return 0;
            }
        }
        else if (i == 3)
        {
            ll l = 1, r = sqrt(b) + 1, ans = 100000;
            while(l <= r) {
                ll m = (l + r) / 2;
                ll val = (m * (m + 1) / 2) * (m * (m + 1) / 2);
                if(val >= b) {
                    ans = min(ans, m);
                    r = m - 1;
                }
                else 
                    l = m + 1;
            }

            if((ans * (ans + 1) / 2) * (ans * (ans + 1) / 2) == b) {
                cout << i + 1 << ' ' << ans << endl;
                return 0;
            }
        }
        else
        {
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
    }
    cout << "impossible";

    return 0;
}
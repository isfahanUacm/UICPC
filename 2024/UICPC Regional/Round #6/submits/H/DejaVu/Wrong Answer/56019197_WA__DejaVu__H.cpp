#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

template <typename T>
T power(T a, int64_t b) {
    assert(b >= 0);
    T res{1};
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll b;
    cin >> b;
    
    if(b == 1) {
        cout << 3 << ' ' << 1 << endl;
        return 0;
    }

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
                if(val >= b or val <= 0) {
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
                if(val >= b or val <= 0) {
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
                ans += power(j, i);
                if (ans == b)
                {
                    cout << i + 1 << " " << j;
                    return 0;
                }
                else if (ans > b or ans <= 0)
                    break;
                j++;
            }
        }
    }
    cout << "impossible";

    return 0;
}

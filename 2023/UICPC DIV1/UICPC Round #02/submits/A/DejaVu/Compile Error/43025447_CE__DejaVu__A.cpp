#include <bits/stdc++.h>
using namespace std;

const ll mod = 1e9 + 7;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio;
    int n, T;
    cin >> n >> T;

    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        sum += t;
        cnt += 1;

        if (sum > T)
        {
            cnt--;
            break;
        }
    }

    cout << cnt;

    return 0;
}

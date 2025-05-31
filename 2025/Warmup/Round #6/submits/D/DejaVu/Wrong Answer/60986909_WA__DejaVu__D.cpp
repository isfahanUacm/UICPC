#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ":" << x << "\n"
#define deb2(x) cout << ":" << x << "\n"
#define in(x) cin >> x
#define pb push_back
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define f first
#define s second
#define ll int64_t
#define per(i, a, b) for (ll i = a; i <= b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";
const ll maxn = 1e5 + 15;
const ll mod = 1e9 + 7;
const ll lg = 22;

ll getAnswer(ll n, ll k)
{
    ll ans = 0;
    while (n > 0)
    {
        if (n % k == 0)
        {
            ans++;
            n /= k;
        }
        else
        {
            ll d = n / k;
            ll last = d * k;
            ans += n - last;
            n = last;
        }
    }
    return ans;
}

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll r, k;
        cin >> r >> k;

        vector<ll> pow;
        pow.push_back(1);
        ll i = 1;

        while (pow[i - 1] * k <= r)
        {
            pow.push_back(pow[i - 1] * k);
            i++;

            if (pow[i - 1] * k < pow[i - 1])
                break;
        }

        ll lastPow = pow[pow.size() - 1];
        ll lastMul = (r / k) * k;
        ll ans = 0;
        ll ans1 = getAnswer(r, k);
        ll ans2 = getAnswer(lastPow - 1, k);
        ll ans3 = getAnswer(lastMul - 1, k);
        cout << max(ans1, max(ans2, ans3)) << endl;
    }

    return 0;
}
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
const ll maxn = 1e6 + 15;
const ll mod = 1e9 + 7;
const ll lg = 22;

signed main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll r, k;
        cin >> r >> k;
        ll d = r / k;
        ll last = d * k;

        ll ans1 = 0;
        ll n1 = r;
        while (n1 > 0)
        {
            if (n1 % k == 0)
            {
                n1 /= k;
                ans1 += 1;
            }
            else
            {
                ll d1 = n1 / k;
                ll last1 = d1 * k;
                ans1 += n1 - last1;
                n1 = last1;
            }
        }
        ll ans2 = 0;
        ll n2 = last - 1;
        while (n2 > 0)
        {
            if (n2 % k == 0)
            {
                n2 /= k;
                ans2 += 1;
            }
            else
            {
                ll d2 = n2 / k;
                ll last2 = d2 * k;
                ans2 += n2 - last2;
                n2 = last2;
            }
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
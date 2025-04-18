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
#define ll long long
#define per(i, a, b) for (ll i = a; i <= b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";
const ll maxn = 2e6 + 1;
const ll mod = 1e9 + 7;
const ll lg = 22;

vector<ll> a;
ll n, m, k;
signed main()
{

    cin >> n >> m >> k;
    per(i, 1, n)
    {
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    ll tmp = 0;
    ll groups = 0;
    while (tmp < n)
    {
        ll j = tmp;
        while (j <= min(n - 1, tmp + k - 1) && a[j] - a[tmp] <= m)
        {
            j++;
        }
        tmp = j;
        groups++;
    }
    cout << groups << '\n';

    return 0;
}
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
#define ll int
#define per(i, a, b) for (ll i = a; i <= b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";
const ll maxn = 1e5 + 1;
const ll maxai = 1e6 + 1;
const ll mod = 1e9 + 7;
const ll lg = 22;

void solve()
{
    ll n, a[maxn];
    ll pos[maxai];
    per(i, 0, maxn - 1)
    {
        pos[i] = -1;
    }
    a[0] = 0;
    pos[0] = 0;
    a[1] = 1;
    pos[1] = 1;
    ll i = 2;
    while (a[i - 1] + a[i - 2] <= maxai)
    {
        a[i] = a[i - 1] + a[i - 2];
        pos[a[i]] = i;
        i++;
    }

    vector<pii> ans;
    cin >> n;
    vector<ll> ones;
    per(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            ones.pb(i);
        if (pos[a[i]] != -1)
        {
            ans.pb({a[i], i});
        }
    }

    if (ones.size() > 1)
    {
        cout << ones[1] << " " << ones[0] << endl;
        return;
    }
    sort(ans.begin(), ans.end());

    if (ans.size() < 2)
    {
        outl("impossible");
        return;
    }

    per(j, 0, ans.size() - 2)
    {
        if (pos[ans[j + 1].f] - pos[ans[j].f] == 1 /*&& ans[j + 1].s > ans[j].s*/)
        {
            cout << ans[j].s << " " << ans[j + 1].s << endl;
            return;
        }
    }

    outl("impossible");
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
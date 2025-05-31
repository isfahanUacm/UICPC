#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, a) for (int i = 0; i < (a); i++)
#define in(a, n) FOR(i, n) cin >> a[i];
#define out(a, n) FOR(i, n) cout << a[i] << " ";
#define X first
#define Y second
#define MAX 100000

const int INF = 1e7 + 7;

// ll a[MAX];
// vll a(MAX);

void solve()
{
    ll r, k;
    cin >> r >> k;
    ll n = r;
    ll ans1 = 0;

    while (n > 0)
    {
        ans1++;
        if (n % k == 0)
        {
            n /= k;
        }
        else
        {
            n--;
        }
    }
    n = r;

    while ((n % k) != (k - 1))
    {
        n--;
    }
    ll ans2 = 0;

    while (n > 0)
    {
        ans2++;
        if (n % k == 0)
        {
            n /= k;
        }
        else
        {
            n--;
        }
    }

    cout << max(ans1, ans2) << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

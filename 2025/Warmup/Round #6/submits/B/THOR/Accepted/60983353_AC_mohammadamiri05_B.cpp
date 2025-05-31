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
    ll n;

    cin >> n;
    ll ans = -1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = i;
            break;
        }
    }

    if (ans == -1)
    {
        cout << 1 << " " << n - 1 << "\n";
    }
    else
    {
        cout << n / ans << " " << n * (ans - 1) / ans << "\n";
    }
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

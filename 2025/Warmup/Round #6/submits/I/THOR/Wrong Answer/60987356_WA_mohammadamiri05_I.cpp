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
#define MAX 100010

const int INF = 1e7 + 7;

ll a[MAX];
ll p = 0;
ll prime[MAX];
// vll a(MAX);

void solve()
{
    int n;
    cin >> n;
    in(a, n);
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = lcm(ans, a[i]);
    }
    ll sum = 0;
    for (int i = 0; i < p; i++)
    {
        while (ans % prime[i] == 0)
        {
            ans /= prime[i];
            sum++;
        }
    }

    if (sum % 2 == 0)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 2; i < MAX; i++)
    {
        int div = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                div++;
            }
        }
        if (div == 0)
        {
            prime[p] = i;
            p++;
        }
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << prime[i] << " ";
    // }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

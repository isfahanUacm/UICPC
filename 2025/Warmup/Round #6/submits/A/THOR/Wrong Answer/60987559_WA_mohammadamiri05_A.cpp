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
#define MAX 1010

const int INF = 1e7 + 7;

// vll a(MAX);

void solve()
{
    ll n, m, h;
    cin >> n >> m >> h;

    ll a[n + 1][m + 1];
    ll ps[n + 1][m + 1];
    pii ans[n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
        sort(a[i], a[i] + m);
    }

    for (int i = 0; i < n; i++)
    {
        ps[i][0] = a[i][0];
        for (int j = 1; j < m; j++)
        {
            ps[i][j] = ps[i][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans[i].first = m;
        ans[i].second = 0;
        ll sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += ps[i][j];
            if (ps[i][j] > h)
            {
                ans[i].first = j;
                ans[i].second = -(sum - ps[i][j]);
                break;
            }
        }
        if (ans[i].first == m)
        {
            ans[i].second = -sum;
        }
    }

    int answer = n;
    sort(ans + 1, ans + n, greater<>());

    for (int i = 0; i < n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    for (int i = 1; i < n; i++)
    {
        if (ans[0].first == ans[i].first)
        {
            if (ans[0].second >= ans[i].second)
            {
                answer = i;
                break;
            }
        }
        else if (ans[0].first > ans[i].first)
        {
            answer = i;
            break;
        }
    }

    cout << answer << "\n";
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

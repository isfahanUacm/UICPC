#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
using pll = pair<long long, long long>;
using ull = unsigned long long;
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define MP make_pair
#define pb push_back
#define pf push_front
#define set_dec(x) cout << fixed << setprecision(x);
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main()
{
    fast int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m;
        cin >> n >> m;
        int ans[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = 2;
            }
        }
        if (n == 1 && m == 1)
        {
            cout << "YES" << endl;
            cout << 1 << endl;
            continue;
        }
        int counter = 0;
        for (int k = n * m; k >= 3; k--)
        {
            int pnt = n * m - k + 2;
            for (int i = n * m; i >= 2 * k; i--)
            {
                if (i % k == 0)
                {
                    pnt -= n * m - i + 2;
                }
                if (pnt <= 0)
                {
                    i = 0;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int x = k / gcd(ans[i][j], k);
                    if (ans[i][j] * x <= 1e9)
                    {
                        ans[i][j] *= x;
                        pnt--;
                    }
                    if (pnt <= 0)
                    {
                        i = n, j = m;
                    }
                }
            }
            if (pnt <= 0)
                counter++;
        }
        if (counter == n * m - 2)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << ans[i][j] << ' ';
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
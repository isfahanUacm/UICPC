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
#define MOD ((ll)1e9 + 7)
#define set_dec(x) cout << fixed << setprecision(x);
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int MAXN = 2e5 + 5;
int a[MAXN];
int main()
{
    fast int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            a[b]++;
        }
        bool fl = 0;
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= 2)
                fl |= 1;
            if (a[i])
                s += 1;
        }
        if (!(s % 2) || fl)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        for (int i = 1; i <= n; i++)
            a[i] = 0;
    }
}
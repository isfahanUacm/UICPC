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
int main()
{
    fast int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        ll s = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int a;
            cin >> a;
            s += a;
        }
        cout << -1 * s << endl;
    }
}
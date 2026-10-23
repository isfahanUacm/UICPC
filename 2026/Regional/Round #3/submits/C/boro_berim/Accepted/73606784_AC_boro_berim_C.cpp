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
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(all(a));
        int mx = 1;
        int cs = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1)
            {
                cs++;
            }
            else
            {
                cs = 1;
            }
            mx = max(mx, cs);
        }
        cout << n - mx<< endl;
    }
}

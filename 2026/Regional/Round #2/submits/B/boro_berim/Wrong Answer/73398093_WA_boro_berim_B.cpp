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
        string s, t;
        cin >> s >> t;
        if (s == t)
            cout << 0 << endl;
        else
        {
            int n = s.size();
            int m = t.size();
            int i = 0;
            int l1 = 0, l2 = 0;
            while (i < n && i < m && s[i] == t[i])
            {
                l1++;
                i++;
            }
            i = 0;
            reverse(all(s));
            reverse(all(t));
            while (i < n && i < m && s[i] == t[i])
            {
                l2++;
                i++;
            }
            if (l2 + l1 >= n || l1 + l2 >= m)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
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
const int MAXN = 1e6 + 5;
int a[MAXN], mrk[MAXN], prim[MAXN], ans[MAXN], num[MAXN];

ll pw(ll pa, ll pd)
{
    if (pd == 0)
        return 1;
    ll pc = pw(pa, pd / 2);
    pc = (pc * pc);
    if (pd % 2)
        pc = (pc * pa);
    return pc;
}

void prep()
{
    for (int i = 1; i < MAXN; i++)
    {
        mrk[i] = 1;
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (prim[i])
        {
            continue;
        }
        for (int j = i; j < MAXN; j += i)
        {
            if (j != i)
                prim[j] = 1, num[j]++;
            if (num[j] >= 2)
            {
                mrk[j] = 0;
                continue;
            }
            int res = i, pnt = 0;
            for (int k = 0; k < 20; k++)
            {
                if (j % res != 0)
                    break;
                else
                    pnt = k;
                if (res * res > MAXN)
                    break;
                res *= res;
                // cout << k << res << endl;
            }
            if (j % pw(i, (1 << pnt)) == 0 && j % pw(i, (1 << pnt) + 1) == 0)
            {
                mrk[j] = 0;
            }
        }
    }
    ans[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (mrk[i] != 1)
        {
            ans[i] = ans[i - 1];
        }
        else
        {
            ans[i] = ans[i - 1] + 1;
        }
    }
}
int32_t main()
{
    fast int tt;

    prep();
    cin >> tt;
    while (tt--)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
}
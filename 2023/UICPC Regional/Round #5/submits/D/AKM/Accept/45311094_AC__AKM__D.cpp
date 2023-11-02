#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;
#define nl "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ll modOp(ll a, ll b, int op)
{
    switch (op)
    {
    case 0:
        return ((a % MOD) + (b % MOD)) % MOD;
    case 1:
        return ((a % MOD) - (b % MOD) + MOD) % MOD;
    case 2:
        return (a % MOD) * (b % MOD) % MOD;
    }
}
bool compareInterval(tuple<double, double, double, double> i1, tuple<double, double, double, double> i2)
{
    return (get<3>(i1) < get<3>(i2));
}

double res(double h, double r)
{
    return M_PI * (h * h) * (3.0 * r - h) / 3.0;
}

void solve()
{
    int n, s;
    cin >> n >> s;

    double st = 1e6;

    vector<tuple<double, double, double, double>> a(n);
    vector<double> sa(n);
    for (int i = 0; i < n; i++)
    {
        double r, x, y, z;
        cin >> r >> x >> y >> z;
        r /= 1000;
        x /= 1000;
        y /= 1000;
        z /= 1000;
        a[i] = make_tuple(r, x, y, z);
    }

    if (n == 0)
    {
        for (int i = 0; i < s; i++)
            cout << fixed << showpoint << setprecision(8) << 100.0 / s << endl;

        return;
    }
    sort(all(a));

    for (int i = 0; i < n; i++)
    {
        sa[i] = 4.0 / 3.0 * M_PI * get<0>(a[i]) * get<0>(a[i]) * get<0>(a[i]);
        st -= sa[i];
    }

    double sEach = 1.0 * st / s;

    double z = 0;
    for (int k = 0; k < s; k++)
    {
        double start = z;
        double l = z, r = 100;
        bool flag = true;
        while (l <= r)
        {
            double mid = (1.0 * l + r) / 2.0;

            double dec = 0;

            for (int i = 0; i < n; i++)
            {
                double st = get<3>(a[i]) - get<0>(a[i]);
                double et = get<3>(a[i]) + get<0>(a[i]);

                if (et <= start)
                    continue;
                if (st >= mid)
                    continue;

                if (st >= start && et <= mid)
                {
                    dec += sa[i];
                }
                else if (st <= start && et >= mid)
                {
                    double h1 = et - mid;
                    double h2 = start - st;

                    double tmp = sa[i];
                    tmp -= res(h1, get<0>(a[i]));
                    tmp -= res(h2, get<0>(a[i]));

                    dec += tmp;
                }
                else if (st <= mid && et >= mid)
                {
                    double h = mid - st;
                    dec += res(h, get<0>(a[i]));
                }
                else if (st <= start && et >= start)
                {
                    double h = et - start;
                    dec += res(h, get<0>(a[i]));
                }
            }

            double tmpS = 100 * 100 * (mid - start) - dec;

            if (abs(tmpS - sEach) < pow(10, -7))
            {
                z = mid;
                flag = false;
                break;
            }
            else if (tmpS - sEach <= -1 * pow(10, -7))
            {
                l = mid + pow(10, -9);
            }
            else if (tmpS - sEach >= pow(10, -7))
            {
                r = mid - pow(10, -9);
            }
        }
        if (flag)
            z = l;

        cout << fixed << showpoint << setprecision(8) << z - start << endl;
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}

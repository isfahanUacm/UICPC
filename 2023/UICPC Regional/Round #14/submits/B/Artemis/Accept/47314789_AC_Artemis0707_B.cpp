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

void solve()
{
    map<char, int> s, h;
    for (int i = 'A'; i <= 'H'; i++)
    {
        s[char(i)] = 'H' + 1 - i;
        h['H' + 1 - i] = char(i);
    }

    char c1, c2;
    int x1, x2;
    cin >> c1 >> x1 >> c2 >> x2;

    int b11, b12, b21, b22;
    b11 = x1 - s[c1];
    b12 = x1 + s[c1];
    b21 = x2 - s[c2];
    b22 = x2 + s[c2];
    if ((s[c1] + x1) % 2 != (s[c2] + x2) % 2)
        cout << "Impossible";
    else if (x1 == x2 && c1 == c2)
        cout << 0 << ' ' << c1 << ' ' << x1;
    else if (abs(s[c1] - s[c2]) == abs(x1 - x2))
        cout << 1 << ' ' << c1 << ' ' << x1 << ' ' << c2 << ' ' << x2;
    else
    {
        int u = (b22 - b11) / 2;
        int v = (b12 - b21) / 2;

        int yu = u + b11;
        int yv = v + b21;

        if (((u < 1 || u > 8) || (yu < 1 || yu > 8)) && ((v < 1 || v > 8) || (yv < 1 || yv > 8)))
            cout << "Impossible";
        else if ((u < 1 || u > 8) || (yu < 1 || yu > 8))
        {
            int y = v + b21;
            char t = h[v];
            cout << 2 << ' ' << c1 << ' ' << x1 << ' ' << t << ' ' << y << ' ' << c2 << ' ' << x2;
        }
        else
        {
            int y = u + b11;
            char t = h[u];
            cout << 2 << ' ' << c1 << ' ' << x1 << ' ' << t << ' ' << y << ' ' << c2 << ' ' << x2;
        }
    }

    cout << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

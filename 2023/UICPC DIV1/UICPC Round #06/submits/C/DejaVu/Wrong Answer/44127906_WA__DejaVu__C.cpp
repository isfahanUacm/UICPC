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

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    fastio;

    ll xB, yB, x1, y1, x2, y2;
    cin >> xB >> yB >> x1 >> y1 >> x2 >> y2;

    ll gcdA = __gcd(xB, yB);
    ll firstX = xB / gcdA;
    ll firstY = yB / gcdA;

    if (x1 <= firstX && y1 <= firstY && x2 >= firstX && y2 >= firstY)
    {
        ll tmp = y2 / firstY;
        if (x2 / firstX < tmp)
            tmp = x2 / firstX;
        tmp++;

        if (tmp * firstX < xB)
        {
            cout << "No\n";
            cout << tmp * firstX << " " << tmp * firstY;
        }
        else
            cout << "Yes";
    }
    else
    {
        cout << "No\n";
        cout << firstX << " " << firstY;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;
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

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio;
    int n;
    cin >> n;

    int R = 0, C = 0, RA = 0, RB = 0, RC = 0, CA = 0, CB = 0, CC = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'N')
        {
            C++;
            CA = CA + (s[1] == 'Y');
            CB = CB + (s[2] == 'Y');
            CC = CC + (s[3] == 'Y');
        }
        else
        {
            R++;
            RA = RA + (s[1] == 'Y');
            RB = RB + (s[2] == 'Y');
            RC = RC + (s[3] == 'Y');
        }
    }

    double b1 = 1.0 * RA / R * 100;
    double b2 = 1.0 * RB / R * 100;
    double b3 = 1.0 * RC / R * 100;
    double a1 = 1.0 * CA / C * 100;
    double a2 = 1.0 * CB / C * 100;
    double a3 = 1.0 * CC / C * 100;

    if ((a1 - b1) / a1 <= 0)
        cout << "Not Effective";

    else
        cout << fixed << showpoint << setprecision(6) << (a1 - b1) / a1 * 100;

    cout << '\n';

    if ((a2 - b2) / a2 <= 0)
        cout << "Not Effective";

    else
        cout << fixed << showpoint << setprecision(6) << (a2 - b2) / a2 * 100;

    cout << '\n';
    if ((a3 - b3) / a3 <= 0)
        cout << "Not Effective";

    else
        cout << fixed << showpoint << setprecision(6) << (a3 - b3) / a3 * 100;

    return 0;
}

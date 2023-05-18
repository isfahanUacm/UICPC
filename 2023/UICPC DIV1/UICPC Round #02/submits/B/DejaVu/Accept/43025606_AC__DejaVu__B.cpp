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

    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        int pss = stoi(s2.substr(0, 4));
        int born = stoi(s3.substr(0, 4));
        int sem = stoi(s4);

        if (pss >= 2010 || born >= 1991)
        {
            cout << s1 << " eligible";
        }
        else if (sem > 40)
        {
            cout << s1 << " ineligible";
        }
        else
        {
            cout << s1 << " coach petitions";
        }

        cout << "\n";
    }

    return 0;
}

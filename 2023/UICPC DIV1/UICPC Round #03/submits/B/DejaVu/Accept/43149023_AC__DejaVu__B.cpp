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

double convertFtoB(string s)
{
    double aim = 0.0;
    for (int i = 2; i < s.size(); i++)
    {
        if (s[i] == '1')
            aim += pow(2, -1 * (i - 1));
    }
    return aim;
}

double aim;
string fi;
double Pa;

void solve(int i, int N, double l, double r, string p)
{
    if (i == N)
    {
        if (l == aim)
            fi = p;
        return;
    }

    solve(i + 1, N, l, l + (r - l) * Pa, p + "A");
    solve(i + 1, N, l + (r - l) * Pa, r, p + "B");
}

int main()
{
    fastio;
    int N, D;
    cin >> N >> D;

    string s;
    cin >> s;

    Pa = D * 1.0 / 8.0;
    aim = convertFtoB(s);
    
    solve(0, N, 0.0, 1.0, "");

    cout << fi;

    return 0;
}

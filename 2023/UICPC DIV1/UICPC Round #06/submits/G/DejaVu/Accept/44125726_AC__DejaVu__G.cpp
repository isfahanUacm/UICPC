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

int main()
{
    fastio;
    ll n, k;
    cin >> n >> k;

    vector<ll> house(k + 2);

    house[0] = 0;
    for (int i = 1; i < k + 1; i++)
        cin >> house[i];
    house[k + 1] = n + 1;

    ll res = 0;
    for (int i = 1; i < k + 2; i++)
    {
        res += (house[i] - house[i - 1] - 1) * (house[i] - house[i - 1]) / 2;
    }

    cout << (n * (n + 1) / 2) - res;

    return 0;
}

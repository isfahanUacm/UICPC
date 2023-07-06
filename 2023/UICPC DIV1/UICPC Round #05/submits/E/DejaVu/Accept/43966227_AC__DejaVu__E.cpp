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
    vector<int> p;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int num = i * pow(10, 5) + i + j * pow(10, 4) + j * pow(10, 1) + k * pow(10, 3) + k * pow(10, 2);
                p.push_back(num);
            }
        }
    }

    sort(all(p));

    fastio;
    int n;
    cin >> n;

    while (n--)
    {
        int b;
        cin >> b;
        int l = lower_bound(all(p), b) - p.begin();

        if (b == 100000)
            cout << b + 1;
        else if (p[l] == b)
            cout << b;
        else
        {
            int t = p[l];
            int u = p[l - 1];

            if (abs(b - t) >= abs(b - u))
                cout << u;
            else
                cout << t;
        }

        cout << '\n';
    }

    return 0;
}

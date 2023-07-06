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
    int n;
    cin >> n;

    vector<pii> a;
    for (int i = 0; i < pow(2, n); i++)
    {
        int t;
        cin >> t;
        a.push_back(mp(t, 1));
    }

    sort(all(a));
    int cnt = pow(2, n + 1) - 1;

    for (int i = 0; i < n; i++)
    {
        vector<pii> temp;
        for (int j = 0; j < a.size() - 1; j += 2)
        {
            if (a[j].first == -1 || a[j + 1].first == -1)
            {
                continue;
            }
            else if (a[j].first == a[j + 1].first)
            {
                temp.push_back(mp(a[j].first, i + 1));
                cnt -= 2;
            }
            else
            {
                temp.push_back(mp(-1, -1));
            }
        }

        a = temp;
    }

    cout << cnt;
    return 0;
}

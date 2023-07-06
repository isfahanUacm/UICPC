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

vector<int> res;

void f(vector<int> a)
{
    if (a.size() == 1)
    {
        res.push_back(a[0]);
        return;
    }

    vector<int> t1, t2;
    t1.clear();
    t2.clear();
    for (int i = 0; i < a.size(); i += 2)
        t1.push_back(a[i]);
    for (int i = 1; i < a.size(); i += 2)
        t2.push_back(a[i]);

    f(t1);
    f(t2);

    return;
}

int main()
{
    fastio;

    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < pow(2, n); i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }

    f(a);

    a = res;
    int cnt = pow(2, n + 1) - 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < a.size(); j += 2)
        {
            if (a[j] == -1 || a[j + 1] == -1)
            {
                temp.push_back(-1);
            }
            else if (a[j] == a[j + 1])
            {
                temp.push_back(a[j]);
                cnt -= 2;
            }
            else
            {
                temp.push_back(-1);
            }
        }

        a = temp;
    }

    cout << cnt;
    return 0;
}

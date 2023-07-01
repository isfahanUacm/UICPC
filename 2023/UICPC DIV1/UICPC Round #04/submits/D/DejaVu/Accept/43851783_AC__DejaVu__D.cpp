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

int orientation(pii p, pii q, pii r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int main()
{
    vector<int> ans;

    int n;
    cin >> n;
    vector<pii> a;

    int left = -1;
    int lVal = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(mp(x, y));
        if (x < lVal)
        {
            left = i;
            lVal = x;
        }
    }

    int s = left, r = -1;
    do
    {
        ans.push_back(s);
        r = (s + 1) % n; // :))))))))))
        for (int i = 0; i < n; i++)
            if (orientation(a[s], a[i], a[r]) == 2)
                r = i;

        s = r;

    } while (s != left);

    ll mx = INT_MIN;
    for (int i = 0; i < ans.size(); i++)
        for (int j = i + 1; j < ans.size(); j++)
            mx = (pow(a[ans[j]].second - a[ans[i]].second, 2) + pow(a[ans[j]].first - a[ans[i]].first, 2) > mx) ? pow(a[ans[j]].second - a[ans[i]].second, 2) + pow(a[ans[j]].first - a[ans[i]].first, 2) : mx;

    cout << fixed << showpoint << setprecision(8) << sqrt(mx);
    return 0;
}

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
    int n;
    cin >> n;

    vector<int> s1(n), s2(n);
    for (int i = 0; i < n; i++)
        cin >> s1[i];
    for (int i = 0; i < n; i++)
        cin >> s2[i];

    unordered_set<int> rem1, rem2, tot1, tot2;

    string res = "";
    for (int i = 0; i < n; i++)
    {
        res.push_back(('0' + s2[i]));
        res.push_back(' ');

        tot1.insert(s1[i]);
        tot2.insert(s2[i]);

        if (tot1.find(s2[i]) == tot1.end())
            rem1.insert(s2[i]);
        if (tot2.find(s1[i]) == tot2.end())
            rem2.insert(s1[i]);

        if (rem1.find(s1[i]) != rem1.end())
            rem1.erase(s1[i]);
            
        if (rem2.find(s2[i]) != rem2.end())
            rem2.erase(s2[i]);

        if (rem1.empty() && rem2.empty())
        {
            tot1.clear();
            tot2.clear();
            res.push_back('#');
            res.push_back(' ');
        }
    }

    res.pop_back();
    res.pop_back();

    cout << res;
    return 0;
}

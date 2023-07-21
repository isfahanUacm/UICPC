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

    vector<ll> s1(n), s2(n);
    for (int i = 0; i < n; i++)
        cin >> s1[i];
    for (int i = 0; i < n; i++)
        cin >> s2[i];

    unordered_map<ll, ll> s;

    string res = "";
    ll dif = 0;
    for (int i = 0; i < n; i++)
    {
        res.push_back(('0' + s2[i]));
        res.push_back(' ');

        if (s[s1[i]] == 0)
            dif++;
        s[s1[i]] += 1;
        if (s[s1[i]] == 0)
            dif--;

        if (s[s2[i]] == 0)
            dif++;
        s[s2[i]] -= 1;
        if (s[s2[i]] == 0)
            dif--;

        if (dif == 0 && i != n - 1)
            res.push_back('#'), res.push_back(' ');
    }

    while (res.back() == ' ' || res.back() == '#')
        res.pop_back();

    cout << res;
    return 0;
}
